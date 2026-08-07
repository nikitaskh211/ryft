#ifndef RYFT_LEXER_H
/* Header guard */
#define RYFT_LEXER_H

/* Ryft includes */
#include "./ryft-token.h"

/* A function that counts the amount of tokens within a string of characters and returns the count */
size_t ryft_lexer_count_tokens(const char *file_contents);

/* A function that tokenizes the string of characters and returns a pointer to the array of tokens */
ryft_token_t *ryft_lexer_tokenize_str(size_t token_amount, const char *file_contents);

#endif // !RYFT_LEXER_H