//
// Created by TheLoneWoof on 4/5/18.
//

#include <iostream>
#include "BinaryTree.h"

// CLEANING UP. Destroying subtrees.

void BinaryTree::destroySubTree(TreeNode * tree) {
    if (!tree) return;
    destroySubTree(tree->left);
    destroySubTree(tree->right);
    delete tree;
}

/*
 *    Programming Challenge 1A
 *    An insert function that does not use recursion,
 *    directly or indirectly by calling a recursive function.
 *
 */

void BinaryTree::insert(double x) {
    /*
     *     This implementation makes use to pointers to pointers,
     *     indicated by the **. This works but there's another way of
     *     doing it that's much easier.

    TreeNode ** ptrToNodePtr = &root;

    while (*ptrToNodePtr) {
        if ((**ptrToNodePtr).value == x) {
            return; // Do nothing.
        } else if (x < (**ptrToNodePtr).value) {
            ptrToNodePtr = &((**ptrToNodePtr).left);
        } else {
            ptrToNodePtr = &((**ptrToNodePtr).right);
        }
    }

    *ptrToNodePtr = new TreeNode(x);

     */

    // If tree node is empty...
    TreeNode * newNode = new TreeNode(x);
    if (!root) {
        root = newNode;
    } else {
        // If the tree node is not empty, we can just append the new item by
        // changing the value of the left/right pointer.
        TreeNode *currentNode, *oneAfter;
        currentNode = oneAfter = root;
        // We have two variables here: (1) currentNode, and
        // (2) oneAfter -- which is just used to test for nullptr (i.e. insertion points)
        while (currentNode->value != x && oneAfter != nullptr) {
            currentNode = oneAfter;
            if (x < currentNode->value) {
                oneAfter = currentNode->left;
            } else {
                oneAfter = currentNode->right;
            }
        }

        if (currentNode->value == x) return;
        else if (x < currentNode->value) {
            currentNode->left = newNode;
        } else {
            currentNode->right = newNode;
        }
        // Do note that we can't assign newNode to oneAfter
        // since doing so wouldn't affect the node on the tree.
    }

    return;
}

/*
 *    Programming Challenge 1B
 *    Create a search function that works by calling a private
 *    recursive function.
 *
 */

// Public Member Function
bool BinaryTree::search(double x) {
    return search(x, root);
}

// Private Member Function -- Recursive
bool BinaryTree::search(double x, TreeNode * tree) {
    if (!tree) {
        return false; // Found end of tree but no match.
    } else if (tree->value == x) {
        return true;
    } else if (x < tree->value) {
        return search(x, tree->left);
    } else {
        return search(x, tree->right);
    }
}

/*
 *     Programming Challenge 1C
 *     Create an in-order function that accepts an empty vector and fills
 *     it with the in-order list of numbers in the tree.
 *
 */

void BinaryTree::inorder(std::vector<double> & v) {
    attachinorder(v, root);
}

void BinaryTree::attachinorder(std::vector<double> & v, TreeNode * tree) {
    if (tree) {
        attachinorder(v, tree->left);
        v.push_back(tree->value);
        attachinorder(v, tree->right);
    }
}

/*
 *    Programming Challenge 2
 *    Get the size of the tree.
 *
 */

void BinaryTree::countNodes(int & count, TreeNode * tree) {
    if (!tree) return;
    else {
        count++;
        countNodes(count, tree->left);
        countNodes(count, tree->right);
    }
}

int BinaryTree::size() {
    int count = 0;
    countNodes(count, root);
    return count;
}

/*
 *    Programming Challenge 3
 *    Count the number of leaf nodes (i.e. nodes with no children) on the
 *    tree. In this implementation, two methods are used -- A public method
 *    and a private one for recursion.
 *
 */

void BinaryTree::countLeaves(int & leafCount, TreeNode * tree) {
    if (!tree) return;
    else if (!tree->left && !tree->right) {
        leafCount++;
    } else {
        countLeaves(leafCount, tree->left);
        countLeaves(leafCount, tree->right);
    }
}

int BinaryTree::leafCount() {
    int nLeaves = 0;
    countLeaves(nLeaves, root);
    return nLeaves;
}

/*
 *    Programming Challenge 4
 *    The height of tree is the number of levels it contains.
 *
 */

int BinaryTree::height() {
    std::vector<TreeNode *> currentLevel;
    std::vector<TreeNode *> nextLevel;
    int height = 0;

    // Start the count.
    if (root) currentLevel.push_back(root);

    // Children nodes.
    while (currentLevel.size() > 0) {
        height++;
        for (TreeNode * tree : currentLevel) {
            if (tree->left) nextLevel.push_back(tree->left);
            if (tree->right) nextLevel.push_back(tree->right);
        }
        currentLevel = nextLevel;
        nextLevel.clear();
    }

    return height;
}

/*
 *    Programming Challenge 5
 *    The width of a tree is the largest number of nodes at the same level.
 *
 */

int BinaryTree::width() {
    std::vector<TreeNode *> currentLevel;
    std::vector<TreeNode *> nextLevel;
    int width = 0;

    // Start the count.
    if (root) currentLevel.push_back(root);

    // Children nodes.
    while (currentLevel.size() > 0) {
        width = ( width > currentLevel.size() ) ? width : currentLevel.size();
        for (TreeNode * tree : currentLevel) {
            if (tree->left) nextLevel.push_back(tree->left);
            if (tree->right) nextLevel.push_back(tree->right);
        }
        currentLevel = nextLevel;
        nextLevel.clear();
    }

    return width;
}

/*
 *    Programming Challenge 6
 *    Implement a tree copy constructor.
 *
 */

BinaryTree::BinaryTree(const BinaryTree & copy) {
    root = duplicateNode(copy.root);
}

BinaryTree::TreeNode * BinaryTree::duplicateNode(const TreeNode * source) {
    if (!source) return nullptr;
    return new TreeNode(
        source->value,
        ( source->left ) ? duplicateNode(source->left) : nullptr,
        ( source->right ) ? duplicateNode(source->right) : nullptr
    );
}

/*
 *    Programming Challenge 7
 *    Implement an overloaded copy constructor.
 *
 */

BinaryTree & BinaryTree::operator=(const BinaryTree & source) {
    destroySubTree(root); // Just to cover my bases.
    root = duplicateNode(source.root);
    return *this;
}

