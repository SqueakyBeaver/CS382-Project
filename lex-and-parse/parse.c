#include "parse.h"

// Parses the EBNF rule:
// <expr> -> <term> { (+ | -) <term> }
void expr() {
    printf("[expr\n");

    // Parse expression

    printf("]\n");
}

// Parses the EBNF rule:
// <term> -> <factor> { (* | /) <factor> }
void term() {
    printf("\t[term\n");

    // Parse term

    printf("\t]\n");
}

// Parses the EBNF rule:
// <factor> -> id | int_constant | ( <expr> )
void factor() {
    printf("\t\t[factor\n\t");

    // Parse factor

    printf("\t\t]\n");
}