#pragma once
#include <stdio.h>

// Global variables from main.c
extern int charClass;
extern char lexeme[256];
extern char nextChar;
extern int lexLen;
extern int nextToken;
extern FILE *in_fp;
extern FILE *out_fp;

void expr();
void term();
void factor();
void error(const char* action, const char* msg);
void printNode(const char* name, ...);