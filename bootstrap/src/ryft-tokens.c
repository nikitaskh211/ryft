/* Standard C includes */
#include <stdio.h>
#include <stdlib.h>

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
    return ('0' <= c && c <= '9') ? (int)(c - '0') : -1;
}

/* Helper for comparing strings of text */
static int ryft_cstr_cmp(const char *cstr1, const char *cstr2)
{
    while (*cstr1 && (*cstr1 == *cstr2))
    {
        cstr1++;
        cstr2++;
    }
    return (int)(*cstr1 - *cstr2);
}

/* Ryft tokenizing function */
size_t ryft_tokenize(const char *src, ryft_token_t *tokens)
{
    if (!src)
    {
        fprinft(stderr, "error:%s:ryft_tokenize:%u: No pointer to the string containing the contents of the source file was provided.", __FILE__, __LINE__);
        return 0;
    }
    else if (!tokens)
    {
        fprintf(stderr, "error:%s:ryft_tokenize:%u: No pointer to an array of tokens was provided.", __FILE__, __LINE__);
        return 0;
    }
    const char *src_reader = src;
    while (*src_reader != '\0')
    {
        if (*src_reader == ' ')
        {
        }
    }
}

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif