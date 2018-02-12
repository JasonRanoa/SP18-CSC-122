#include <iostream>
#include "DayOfYearMod.h"

int main() {

    int test[ ] = {2, 32, 365};
    const int SIZE = sizeof(test) / sizeof(test[0]);

    DayOfYearMod d[SIZE];

    // Assign test values.

    for (int i = 0; i < SIZE; i++) {
        d[i].setDay(test[i]);
        std::cout << d[i] << " \n";
    }

    std::cout << "\n";
    std::cout << "Add a day to each. \n";
    std::cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        std::cout << ++d[i] << "\n";
    }

    std::cout << "\n";
    std::cout << "Remove a day to each. \n";
    std::cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        std::cout << --d[i] << "\n";
    }

    return 0;
}
