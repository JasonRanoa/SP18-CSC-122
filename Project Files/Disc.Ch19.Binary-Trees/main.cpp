// This program builds a binary tree with 5 nodes.
// The deleteNode function is used to remove 2 of them.
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
    IntBinaryTree tree;

    cout << "Inserting the numbers 5 8 3 12 9.\n";
    tree.insert(5);
    tree.insert(8);
    tree.insert(3);
    tree.insert(12);
    tree.insert(9);
    cout << "Inserting additional numbers, 2 4 6 13, to create two-children nodes.\n";
    // Adding the following numbers to create nodes with two children.
    // Nodes with two children are: 5, 3, 8, 12.
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(13);

    cout << "\nHere are the values in the tree:\n";
    tree.showInOrder();
    cout << "\nHere are the values in pre-order: \n";
    tree.showPreOrder();

    cout << "\n\nThe delete method has been altered to show \n";
    cout << "that the method is deleting a node with two children. \n";

    cout << "\nDeleting 8...\n";
    tree.remove(8);

    cout << "\nDeleting 12...\n";
    tree.remove(12);

    cout << "\nDeleting 3... \n";
    tree.remove(3);

    cout << "\nNow, here are the nodes:\n";
    tree.showInOrder();
    cout << "\nNow, here are the values in pre-order: \n";
    tree.showPreOrder();
    return 0;
}