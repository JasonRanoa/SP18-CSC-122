//
// Created by TheLoneWoof on 2/27/18.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    ptr = nullptr;
}

void LinkedList::add(double x) {
    // Adds it in front of the list.
    ptr = new ListNode(x, ptr);
}

bool LinkedList::isMember(double x) {
    ListNode *temp_ptr;
    bool isFound = false;

    temp_ptr = ptr;
    while (temp_ptr) {
        if (temp_ptr->value == x) {
            isFound = true;
            break;
        }
        temp_ptr = temp_ptr->next;
    }

    temp_ptr = nullptr;
    return isFound;
}
int LinkedList::countMember(double x) {
    ListNode *temp_ptr;
    int count = 0;

    temp_ptr = ptr;
    while (temp_ptr) {
        if (temp_ptr->value == x) {
            count++;
        }
        temp_ptr = temp_ptr->next;
    }

    temp_ptr = nullptr;
    return count;
}
