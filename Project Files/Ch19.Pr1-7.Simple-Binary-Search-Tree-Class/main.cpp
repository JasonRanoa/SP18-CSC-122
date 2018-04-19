#include <iostream>
#include <sstream>
#include <vector>
#include "BinaryTree.h"

void enterTestData(BinaryTree &);
void displayTreeInfo(BinaryTree * const, std::string);

void demoOne();
void demoTwo();
void demoThree();

int main() {
    demoThree();

    return 0;
}

void enterTestData(BinaryTree & bin) {
    std::string testData =
        "72.8 39.2 10.9 20.3 42.7 "
        "40.0 69.8 50.2 73.2 90.2 "
        "85.3 97.6 95.4";

    std::stringstream ss(testData);

    double temp;
    while (ss >> temp) {
        bin.insert(temp);
    }
}

void displayTreeInfo(BinaryTree * const bin, std::string name) {
    std::cout << "  " << name << " Information: \n";
    std::vector<double> dList;
    bin->inorder(dList);
    std::cout << "    Data: ";
    for (double d : dList) {
        std::cout << d << " ";
    }
    std::cout << "\n";
    std::cout << "    Size: " << bin->size() << "; ";
    std::cout << "Leaf Count: " << bin->leafCount() << "; ";
    std::cout << "Height: " << bin->height() << "; ";
    std::cout << "Width: " << bin->width() << "\n";
    std::cout << "\n";
}

void demoOne() {
    BinaryTree treeOne;
    enterTestData(treeOne);

    std::vector<double> numList;
    treeOne.inorder(numList);

    std::cout << "Displaying list values in order: \n";
    for (double d : numList) {
        std::cout << d << " ";
    }
    std::cout << "\n\n";

    std::cout << "Tree Information: \n";
    std::cout << "  Size       : " << treeOne.size() << "\n"; // should be 13
    std::cout << "  Leaf Count : " << treeOne.leafCount() << "\n"; // should be 5
    std::cout << "  Height     : " << treeOne.height() << "\n"; // should be 5
    std::cout << "  Width      : " << treeOne.width() << "\n"; // should be 5
    std::cout << "\n";

    double positiveTests[] = { 73.2, 42.7, 20.3, 50.2, 95.4 };
    std::cout << "Testing for false-negatives (method should return true)... \n";
    for (double test : positiveTests) {
        std::cout << "  Searching for " << test << "... ";
        if (treeOne.search(test)) {
            std::cout << "Returned true. PASS. \n";
        } else {
            std::cout << "Returned false. FAIL. \n";
        }
    }
    std::cout << "\n";

    double negativeTests[] = { 31.4, 62.5, 99.9, 15.4, 62.7 };
    std::cout << "Testing for false-positives (method should return false)... \n";
    for (double test : negativeTests) {
        std::cout << "  Searching for " << test << "... ";
        if (treeOne.search(test)) {
            std::cout << "Returned true. FAIL. \n";
        } else {
            std::cout << "Returned false. PASS. \n";
        }
    }
}

void demoTwo() {
    BinaryTree treeOne;
    enterTestData(treeOne);

    std::vector<double> numList;
    treeOne.inorder(numList);
    BinaryTree treeTwo = treeOne; // Uses the copy constructor

    std::cout << "Displaying initial states. \n"
                 "They should have the same information. \n\n";
    displayTreeInfo(&treeOne, "Initial TreeOne");
    displayTreeInfo(&treeTwo, "Initial TreeOne");

    double test[] = { 6.9, 80.2, 49.3 };
    for (double d : test) {
        treeTwo.insert(d);
    }
    std::cout << "Displaying post-addition information. \n\n"
                 "They should be different. \n";
    displayTreeInfo(&treeOne, "Post-Addition TreeOne");
    displayTreeInfo(&treeTwo, "Post-Addition TreeTwo");

}

void demoThree() {
    BinaryTree treeOne, treeTwo, treeThree;
    enterTestData(treeOne);

    std::vector<double> numList;
    treeOne.inorder(numList);

    std::cout << "Displaying initial states. \n"
                 "Only treeOne should have members. \n\n";
    displayTreeInfo(&treeOne, "TreeOne");
    displayTreeInfo(&treeTwo, "TreeTwo");
    displayTreeInfo(&treeThree, "ThreeTree");

    treeThree = treeTwo = treeOne; // this uses an assignment operator.

    std::cout << "Displaying post-assignment operator. \n"
                 "The trees should all have the same information. \n\n";
    displayTreeInfo(&treeOne, "TreeOne");
    displayTreeInfo(&treeTwo, "TreeTwo");
    displayTreeInfo(&treeThree, "ThreeTree");

    // Adding stuff to treeTwo.
    double testTwo[] = { 6.9, 80.2, 49.3 };
    for (double d : testTwo) {
        treeTwo.insert(d);
    }

    double testThree[] = { 108.2, 221.7, 397.8, 407.2, 503.4, 10.8, 21.6 };
    treeThree = BinaryTree(); // Resetting treeTree
    for (double d : testThree) {
        treeThree.insert(d);
    }

    std::cout << "Displaying post-adjustment information. \n\n"
                 "They should be different. \n";
    displayTreeInfo(&treeOne, "TreeOne");
    displayTreeInfo(&treeTwo, "TreeTwo");
    displayTreeInfo(&treeThree, "ThreeTree");
}