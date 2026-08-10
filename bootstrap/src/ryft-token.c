/* Ryft includes */
#include "../include/ryft-token.h"

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif

/* Table of Ryft datatypes */
#define TOKEN(_, keyword) keyword,
// clang-format off
const char *ryft_numeric_int_datatypes[] = {
    RYFT_NUMERIC_INT_DATATYPE(TOKEN)
};
const char *ryft_numeric_float_datatypes[] = {
    RYFT_NUMERIC_FLOAT_DATATYPE(TOKEN)
};
const char *ryft_special_datatypes[] = {
    RYFT_SPECIAL_DATATYPE(TOKEN)
};
// clang-format on
#undef TOKEN

/* Table sizes of Ryft datatypes */
const size_t ryft_numeric_int_datatypes_count =
    sizeof(ryft_numeric_int_datatypes) / sizeof(ryft_numeric_int_datatypes[0]);
const size_t ryft_numeric_float_datatypes_count =
    sizeof(ryft_numeric_float_datatypes) /
    sizeof(ryft_numeric_float_datatypes[0]);
const size_t ryft_special_datatypes_count =
    sizeof(ryft_special_datatypes) / sizeof(ryft_special_datatypes[0]);

/* Table of Ryft keywords */
#define TOKEN(_, keyword) keyword,
// clang-format off
const char *ryft_keywords[] = {
    RYFT_DECLARATION(TOKEN)
    RYFT_NUMERIC_INT_DATATYPE(TOKEN)
    RYFT_NUMERIC_FLOAT_DATATYPE(TOKEN)
    RYFT_BOOL_LITERAL(TOKEN)
};
// clang-format on
#undef TOKEN

/* Table size of Ryft keywords */
const size_t ryft_keywords_count =
    sizeof(ryft_keywords) / sizeof(ryft_keywords[0]);

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif