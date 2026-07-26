#ifndef RYFT_TOKENS_H
#define RYFT_TOKENS_H

/* ---- X-macro expansion safety. ---- */

#ifdef X
#undef X
#endif // !X

/* ---- Primitive tokens. ---- */

/* ==== Identifiers ==== */

#define IDENTIFIERS \
  X(ID, "<id>")

/* ==== Literals ==== */

#define LITERALS              \
  X(LIT_TRUE, "true")         \
  X(LIT_FALSE, "false")       \
  X(LIT_INT, "<int>")         \
  X(LIT_REAL, "<real>")       \
  X(LIT_COMPLEX, "<complex>") \
  X(LIT_CHAR, "<char>")       \
  X(LIT_STR, "<str>")

/* ==== Datatypes ==== */

#define BOOLEANS \
  X(TYPE_BOOL, "bool")

#define UNSIGNED_INTEGERS \
  X(TYPE_U08, "u08")      \
  X(TYPE_U16, "u16")      \
  X(TYPE_U32, "u32")      \
  X(TYPE_U64, "u64")

#define SIGNED_INTEGERS \
  X(TYPE_I08, "i08")    \
  X(TYPE_I16, "i16")    \
  X(TYPE_I32, "i32")    \
  X(TYPE_I64, "i64")

#define REAL_FLOATS  \
  X(TYPE_R08, "r08") \
  X(TYPE_R16, "r16") \
  X(TYPE_R32, "r32") \
  X(TYPE_R64, "r64")

#define COMPLEX_FLOATS \
  X(TYPE_C08, "c08")   \
  X(TYPE_C16, "c16")   \
  X(TYPE_C32, "c32")   \
  X(TYPE_C64, "c64")

#define CHARACTERS     \
  X(TYPE_CHAR, "char") \
  X(TYPE_STR, "str")

#define POINTERS \
  X(TYPE_PTR, "ptr")

/* ==== Direction attributes ==== */

#define DIRECTIONS        \
  X(OPTIONAL, "optional") \
  X(IN, "in")             \
  X(OUT, "out")           \
  X(IN_OUT, "in_out")

/* ==== Declarations ==== */

#define DECLARATIONS  \
  X(LET, "let")       \
  X(CONST, "const")   \
  X(STRUCT, "struct") \
  X(ENUM, "enum")     \
  X(UNION, "union")

/* ==== Control flow ==== */

#define CONTROL_FLOW      \
  X(IF, "if")             \
  X(ELIF, "elif")         \
  X(ELSE, "else")         \
  X(MATCH, "match")       \
  X(CASE, "case")         \
  X(DEFAULT, "default")   \
  X(LOOP, "loop")         \
  X(FROM, "from")         \
  X(TO, "to")             \
  X(WHILE, "while")       \
  X(BREAK, "break")       \
  X(CONTINUE, "continue") \
  X(RETURN, "return")

/* ==== Procedures ==== */

#define PROCEDURES      \
  X(FUNC, "func")       \
  X(SUBR, "subr")       \
  X(PROG, "prog")       \
  X(RETURNS, "returns") \
  X(CALL, "call")

/* ==== Memory management ==== */

#define MEMORY_MANAGEMENT     \
  X(ALLOCATE, "allocate")     \
  X(DEALLOCATE, "deallocate") \
  X(REALLOCATE, "reallocate") \
  X(ALLOCATED, "allocated")

/* ==== Directives ==== */

#define DIRECTIVES         \
  X(MODULE, "#module")     \
  X(IMPORT, "#import")     \
  X(ENCODING, "#encoding") \
  X(UNSAFE, "#unsafe")     \
  X(EXTERN, "#extern")     \
  X(INLINE, "#inline")     \
  X(UNROLL, "#unroll")

/* ==== Operators ==== */

#define BOOLEAN_OPERATORS \
  X(NOT, "not")           \
  X(AND, "and")           \
  X(OR, "or")

#define ARITHMETIC_OPERATORS \
  X(PLUS, "+")               \
  X(MINUS, "-")              \
  X(STAR, "*")               \
  X(SLASH, "/")              \
  X(PERCENT, "%")            \
  X(STAR_STAR, "**")         \
  X(AT, "@")

#define COMPARISON_OPERATORS \
  X(EQUAL, "==")             \
  X(NOT_EQUAL, "!=")         \
  X(LESS, "<")               \
  X(GREATER, ">")            \
  X(LESS_EQUAL, "<=")        \
  X(GREATER_EQUAL, ">=")

#define BITWISE_OPERATORS \
  X(AMPERSAND, "&")       \
  X(PIPE, "|")            \
  X(CARET, "^")           \
  X(TILDE, "~")           \
  X(LEFT_SHIFT, "<<")     \
  X(RIGHT_SHIFT, ">>")

#define ASSIGNMENT_OPERATORS \
  X(ASSIGN, "=")             \
  X(PLUS_EQUAL, "+=")        \
  X(MINUS_EQUAL, "-=")       \
  X(STAR_EQUAL, "*=")        \
  X(SLASH_EQUAL, "/=")       \
  X(PERCENT_EQUAL, "%=")     \
  X(STAR_STAR_EQUAL, "**=")  \
  X(AT_EQUAL, "@=")          \
  X(AMPERSAND_EQUAL, "&=")   \
  X(PIPE_EQUAL, "|=")        \
  X(CARET_EQUAL, "^=")       \
  X(LEFT_SHIFT_EQUAL, "<<=") \
  X(RIGHT_SHIFT_EQUAL, ">>=")

#define ACCESS_OPERATORS \
  X(DOT, ".")            \
  X(ARROW, "->")

/* ==== Delimiters ==== */

#define DELIMITERS          \
  X(LEFT_PARENTHESIS, "(")  \
  X(RIGHT_PARENTHESIS, ")") \
  X(LEFT_BRACKET, "[")      \
  X(RIGHT_BRACKET, "]")     \
  X(LEFT_BRACE, "{")        \
  X(RIGHT_BRACE, "}")       \
  X(COMMA, ",")             \
  X(COLON, ":")             \
  X(SEMICOLON, ";")         \
  X(HASH, "#")

/* ==== Special tokens ==== */

#define SPECIAL           \
  X(EOF, "<end_of_file>") \
  X(COMMENT, "<comment>")

/* ---- Groups of primitive tokens. ---- */

/* ==== Group of datatypes ==== */

#define DATATYPES   \
  BOOLEANS          \
  UNSIGNED_INTEGERS \
  SIGNED_INTEGERS   \
  REAL_FLOATS       \
  COMPLEX_FLOATS    \
  CHARACTERS        \
  POINTERS

/* ==== Group of keywords ==== */

#define KEYWORDS \
  DECLARATIONS   \
  CONTROL_FLOW   \
  PROCEDURES     \
  MEMORY_MANAGEMENT

/* ==== Group of operators ==== */

#define OPERATORS      \
  BOOLEAN_OPERATORS    \
  ARITHMETIC_OPERATORS \
  COMPARISON_OPERATORS \
  BITWISE_OPERATORS    \
  ASSIGNMENT_OPERATORS \
  ACCESS_OPERATORS

/* ------ Complete set of tokens. ------ */

#define RYFT_TOKENS \
  IDENTIFIERS       \
  LITERALS          \
  DATATYPES         \
  DIRECTIONS        \
  KEYWORDS          \
  DIRECTIVES        \
  OPERATORS         \
  DELIMITERS        \
  SPECIAL

/* ----- X-macro expansion safety. ----- */

#ifdef X
#undef X
#endif // !X

#endif // !RYFT_TOKENS_H