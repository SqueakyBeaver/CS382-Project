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
    return nextToken;
}

void addChar() {
    // Add nextChar to lexeme array
}

void getChar() {
    // Reassign nextChar
    // find nextChar's character class and store that
}

void getNonBlank() {}

int lex() { return 0; }