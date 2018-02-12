#include <iostream>
#include <memory>
#include "BubbleSort.h"
#include "SelectionSort.h"

int main() {
    const int SIZE = 20;
    int list[SIZE];

    // Populate the array with random values.
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        list[i] = ( rand() % (999 - 100) ) + 100 + 1;
    }

    std::cout << "Unsorted List: \n";
    for (int i : list) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    std::shared_ptr<AbstractSort> b = std::make_shared<SelectionSort>();
    b->sort(list, SIZE);

    std::cout << "Sorted List: \n";
    for (int i : list) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    std::cout << b->ALGORITHM_NAME() << " made " << b->getComparisons() << " comparisons to sort the given array. \n";

    return 0;
}