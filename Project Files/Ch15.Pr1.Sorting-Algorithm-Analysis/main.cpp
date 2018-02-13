#include <iostream>
#include <memory>
#include "BubbleSort.h"
#include "SelectionSort.h"

int main() {
    const int SIZE = 20;
    int listSel[SIZE];

    // Populate the array with random values.
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        listSel[i] = ( rand() % (999 - 100) ) + 100 + 1;
    }

    // Recreate the array for Bubble Sort.
    int listBub[SIZE];
    std::copy(listSel, listSel + SIZE, listBub);

    std::cout << "Unsorted List: \n";
    for (int i : listSel) {
        static int nl = 1;
        std::cout << i << " ";
        if (nl % 20 == 0 && nl != SIZE) std::cout << "\n";
        nl++;
    }
    std::cout << "\n\n";

    // TESTING SELECTION SORT.
    std::shared_ptr<AbstractSort> sel = std::make_shared<SelectionSort>();
    sel->sort(listSel, SIZE);

    std::cout << "Sorted List after SELECTION SORT: \n";
    for (int i : listSel) {
        static int nl = 1;
        std::cout << i << " ";
        if (nl % 20 == 0 && nl != SIZE) std::cout << "\n";
        nl++;
    }
    std::cout << "\n\n";

    std::cout << sel->ALGORITHM_NAME() << " made "
              << sel->getComparisons() << " comparisons to sort the given array. \n\n";

    // TESTING BUBBLE SORT
    std::shared_ptr<AbstractSort> bub = std::make_shared<BubbleSort>();
    bub->sort(listBub, SIZE);

    std::cout << "Sorted List after BUBBLE SORT: \n";
    for (int i : listBub) {
        static int nl = 1;
        std::cout << i << " ";
        if (nl % 20 == 0 && nl != SIZE) std::cout << "\n";
        nl++;
    }
    std::cout << "\n\n";

    std::cout << bub->ALGORITHM_NAME() << " made "
              << bub->getComparisons() << " comparisons to sort the given array. \n";

    return 0;
}