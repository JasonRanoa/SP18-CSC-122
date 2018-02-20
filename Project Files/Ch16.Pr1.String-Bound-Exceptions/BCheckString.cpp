//
// Created by TheLoneWoof on 2/15/18.
//

#include "BCheckString.h"
#include <iostream>

BCheckString::BCheckString() : std::string("") { }
BCheckString::BCheckString(std::string s) : std::string(s) {
    firstChar = const_cast<char *>( this->data() );
}

char& BCheckString::operator[](int k) {
    if (k < 0 || k >= this->size()) {
        throw BoundsException(k);
    } else {
        return *(firstChar + k);
    }
}


