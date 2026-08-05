#ifndef RYFT_TOKENS_H
/* Header guard */
#define RYFT_TOKENS_H

/* Standard C includes */
#include <stddef.h>

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif

#define RYFT_SERVICE(TOKEN)                                                 \
    /* End of file */                                                       \
    TOKEN(EOF, "<eof>") /* Marks the end of the token stream */             \
    /* Unknown */                                                           \
    TOKEN(UNKNOWN, "<unknown>") /* Marks unrecognized character sequence */ \
    /* Error */                                                             \
    TOKEN(ERROR, "<error>") /* Malformed token */

#define RYFT_IDENTIFICATOR(TOKEN) \
    /* String identificator */    \
    TOKEN(ID, "<id>")

#define RYFT_DECLARATION(TOKEN)                      \
    /* Variable declaration */                       \
    TOKEN(LET, "let")     /* Declaring a variable */ \
    TOKEN(CONST, "const") /* Declaring a constant */

#define RYFT_DATATYPE(TOKEN)                                        \
    /* Unsigned integers */                                         \
    TOKEN(U8, "u8")   /* 8bit  unsigned integer */                  \
    TOKEN(U16, "u16") /* 16bit unsigned integer */                  \
    TOKEN(U32, "u32") /* 32bit unsigned integer */                  \
    TOKEN(UOS, "uos") /* unsigned integer the size of OS bitness */ \
    TOKEN(U64, "u64") /* 64bit unsigned integer */                  \
    /* Signed integers */                                           \
    TOKEN(I8, "i8")   /* 8bit  signed integer */                    \
    TOKEN(I16, "i16") /* 16bit signed integer */                    \
    TOKEN(I32, "i32") /* 32bit signed integer */                    \
    TOKEN(I64, "i64") /* 64bit signed integer */                    \
    /* Floating point numbers */                                    \
    TOKEN(R32, "r32") /* 32bit floating point real number */        \
    TOKEN(R64, "r64") /* 64bit floating point real number */        \
    TOKEN(C32, "c32") /* 32bit floating point complex number */     \
    TOKEN(C64, "c64") /* 64bit floating point complex number */

#define RYFT_BOOL_LITERAL(TOKEN)                                             \
    /* Booleans */                                                           \
    TOKEN(LIT_TRUE, "true")   /* A system constant for the value of true  */ \
    TOKEN(LIT_FALSE, "false") /* A system constant for the value of false */

#define RYFT_NUM_LITERAL(TOKEN)                                        \
    /* Integers */                                                     \
    TOKEN(LIT_INT, "<int>") /* A constant integer */                   \
    /* Floating point numbers */                                       \
    TOKEN(LIT_FLOAT, "<float>") /* A constant floating point number */ \
    /* Characters */                                                   \
    TOKEN(LIT_CHAR, "<char>") /* A constant UTF-8 character */         \
    TOKEN(LIT_STR, "<str>")   /* A constant array of UTF-8 characters */

#define RYFT_OPERATOR(TOKEN)                                                   \
    /* Arithmetic */                                                           \
    TOKEN(EQUAL, "=")    /* Assign a value to a number                      */ \
    TOKEN(PLUS, "+")     /* Add two numbers                                 */ \
    TOKEN(MINUS, "-")    /* Subtract two numbers                            */ \
    TOKEN(MULTIPLY, "*") /* Multiply two numbers                            */ \
    TOKEN(DIVIDE, "/")   /* Divide one number by another                    */ \
    TOKEN(MODULUS, "%%") /* Calculate modulus one number divided by another */

/* Enumeration of all tokens */
#define TOKEN(tag, _) RYFT_##tag,
// clang-format off
typedef enum ryft_tokens
{
    RYFT_SERVICE(TOKEN)
    RYFT_IDENTIFICATOR(TOKEN)
    RYFT_DECLARATION(TOKEN)
    RYFT_DATATYPE(TOKEN)
    RYFT_BOOL_LITERAL(TOKEN)
    RYFT_NUM_LITERAL(TOKEN)
    RYFT_OPERATOR(TOKEN)
    RYFT_TOKEN_COUNT
} ryft_tokens_t;
// clang-format on
#undef TOKEN

/* Table of Ryft keywords */
extern const char *ryft_keywords[];

/* Structure of a single Ryft token */
typedef struct ryft_token
{
    char *ptr_to_lexeme;
    size_t lexeme_length;
    size_t row, column;
    ryft_tokens_t kind;
} ryft_token_t;

/* TOKEN macro safety */
#ifdef TOKEN
#undef TOKEN
#endif

/* Ryft tokenizing function */
size_t ryft_tokenize(const char *src, ryft_token_t *tokens);

#endif // !RYFT_TOKENS_H