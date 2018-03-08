//
// Created by TheLoneWoof on 3/8/18.
//

#ifndef EXAM_MIDTERM_LINKEDLIST_H
#define EXAM_MIDTERM_LINKEDLIST_H

#include <iostream>

// TEMPLATE DEFINITION

template <class T>
class LinkedList {

private:
    struct ListItem {
        T value;
        ListItem * next;
        ListItem(T val, ListItem * ptr) {
            value = val;
            next = ptr;
        }
    };
    ListItem * firstItem;

public:
    LinkedList() {
        firstItem = nullptr;
    }

    // Objective 1. Add, Remove, and Print.
    void addItem(T val);
    T popItem();
    void print();

    // Objective 2. Insert at position method.
    void insertAtPos(T, unsigned);
};

// IMPLEMENTATION

template <class T>
void LinkedList<T>::addItem(T val) {
    firstItem = new ListItem(val, firstItem);
}

template <class T>
T LinkedList<T>::popItem() {
    // Pop the item in front of the list.
    ListItem * tempReference;
    T poppedItem;

    // Make duplicates of the first item.
    tempReference = firstItem;
    poppedItem = firstItem->value;

    // Fix the list.
    firstItem = firstItem->next;
    tempReference->next = nullptr;
    delete tempReference;

    return poppedItem;
}

template <class T>
void LinkedList<T>::print() {
    ListItem * temp;
    temp = firstItem;
    while (temp) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
}

template <class T>
void LinkedList<T>::insertAtPos(T item, unsigned index) {
    if (index == 0) {
        // If index == 0, then add item to the beginning.
        addItem(item);
    } else {
        // If index > 1, then insert item between lists.
        ListItem * prevItem, * currItem, * newItem;
        int i = 1;

        prevItem = firstItem;
        currItem = firstItem->next;
        // Loop through i or until last of list.
        while (i < index && currItem) {
            i++;
            prevItem = currItem;
            currItem = currItem->next;
        }

        // Insert item.
        newItem = new ListItem(item, currItem);
        prevItem->next = newItem;

        // Dereference the pointers.
        newItem = nullptr;
        prevItem = nullptr;
        currItem = nullptr;
    }
}


#endif //EXAM_MIDTERM_LINKEDLIST_H
