//
// Created by TheLoneWoof on 2/9/18.
//

#include "Pstring.h"

// Constructors

Pstring::Pstring(std::string s) : std::string(s) {
    statusPalindrome = false;
    determineStatus();
};

Pstring::Pstring() : Pstring("") { }

// Testing for Palindromes.

void Pstring::determineStatus() {
    int size, end, i;
    // Strings of size 0 are not palindromes.
    // That's just cheating.
    size = this->size();
    if (size == 0) {
        statusPalindrome = false;
        return;
    }

    end = size / 2;
    // There's no need to test the middle char
    // against itself.
    for (i = 0; i < end; i++) {
        if ( tolower((*this)[i]) != tolower((*this)[size - 1 - i]) ) {
            break;
        }
    }
    if ( i == end ) statusPalindrome = true;
    else statusPalindrome = false;
}
