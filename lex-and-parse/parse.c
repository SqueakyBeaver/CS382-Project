#include "parse.h"

// TODO: Change the printf's to fprintf's

// Parses the EBNF rule:
// <expr> -> <term> { (+ | -) <term> }
void expr() {
    printf("[expr\n");

    // Parse the first term

    // If there's a + or -, get the next token, then parse the next term

    printf("]\n");
}

// Parses the EBNF rule:
// <term> -> <factor> { (* | /) <factor> }
void term() {
    printf("\t[term\n");

    // Parse the first factor

    // If there's a * or /, get the next token, then parse the next factor

    printf("\t]\n");
}

// Parses the EBNF rule:
// <factor> -> id | int_constant | ( <expr> )
void factor() {
    printf("\t\t[factor\n\t");

    // Find out what the first token is
    // If it's a (, then parse the expression

    printf("\t\t]\n");
}