//
// Created by TheLoneWoof on 2/27/18.
//

#ifndef CH17_PR1_SIMPLE_LINKED_LIST_CLASS_LINKEDLIST_H
#define CH17_PR1_SIMPLE_LINKED_LIST_CLASS_LINKEDLIST_H


class LinkedList {

private:
    struct ListNode {
        double value;
        ListNode *next;
        ListNode(double value1, ListNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    ListNode *ptr;

public:
    void add(double);
    bool isMember(double);
    int countMember(double);
    LinkedList();

};


#endif //CH17_PR1_SIMPLE_LINKED_LIST_CLASS_LINKEDLIST_H
