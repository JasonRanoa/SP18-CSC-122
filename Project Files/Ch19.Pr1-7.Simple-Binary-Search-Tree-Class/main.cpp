#include <iostream>
#include <vector>
#include "BinaryTree.h"

int main() {
    BinaryTree bin;

    bin.insert(2.34);
    bin.insert(3.14);
    bin.insert(6.28);
    bin.insert(2.98);
    bin.insert(1.21);
    bin.insert(-0.54);
    bin.insert(100.0);
    bin.insert(100.4);
    bin.insert(100.5);
    bin.insert(100.6);
    bin.insert(0);

    std::vector<double> list;
    bin.inorder(list);


    for (double d : list) {
        std::cout << d << " ";
    }
    std::cout << "\n";

    std::cout << "SIZE: " << bin.size() << "\n";
    std::cout << "LEAVES: " << bin.leafCount() << "\n";
    std::cout << "HEIGHT: " << bin.height() << "\n";
    std::cout << "WIDTH: " << bin.width() << "\n";

    BinaryTree vin = bin;

    list.clear();
    vin.inorder(list);

    for (double d : list) {
        std::cout << d << " ";
    }
    std::cout << "\n";

    vin.insert(40);
    bin = vin;

    std::cout << "SIZE: " << vin.size() << "\n";
    std::cout << "LEAVES: " << vin.leafCount() << "\n";
    std::cout << "HEIGHT: " << vin.height() << "\n";
    std::cout << "WIDTH: " << vin.width() << "\n";

    list.clear();
    vin.inorder(list);

    for (double d : list) {
        std::cout << d << " ";
    }
    std::cout << "\n";


    return 0;
}