#include <stdio.h>

#include "lex.h"
#include "parse.h"

/*
This program will parse an input based on the following EBNF grammar:
<expr> -> <term> { (+ | -) <term> }
<term> -> <factor> { (* | /) <factor> }
<factor> -> <id> | <int> | (<expr>)
<id> -> <letter> { <letter> | <digit> }
<int> -> <digit> {<digit>}
<letter> -> a | b | ... |z | A | B | ... |Z
<digit> -> 0 | 1 | ... | 9
*/

// Global variables
int charClass;
char lexeme[256];
char nextChar;
int lexLen;
int nextToken;
FILE *in_fp;
FILE *out_fp;

int main() {
    if ((in_fp = fopen("./input", "r")) == NULL) {
        printf("Error: cannot open input file\n");
        return -1;
    }

    if ((out_fp = fopen("./output", "w+")) == NULL) {
        printf("Error: Cannot open output file\n");
        return -1;
    }

    getChar();
    do {
        lex();
        expr();
    } while (nextToken != EOF);

    fclose(in_fp);
    fclose(out_fp);

    return 0;
}