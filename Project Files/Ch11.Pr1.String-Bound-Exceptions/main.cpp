#include <iostream>
#include "BCheckString.h"

int main() {
    BCheckString b("Jason");

    try {
        std::cout << b[2];
    } catch(BCheckString::BoundsException e) {
        std::cout << "This index, " << e.getErrorIndex() << " is out of bounds.";
    }

    return 0;
}