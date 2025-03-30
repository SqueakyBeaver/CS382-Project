#include <stdio.h>

// Global variables from main.c
extern int charClass;
extern char lexeme[256];
extern char nextChar;
extern int lexLen;
extern int nextToken;
extern FILE *in_fp;

void expr();
void term();
void factor();