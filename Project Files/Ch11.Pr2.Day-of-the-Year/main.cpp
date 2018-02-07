#include <iostream>
#include "DayOfYear.h"

int main() {

    DayOfYear d;
    int test[ ] = {2, 32, 365};
    int SIZE = sizeof(test) / sizeof(test[0]);
    for (int i = 0; i < SIZE; i++) {
        d.setDay(test[i]);
        std::cout << test[i] << " ";
        d.print();
        std::cout << "\n";
    }

    return 0;
}