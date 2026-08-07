/* Standard C includes */

/* Ryft includes */
#include "../include/ryft-lexer.h"

/* Helper function that determines whether character is a letter */
static int ryft_is_letter(const char c) {
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
  size_t length = 0;
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
    while (ryft_is_digit(cursor[length]) || cursor[length] == '.' ||
           cursor[length] == '_' || ryft_is_letter(cursor[length])) {
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
  return length;
}

/* A function that counts the amount of tokens within a string of characters and
 * returns the count */
size_t ryft_lexer_count_tokens(const char *file_contents) {
  size_t token_amount = (size_t)0;
  const char *cursor = file_contents;
  char c;
  while (*cursor) {
    c = *cursor;
    if (c == ' ' || c == '\t' || c == '\n') {
      cursor++;
      continue;
    }
    cursor += ryft_lexer_token_length(cursor);
    token_amount++;
  }
  return token_amount;
}

/* A function that tokenizes the string of characters and returns a pointer to
 * the array of tokens */
ryft_token_t *ryft_lexer_tokenize_str(size_t token_amount,
                                      const char *file_contents);