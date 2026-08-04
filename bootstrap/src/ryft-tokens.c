/* Standard C includes */
#include <stdlib.h>
#include <assert.h>

/* Ryft includes */
#include "../include/ryft-tokens.h"

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif

/* Table of Ryft keywords */
#define TOKEN(_, keyword) keyword,
// clang-format off
const char *ryft_keywords[] = {
    RYFT_DECLARATION(TOKEN)
    RYFT_DATATYPE(TOKEN)
    RYFT_BOOL_LITERAL(TOKEN)
};
// clang-format on
#undef TOKEN

/* Helper for converting a char into an integer */
static int ryft_char_to_int(char c)
{
    // Precondition: Caller must guarantee that '0' <= c <= '9'
    assert('0' <= c && c <= '9');
    return (int)(c - '0');
}

/* Ryft tokenizing function */
size_t ryft_tokenize(const char *src, ryft_token_t *tokens)
{
    // Checking for early errors.
    assert(!src);
    assert(!tokens);
    // Two-pointer approach.
    char *lexeme_begin, *lexeme_end;
    // We begin at the same pointer as src.
    lexeme_begin = src;
    // We end at the next logical element.
    lexeme_end = lexeme_begin + 1;
    // We iterate through string character by character.
    while (*lexeme_end != '\0')
    {
    }
}

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif