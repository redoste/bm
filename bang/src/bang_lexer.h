#ifndef BANG_LEXER_H_
#define BANG_LEXER_H_

#include <stdlib.h>

#include "./sv.h"
#include "./bang_diag.h"

typedef enum {
    BANG_TOKEN_KIND_NAME = 0,
    BANG_TOKEN_KIND_NUMBER,
    BANG_TOKEN_KIND_OPEN_PAREN,
    BANG_TOKEN_KIND_CLOSE_PAREN,
    BANG_TOKEN_KIND_OPEN_CURLY,
    BANG_TOKEN_KIND_CLOSE_CURLY,
    BANG_TOKEN_KIND_SEMICOLON,
    BANG_TOKEN_KIND_COLON,
    BANG_TOKEN_KIND_COMMA,
    BANG_TOKEN_KIND_EQ,
    BANG_TOKEN_KIND_LIT_STR,
    BANG_TOKEN_KIND_PLUS,
    BANG_TOKEN_KIND_MINUS,
    BANG_TOKEN_KIND_MULT,
    BANG_TOKEN_KIND_LT,
    BANG_TOKEN_KIND_GE,
    BANG_TOKEN_KIND_NE,
    BANG_TOKEN_KIND_AND,
    BANG_TOKEN_KIND_OR,
    BANG_TOKEN_KIND_EQ_EQ,
    COUNT_BANG_TOKEN_KINDS,
} Bang_Token_Kind;

const char *bang_token_kind_name(Bang_Token_Kind kind);

typedef struct {
    Bang_Token_Kind kind;
    String_View text;
    Bang_Loc loc;
} Bang_Token;

#define BANG_TOKEN_BUFFER_CAPACITY 2

typedef struct {
    Bang_Token tokens[BANG_TOKEN_BUFFER_CAPACITY];
    size_t begin;
    size_t count;
} Bang_Token_Buffer;

void bang_token_buffer_nq(Bang_Token_Buffer *buffer, Bang_Token token);
Bang_Token bang_token_buffer_dq(Bang_Token_Buffer *buffer);
Bang_Token bang_token_buffer_get(const Bang_Token_Buffer *buffer, size_t i);

typedef struct {
    String_View content;
    const char *line_start;
    String_View line;
    const char *file_path;
    size_t row;

    Bang_Token_Buffer peek_buffer;
} Bang_Lexer;

Bang_Lexer bang_lexer_from_sv(String_View content, const char *file_path);

Bang_Loc bang_lexer_loc(Bang_Lexer *lexer);

Bang_Token bang_lexer_expect_token(Bang_Lexer *lexer, Bang_Token_Kind kind);
Bang_Token bang_lexer_expect_keyword(Bang_Lexer *lexer, String_View name);
bool bang_lexer_next(Bang_Lexer *lexer, Bang_Token *token);
bool bang_lexer_peek(Bang_Lexer *lexer, Bang_Token *token, size_t offset);

#endif // BANG_LEXER_H_
