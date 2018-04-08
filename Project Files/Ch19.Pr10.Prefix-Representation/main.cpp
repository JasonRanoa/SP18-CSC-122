#include <iostream>
#include <vector>
#include "IntBinaryTree.h"

/*
 *    Programming Challenge 10
 *    Prefix Representation of Binary Trees
 *
 *    Rules:
 *    1. The prefix representation of an empty binary tree is a single underscore.
 *    2. The prefix presentation of a non-empty binary tree is (v L, R),
 *       where v represents the value stored in root and
 *             L and R are the prefix representations of the left and right subtrees.
 *
 *    Modify the binary tree class of Program 19-1 to add the ff. member functions.
 *    1. void treePrint():
 *       This public member function will print the prefix representation of a
 *       binary tree object to standard output.
 *    2. void treePrint(TreeNode * root, ostream& out) const:
 *       This private member function will print the prefix representation of the
 *       binary tree with a given root to a given output stream.
 *
 */

int main() {
    // Loading test data
    std::vector<std::vector<int>> testPool = {
        { }, // intentionally kept empty
        { 5 }, // (5_,_)
        { 4, 2, 6, 1, 3, 5, 7 }, // 4 leaf nodes, 3 levels.
        { 1, 2, 3, 4, 5 }, // Only one leaf node.
        { 3, 1, 4, 5, 9, 2, 6 }, // First seven digits of pi
        { 5, 4, 6, 1, 2, 3, 9, 8, 7 } // Tree forms a diamond.
    };

    std::cout << "Testing treePrint() method... \n";
    std::cout << "Results will be compared to the text's pre-order method output. \n\n";

    for (int i = 0; i < testPool.size(); ++i) {
        IntBinaryTree tree;
        for (int num : testPool[i]) { tree.insert(num); }

        std::cout << "Test Case " << (i + 1) << "\n";
        std::cout << "  Pre-Order Display: ";
        tree.showPreOrder();
        std::cout << "\n";
        std::cout << "  Tree Print Method: ";
        tree.treePrint();
        std::cout << "\n\n";
    }

    return 0;
}