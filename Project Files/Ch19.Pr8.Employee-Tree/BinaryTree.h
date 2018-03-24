//
// Created by TheLoneWoof on 3/22/18.
//

#ifndef CH19_PR8_EMPLOYEE_TREE_BINARYTREE_H
#define CH19_PR8_EMPLOYEE_TREE_BINARYTREE_H

template <class T>
class BinaryTree {

private:
    struct TreeNode {
        T value;
        TreeNode * left;
        TreeNode * right;

        TreeNode(
                T argVal,
                TreeNode * argLeft = nullptr,
                TreeNode * argRight = nullptr) {
            value = argVal;
            left = argLeft;
            right = argRight;
        }
    };
    TreeNode * root;

    // Private Methods
    void insert(TreeNode * &, T);
    void destroySubTree(TreeNode *);

public:
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {
        destroySubTree(root);
    }

    bool search(const T, T&) const;
    void insert(T item) {
        insert(root, item);
    }


};

// Templates

// PRIVATE METHODS

template <class T>
void BinaryTree<T>::insert(TreeNode *& tree, T newItem) {
    // If tree is empty.
    if (!tree) {
        tree = new TreeNode(newItem);
        return;
    }

    // If value is already in tree.
    if (tree->value == newItem) {
        return; // Do nothing.
    }

    if (newItem < tree->value) {
        insert(tree->left, newItem);
    } else {
        insert(tree->right, newItem);
    }

    return;
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode * tree) {
    if (!tree) return;
    destroySubTree(tree->left);
    destroySubTree(tree->right);
    delete tree;
}

// PUBLIC METHODS

template <class T>
bool BinaryTree<T>::search(const T searchTerm, T & itemContainer) const {
    TreeNode * tree = root;
    while (tree) {
        if (tree->value == searchTerm) {
            itemContainer = tree->value;
            return true;
        } else if (searchTerm < tree->value) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return false;
}

#endif //CH19_PR8_EMPLOYEE_TREE_BINARYTREE_H
