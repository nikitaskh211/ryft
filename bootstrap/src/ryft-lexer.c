/* Standard C includes */
#include <stdlib.h>

/* Ryft includes */
#include "../include/ryft-lexer.h"

/* Helper function that determines whether character is a letter */
static int ryft_is_letter(const char c) {
  /* Main nested else-if */
  if ('A' <= c && c <= 'Z') {
    /* This would be an uppercase letter character */
    return 1;
  } else if ('a' <= c && c <= 'z') {
    /* This would be a lowercase letter character */
    return 2;
  } else {
    /* This would not be a letter character */
    return 0;
  }
}

/* Helper function that determines whether character is a digit */
static int ryft_is_digit(const char c) {
  /* Main nested else-if */
  if ('0' <= c && c <= '9') {
    /* This would be a digit character */
    return 1;
  } else {
    /* This would not be a digit character */
    return 0;
  }
}

/* Helper function that calculates the jump to the next token */
static size_t ryft_lexer_token_length(const char *cursor) {
  /* The token length accumulator */
  size_t length = (size_t)0;
  /* Main nested else-if */
  if (cursor[length] == '\0') {
    /* This would be considered the end of file, which itself requires only one
     * token, hence why it only increments once */
    length++;
  } else if (cursor[length] == '_' || ryft_is_letter(cursor[length])) {
    /* Anything starting from a letter or an underscoore and without any special
     * character is to be considered a unique identifier */
    length++;
    while (cursor[length] == '_' || ryft_is_letter(cursor[length]) ||
           ryft_is_digit(cursor[length])) {
      length++;
    }
  } else if (ryft_is_digit(cursor[length])) {
    /* Anything starting from a digit, optionally containing a dot, an
     * underscoore or a letter is to be considered a number literal */
    length++;
    while (ryft_is_digit(cursor[length]) || ryft_is_letter(cursor[length]) ||
           cursor[length] == '.' || cursor[length] == '_' ||
           (cursor[length - 1] == 'e' || cursor[length - 1] == 'E') &&
               (cursor[length] == '+' || cursor[length] == '-')) {
      length++;
    }
  } else if (cursor[length] == '\'') {
    /* Anything starting from the single quote is to be considered a character
     * literal*/
    length++;
    while (cursor[length] != '\'' && cursor[length] != '\0') {
      if (cursor[length] == '\\' && cursor[length + 1] != '\0') {
        length++;
      }
      length++;
    }
    if (cursor[length] == '\'') {
      length++;
    }
  } else if (cursor[length] == '\"') {
    /* Anything starting from the double quote is to be considered a string
     * literal */
    length++;
    while (cursor[length] != '\"' && cursor[length] != '\0') {
      if (cursor[length] == '\\' && cursor[length + 1] != '\0') {
        length++;
      }
      length++;
    }
    if (cursor[length] == '\"') {
      length++;
    }
  } else {
    /* Anything else will be considered a single token */
    length++;
  }
  /* Returning the result */
  return length;
}

/* A function that counts the amount of tokens within a string of characters and
 * returns the count */
size_t ryft_lexer_count_tokens(const char *file_contents) {
  /* The token amount accumulator */
  size_t token_amount = (size_t)0;
  /* A cursor pointer that copies initial position of file_contents */
  const char *cursor = file_contents;
  /* Main reading cycle */
  while (*cursor) {
    /* If we read a whitespace pass */
    if (*cursor == ' ' || *cursor == '\t' || *cursor == '\n') {
      cursor++;
      continue;
    }
    /* Whether we see a possible token shift the cursor position to the next
     * possible token */
    cursor += ryft_lexer_token_length(cursor);
    /* Incrementing the accumulator counter */
    token_amount++;
  }
  /* Returning the result */
  return token_amount;
}

/* A function that lexicographically compares C strings */
static int ryft_c_str_cmp(const char *cstr1, const char *cstr2) {
  while (*cstr1 && (*cstr1 == *cstr2)) {
    cstr1++;
    cstr2++;
  }
  return (int)((unsigned char)*cstr1 - (unsigned char)*cstr2);
}

/* A function that lexicographically compares C strings up to 'n' characters */
static int ryft_c_str_n_cmp(size_t n, const char *cstr1, const char *cstr2) {
  for (size_t i = 0; i < n; i++) {
    unsigned char c1 = (unsigned char)*cstr1;
    unsigned char c2 = (unsigned char)*cstr2;
    if (c1 != c2) {
      return (int)(c1 - c2);
    }
    if (c1 == '\0') {
      return 0;
    }
    cstr1++;
    cstr2++;
  }
  return 0;
}

/* A function that determines whether a character represents a binary value*/
static int ryft_is_binary(const char c) {
  /* Main nested else-if */
  if (c == '0' || c == '1') {
    /* This would be appropriate for a binary value */
    return 1;
  } else {
    /* This would be inappropriate for a binary value */
    return 0;
  }
}

/* A function that determines whether a character represents an octal value */
static int ryft_is_octal(const char c) {
  /* Main nested else-if */
  if ('0' <= c && c <= '7') {
    /* This would be appropriate for an octal value */
    return 1;
  } else {
    /* This would be inappropriate for an octal value */
    return 0;
  }
}

/* A function that determines whether a character represents a hexadecimal value
 */
