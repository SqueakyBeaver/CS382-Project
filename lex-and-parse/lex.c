#include "lex.h"

/* In the first part, you will implement a simple lexcial analyzer that can
recognize the following tokens:
identifier               | foo (var names)
integer literal          | 0-9
left parenthesis         | (
right parenthsis         | )
additive operators       | +, -
multiplicative operators | *, /
*/

int lookup(char ch) {
    // lookup the token for characters that aren't alphanumeric
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
        default:
            addChar();
            nextToken = EOF;
            break;
    }
    return nextToken;
}

void addChar() {
    // Add nextChar to lexeme array
    if (lexLen <= 254) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    }
    else {
        printf("Error - lexeme is too long \n");
    }
}

void getChar() {
    // Reassign nextChar
    // find nextChar's character class and store that
    nextChar = getc(in_fp);
    
    if (nextChar == EOF) {
        charClass = EOF;
    }
    if (isalpha(nextChar)) {
        charClass = LETTER;
    } else if (isdigit(nextChar)) {
        charClass = DIGIT;
    } else {
        charClass = UNKNOWN;
    }
}

void getNonBlank() {
    // calls getChar() until a non-whitespace char is returned
    while(isspace(nextChar)) {
        getChar();
    }
}

int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
        // parse identifiers
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;
        
        // parse int literals
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;
        
        // parentheses and operators
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;

        // EOF
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    }
    // printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    return nextToken;
}