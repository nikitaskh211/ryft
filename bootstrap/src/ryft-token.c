/* Ryft includes */
#include "../include/ryft-token.h"

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

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif