/*
This program will parse an input based on the following EBNF grammar:
<expr> -> <term> { (+ | -) <term> }
<term> -> <factor> { (* | /) <factor> }
<factor> -> id | int_constant | (<expr>)
*/
#include <stdio.h>

#include "lex.h"
#include "parse.h"

// Global variables
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int nextToken;
FILE *in_fp;

int main() {
    if ((in_fp = fopen("./input", "r")) == NULL) {
        printf("Error: cannot open input file\n");
        return -1;
    }

    // Parse here

    fclose(in_fp);

    return 0;
}