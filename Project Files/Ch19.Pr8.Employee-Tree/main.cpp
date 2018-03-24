#include <iostream>
#include <string>
#include "EmployeeInfo.h"
#include "BinaryTree.h"

int main() {
    // TEST DATA
    const int SIZE = 8;
    int EmpIDs[SIZE] = {
        1021, 1057, 2487, 3769, 1017, 1275, 1899, 4218
    };
    std::string EmpNames[SIZE] {
        "John Williams", "Bill Witherspoon", "Jennifer Twain",
        "Sophia Lancaster", "Debbie Reece", "George McMullen",
        "Ashley Smith", "Josh Plemmons"
    };

    BinaryTree<EmployeeInfo> EmpList;
    for (int i = 0; i < SIZE; i++) {
        EmployeeInfo temp(EmpIDs[i], EmpNames[i]);
        EmpList.insert( temp );
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}