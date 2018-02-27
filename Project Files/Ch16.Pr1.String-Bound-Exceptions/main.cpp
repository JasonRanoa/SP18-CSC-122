#include <iostream>
#include "BCheckString.h"

int main() {
    BCheckString b("Xorem Xpsum");

    std::cout << "After construction:     " << b << "\n";

    // This still works!
    b[0] = 'L';
    b[6] = 'i';

    std::cout << "After char adjustments: " << b << "\n";

    std::cout << "Testing exception handling... \n";

    for (int i = -2; i < (signed)(b.length()) + 2; i++) {
        static char t;
        try {
            t = b[i];
            std::cout << "   At index " << i << ", found " << t << "\n";
        } catch(BCheckString::BoundsException e) {
            std::cout << "   Index, " << e.getErrorIndex() << ", is out of bounds. \n";
        }
    }

    return 0;
}