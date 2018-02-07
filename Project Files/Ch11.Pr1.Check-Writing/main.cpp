#include <iostream>
#include <random>
#include "Numbers.h"

int main() {


    Numbers n(0);

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        static int x;
        x = rand() % 9999;
        n.setNumber( x );
        std::cout << x << " ";
        n.print();
        std::cout << "\n";
    }

    return 0;
}