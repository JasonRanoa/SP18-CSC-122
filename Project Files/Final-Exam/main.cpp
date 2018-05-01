#include <iostream>
#include <fstream>
#include "BinaryTree.h"

void saveFile();
void readFile(int * &, int &);
void printFile(BinaryTree<int> *);

int main() {
    saveFile(); // Objectives 1 and 2
    int * numRead, length;
    readFile(numRead, length); // Objective 3

    /*
     *  Objective 4.
     *  (4) Create a binary tree data structure
     *      with the data in numRead[]
     *  A template binary class tree created for the
     *  Chapter 19 Programming Challenge 8
     *  was imported. It was also edited to include
     *  the iterators for pre-order and post-order.
     */
    BinaryTree<int> tree;
    for (int i = 0; i < length; ++i) {
        tree.insert(numRead[i]);
    }

    printFile(&tree);

    delete [] numRead;
    return 0;
}

/*
 *  The following method fulfills two objectives.
 *  (1) In your driver program, create an array of integers
 *      called numWrite[] with the following data:
 *      5, 8, 9, 2, 22, 16, 18, 1, 4, 21
 *  (2) Save this data into a binary file called numbers.dat
 *
 */
void saveFile() {
    std::fstream binFile("numbers.dat", std::ios::out | std::ios::binary);
    if (!binFile) {
        std::cout << "Cannot create file. \n";
        exit(-1);
    }

    int numWrite[] = {
        5, 8, 9, 2, 22, 16, 18, 1, 4, 21
    };
    int length = sizeof(numWrite) / sizeof(numWrite[0]);

    for (int i = 0; i < length; ++i) {
        binFile.write(
            reinterpret_cast<char *>(numWrite + i), sizeof(int)
        );
    }

    binFile.close();
}

/*
 *  The following method fulfills one objective.
 *  (3) Now, read this file into an array of integers called numRead[]
 *      ... the pointer of the array is passed to this function
 *
 */
void readFile(int * & arrayHead, int & size) {
    std::fstream binFile("numbers.dat", std::ios::in | std::ios::binary );
    if (!binFile) {
        std::cout << "Cannot open file. \n";
        exit(-2);
    }

    // First, find out how many integers are there.
    int length = 0, temp;
    while (binFile.good()) {
        binFile.read(
            reinterpret_cast<char *>(&temp), sizeof(int)
        );
        ++length;
    }
    --length;
    size = length;

    // Reset the cursor.
    binFile.clear();
    binFile.seekg(0, std::ios::beg);

    arrayHead = new int[length];
    for (int i = 0; i < length; ++i) {
        binFile.read(
                reinterpret_cast<char *>(&temp), sizeof(int)
        );
        arrayHead[i] = temp;
    }

    binFile.close();
}

/*
 *  The following method fulfills one objective.
 *  (5) Print out in a text file called numbers.txt
 *      the data contained in the binary tree using all 3
 *      methods: inorder, pre-order, post-order.
 *  Note that this function uses a template for the
 *  binary tree class. A header file is included.
 *
 */
void printFile(BinaryTree<int> * tree) {
    std::fstream numFile("numbers.txt", std::ios::out);
    if (!numFile) {
        std::cout << "Cannot create file. \n";
        exit(-3);
    }

    BinaryTree<int>::Iterator i;

    numFile << "InOrder: ";
    i = tree->getInOrderIterator();
    while (i.good()) {
        numFile << *i << " ";
        i++;
    }
    numFile << "\n";

    numFile << "PreOrder: ";
    i = tree->getPreOrderIterator();
    while (i.good()) {
        numFile << *i << " ";
        i++;
    }
    numFile << "\n";

    numFile << "PostOrder: ";
    i = tree->getPostOrderIterator();
    while (i.good()) {
        numFile << *i << " ";
        i++;
    }
    numFile << "\n";

    numFile.close();
}