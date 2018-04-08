//
// Created by TheLoneWoof on 4/5/18.
//

#ifndef CH19_PR1_7_SIMPLE_BINARY_SEARCH_TREE_CLASS_BINARYTREE_H
#define CH19_PR1_7_SIMPLE_BINARY_SEARCH_TREE_CLASS_BINARYTREE_H

#include <vector>

class BinaryTree {

private:
    struct TreeNode {
        double value;
        TreeNode * left;
        TreeNode * right;

        TreeNode(
            double argVal,
            TreeNode * argLeft = nullptr,
            TreeNode * argRight = nullptr
        ) {
            value = argVal;
            left = argLeft;
            right = argRight;
        }
    };

    TreeNode * root;

    // Private Methods
    void destroySubTree(TreeNode *); // Cleans up dynamic memory allocation
    bool search(double x, TreeNode *);
    void attachinorder(std::vector<double> &, TreeNode *);
    void countNodes(int &, TreeNode *);
    void countLeaves(int &, TreeNode *);
    TreeNode * duplicateNode(const TreeNode *);

public:
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {
        destroySubTree(root);
    }

    void insert(double x); // Programming Challenge 1A.
    bool search(double x); // Programming Challenge 1B.
    void inorder(std::vector<double> &); // Programming Challenge 1C.
    int size(); // Programming Challenge 2
    int leafCount(); // Programming Challenge 3
    int height();// Programming Challenge 4
    int width(); // Programming Challenge 5

    // Programming Challenge 6 Tree Copy Constructor
    BinaryTree(const BinaryTree &);

    // Programming Challenge 7 Tree Assignment Constructor
    BinaryTree & operator=(const BinaryTree &);

};


#endif //CH19_PR1_7_SIMPLE_BINARY_SEARCH_TREE_CLASS_BINARYTREE_H
