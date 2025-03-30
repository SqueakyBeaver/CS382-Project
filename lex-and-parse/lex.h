#pragma once
// This header file only exists to de-clutter main.c
#include <stdio.h>
#include <ctype.h>

// Global variables from main.c
extern int charClass;
extern char lexeme[256];
extern char nextChar;
extern int lexLen;
extern int nextToken;
extern FILE *in_fp;
extern FILE *out_fp;


void addChar();
void getChar();
void getNonBlank();
int lex();

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
