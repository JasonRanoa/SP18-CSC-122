//
// Created by TheLoneWoof on 5/1/18.
//

#ifndef FINAL_EXAM_BINARYTREE_H
#define FINAL_EXAM_BINARYTREE_H

#include <memory> // For the shared pointers.
#include <vector> // For the iterator.
#include <iostream>

/*
 *  This is a copy of the template class that I made for
 *  Chapter 19 Programming Challenge 8 EmployeeTree.
 *  The only modifications I made was that I added four
 *  methods to generate an iterator for the pre-order
 *  and post-order traversals.
 *
 */

/*
 *  NOTE: This is a limited implementation of a binary tree class.
 *        Other functions that are not included such as node deletion
 *        were not needed to fulfill the programming challenge.
 */

template <class T>
class BinaryTree {

private:
    struct TreeNode {
        std::shared_ptr<T> value;
        TreeNode * left;
        TreeNode * right;

        TreeNode(
                std::shared_ptr<T> argValPtr,
                TreeNode * argLeft = nullptr,
                TreeNode * argRight = nullptr) {
            value = argValPtr;
            left = argLeft;
            right = argRight;
        }
    };
    TreeNode * root;

    // Private Methods
    void insert(TreeNode * &, std::shared_ptr<T>);
    void destroySubTree(TreeNode *);

public:
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {
        destroySubTree(root);
    }

    bool search(const T, T&) const;
    std::shared_ptr<T> extract(T) const;
    void insert(T item);

// ITERATOR STUFF
public:
    /*
     * NOTE:
     * A basic iterator is added, just because I wanted to make one.
     * THIS DOES NOT HAVE THE FULL CAPABILITY OF AN STL ITERATOR.
     * ONLY THE METHODS NEEDED TO MAKE THE DRIVER PROGRAM RUN ARE ADDED.
     */
    class Iterator {

    private:
        std::vector< std::shared_ptr<T> > objPointers;
        unsigned maxIndex;
        unsigned currentIndex;

        // This function is friended by the Binary Tree class
        void addPointer(std::shared_ptr<T> newItem) {
            objPointers.push_back(newItem);
            maxIndex++;
        }

    public:
        Iterator() {
            maxIndex = 0;
            currentIndex = 0;
        }
        friend class BinaryTree; // Allows the binary tree to access the pointer vector.

        bool good() {
            return ( currentIndex >= 0 ) && ( currentIndex < maxIndex );
        }
        std::shared_ptr<T> current() {
            if (currentIndex < maxIndex) {
                return objPointers[currentIndex];
            } else {
                return nullptr;
            }
        }
        void reset() {
            currentIndex = 0;
        }

        // Deferencing Operators
        T& operator*() {
            return *(objPointers[currentIndex]);
        }
        const T& operator*() const {
            return *(objPointers[currentIndex]);
        }
        std::shared_ptr<T> operator->() {
            return objPointers[currentIndex];
        }
        const std::shared_ptr<T> operator->() const {
            return objPointers[currentIndex];
        }

        // Increment Operators

        Iterator& operator++() {
            currentIndex++; // Overflows are handled by current() method
            return *this;
        }
        Iterator& operator++(int) {
            currentIndex++; // There's no difference between post and pre
            // in this implementation.
            return *this;
        }

        // Conversion Operators
        operator std::shared_ptr<T>() const {
            if (currentIndex < maxIndex) {
                return objPointers[currentIndex];
            } else {
                return nullptr;
            }
        }
        operator T * () const {
            if (currentIndex < maxIndex) {
                return objPointers[currentIndex];
            } else {
                return nullptr;
            }
        };

    };

// BinaryTree Iterator Generators
private:
    void addInOrderIterator(TreeNode * tree, BinaryTree<T>::Iterator & i);
    void addPreOrderIterator(TreeNode * tree, BinaryTree<T>::Iterator & i);
    void addPostOrderIterator(TreeNode * tree, BinaryTree<T>::Iterator & i);

public:
    BinaryTree<T>::Iterator getInOrderIterator() {
        BinaryTree<T>::Iterator i;
        addInOrderIterator(root, i);
        return i;
    }
    BinaryTree<T>::Iterator getPreOrderIterator() {
        BinaryTree<T>::Iterator i;
        addPreOrderIterator(root, i);
        return i;
    }
    BinaryTree<T>::Iterator getPostOrderIterator() {
        BinaryTree<T>::Iterator i;
        addPostOrderIterator(root, i);
        return i;
    }

};

// Templates

// PRIVATE METHODS

template <class T>
void BinaryTree<T>::insert(TreeNode *& tree, std::shared_ptr<T> newItem) {
    // If tree is empty.
    if (!tree) {
        tree = new TreeNode(newItem);
        return;
    }

    // If value is already in tree.
    if (*tree->value == *newItem) {
        return; // Do nothing.
    }

    if (*newItem < *tree->value) {
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
        if (*(tree->value) == searchTerm) {
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


template <class T>
std::shared_ptr<T> BinaryTree<T>::extract(const T searchTerm) const {
    TreeNode * tree = root;
    while (tree) {
        if (searchTerm == *(tree->value)) {
            return tree->value;
        } else if (searchTerm < *(tree->value)) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return nullptr;
}

template <class T>
void BinaryTree<T>::insert(T item) {
    insert(root, std::make_shared<T>(item));
}

// BinaryTree Iterator InOrder Generator -- Implementation
template <class T>
void BinaryTree<T>::addInOrderIterator(TreeNode * tree, BinaryTree<T>::Iterator & i) {
    if (tree) {
        addInOrderIterator(tree->left, i);
        i.addPointer(tree->value);
        addInOrderIterator(tree->right, i);
    }
}

// BinaryTree Iterator PreOrder Generator -- Implementation
template <class T>
void BinaryTree<T>::addPreOrderIterator(TreeNode * tree, BinaryTree<T>::Iterator & i) {
    if (tree) {
        i.addPointer(tree->value);
        addPreOrderIterator(tree->left, i);
        addPreOrderIterator(tree->right, i);
    }
}

// BinaryTree Iterator PostOrder Generator -- Implementation
template <class T>
void BinaryTree<T>::addPostOrderIterator(TreeNode * tree, BinaryTree<T>::Iterator & i) {
    if (tree) {
        addPostOrderIterator(tree->left, i);
        addPostOrderIterator(tree->right, i);
        i.addPointer(tree->value);
    }
}



#endif //FINAL_EXAM_BINARYTREE_H