static int ryft_is_hexadecimal(const char c) {
  /* Main nested else-if */
  if (('0' <= c && c <= '9') || ('a' <= c && c <= 'f')) {
    /* This would be appropriate for a hexadecimal value */
    return 1;
  } else if (('0' <= c && c <= '9') || ('A' <= c && c <= 'F')) {
    /* This would also be appropriate for a hexadecimal value */
    return 2;
  } else {
    /* This would be inappropriate for a hexadecimal value */
    return 0;
  }
}

/* A function that determines whether a literal is an integer */
static int ryft_is_int_literal(size_t lit_size, const char *lit_str) {
  /* Early return conditions */
  if (lit_size == 0 || lit_str == NULL) {
    return 0;
  }
  /* Declaring some variables for control flow */
  char lit_int_type = 'd', prev_was_digit = 'n';
  size_t i_begin = (size_t)0, i_suffix;
  int (*validator)(const char c) = ryft_is_digit;
  /* Main check for format */
  if (lit_size > 2 && lit_str[i_begin] == '0') {
    switch (lit_str[i_begin + 1]) {
    /* Binary value */
    case 'b':
    case 'B':
      lit_int_type = 'b';
      validator = ryft_is_binary;
      i_begin = (size_t)2;
      break;
    /* Octal value */
    case 'o':
    case 'O':
      lit_int_type = 'o';
      validator = ryft_is_octal;
      i_begin = (size_t)2;
      break;
    /* Hexadecimal value */
    case 'x':
    case 'X':
      lit_int_type = 'h';
      validator = ryft_is_hexadecimal;
      i_begin = (size_t)2;
      break;
    /* Default */
    default:
      if (ryft_is_digit(lit_str[i_begin + 1]) || lit_str[i_begin + 1] == '_') {
        lit_int_type = 'd';
        i_begin = (size_t)0;
      } else {
        return 0;
      }
      break;
    }
  }
  /* Main validation loop */
  size_t i;
  for (i = i_begin; i < lit_size; i++) {
    if (lit_str[i] == '_') {
      if (prev_was_digit != 'y') {
        return 0;
      }
      prev_was_digit = 'n';
      continue;
    }
    if (!validator(lit_str[i])) {
      break;
    }
    prev_was_digit = 'y';
  }
  i_suffix = i;
  if (prev_was_digit != 'y') {
    return 0;
  }
  /* Suffix check */
  if (i_suffix == lit_size) {
    return 1;
  } else if (i_suffix == i_begin) {
    return 0;
  } else {
    for (size_t j = 0; j < ryft_numeric_int_datatypes_count; j++) {
      if (ryft_c_str_n_cmp(lit_size - i_suffix, ryft_numeric_int_datatypes[j],
                           lit_str + i_suffix)) {
        return 1;
      }
    }
    return 0;
  }
}

/* A function that determines whether a literal is a float */
static int ryft_is_float_literal(size_t lit_size, const char *lit_str) {
  /* Early return conditions */
  if (lit_size == 0 || lit_str == NULL) {
    return 0;
  }
  /* Declaring some variables for control flow */
  char prev_was_digit = 'n', has_dot = 'n', has_exp = 'n', after_exp = 'n';
  /* Main validation loop */
  size_t i, i_suffix;
  for (i = (size_t)0; i < lit_size; i++) {
    /* If it has no valid characters break the cycle an go to a suffix check */
    // clang-format off
    if (!ryft_is_digit(lit_str[i]) && 
        lit_str[i] != '_' && lit_str[i] != '.' &&
        lit_str[i] != 'e' && lit_str[i] != 'E' && 
        lit_str[i] != '+' && lit_str[i] != '-') {
      break;
    }
    // clang-format on
    /* Check valid characters */
    switch (lit_str[i]) {
    case '_':
      if (prev_was_digit != 'y') {
        return 0;
      }
      prev_was_digit = 'n';
      break;
    case '.':
      if (prev_was_digit != 'y' || has_dot == 'y' || has_exp == 'y') {
        return 0;
      }
      prev_was_digit = 'n';
      has_dot = 'y';
      break;
    case 'e':
    case 'E':
      if (prev_was_digit != 'y' || has_exp == 'y') {
        return 0;
      }
      prev_was_digit = 'n';
      has_exp = 'y';
      after_exp = 'y';
      break;
    case '+':
    case '-':
      if (after_exp != 'y') {
        return 0;
      }
      after_exp = 'n';
      break;
    default:
      if (!ryft_is_digit(lit_str[i])) {
        return 0;
      }
      prev_was_digit = 'y';
      after_exp = 'n';
      break;
    }
  }
  if (prev_was_digit != 'y') {
    return 0;
  }
  i_suffix = i;
  /* Suffix check */
  if (i_suffix == lit_size) {
    return 1;
  } else {
    for (size_t j = 0; j < ryft_numeric_float_datatypes_count; j++) {
      if (ryft_c_str_n_cmp(lit_size - i_suffix, ryft_numeric_float_datatypes[j],
                           lit_str + i_suffix)) {
        return 1;
      }
    }
    return 0;
  }
}

/* A function that tokenizes the string of characters and returns a pointer to
 * the array of tokens */
ryft_token_t *ryft_lexer_tokenize_str(const char *file_contents) {}