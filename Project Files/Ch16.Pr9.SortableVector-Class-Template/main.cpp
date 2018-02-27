#include <iostream>
#include "SortableVector.h"

int main() {
    SortableVector<int> s(10);
    srand(time(NULL));
    for (int i = 0; i < s.size(); i++) {
        s[i] = rand() % 1000 + 1;
    }
    cout << "Vector of random integers: \n";
    s.print();

    cout << "\n";
    cout << "... sorting the vector ... \n";
    cout << "\n";
    s.sort();

    cout << "The vector after sorting: \n";
    s.print();
    return 0;
}