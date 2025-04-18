#include "lex.h"

/* 
lexical analyzer grammar (EBNF)
<id> -> <letter> { <letter> | <digit> }
<int> -> <digit> {<digit>}
<letter> -> a | b | ... |z | A | B | ... |Z
<digit> -> 0 | 1 | ... | 9
*/

int lookup(char ch) {
    addChar();
    // lookup the token for characters that aren't alphanumeric
    switch (ch) {
    case '(':
        nextToken = LEFT_PAREN;
        break;
    case ')':
        nextToken = RIGHT_PAREN;
        break;
    case '+':
        nextToken = ADD_OP;
        break;
    case '-':
        nextToken = SUB_OP;
        break;
    case '*':
        nextToken = MULT_OP;
        break;
    case '/':
        nextToken = DIV_OP;
        break;
    default:
        nextToken = EOF;
        break;
    }
    return nextToken;
}

void addChar() {
    // Add nextChar to lexeme array
    if (lexLen > 254) {
        printf("Error - lexeme is too long \n");
        return;
    }

    lexeme[lexLen++] = nextChar;
    lexeme[lexLen] = 0;
}

void getChar() {
    // Reassign nextChar
    nextChar = getc(in_fp);
    
    // find nextChar's character class and store that
    if (nextChar == EOF) {
        charClass = EOF;
        return;
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
    while (isspace(nextChar))
        getChar();
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

    return nextToken;
}