#include <iostream>
#include <iomanip>
#include "EmployeeInfo.h"
#include "BinaryTree.h"

void loadTestData(BinaryTree<EmployeeInfo> &);

int main() {

    BinaryTree<EmployeeInfo> EmpList;
    loadTestData(EmpList);

    // Display the list of employees.
    std::cout << "Here are the list of employees: \n";
    std::cout << "ID     Name \n";
    std::cout << "-----  ---------------- \n";

    BinaryTree<EmployeeInfo>::Iterator i = EmpList.getInOrderIterator();
    for (; i.good(); ++i) {
        std::cout << std::setw(5) << i->getID() << "  ";
        std::cout << i->getName() << "\n";
    }
    std::cout << "\n";

    // Ask the user for an ID:
    unsigned argID;
    std::shared_ptr<EmployeeInfo> argInfo = nullptr;

    std::cout << "Please enter an Employee ID: ";
    std::cin >> argID;
    std::cout << "\n";
    argInfo = EmpList.extract(argID);

    if (argInfo) {
        std::cout << "The employee with an ID of " << argID << "\n"
                  << "has a name of: " << argInfo->getName() << "\n";
    } else {
        std::cout << "There are no employees with an ID of " << argID << "\n";
    }

    std::cout << "\nDone.";
    return 0;
}

void loadTestData(BinaryTree<EmployeeInfo> & BinTree) {
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

    for (int i = 0; i < SIZE; i++) {
        EmployeeInfo temp(EmpIDs[i], EmpNames[i]);
        BinTree.insert( temp );
    }
};
