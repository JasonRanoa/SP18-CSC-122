#include <iostream>
#include "LinkedList.h"

int main() {

    LinkedList ll;
    double test[] = { 3.14, 11.7, 6.022, 3.97, 3.14, 5.87, 3.14 };

    std::cout << "Adding members and testing for membership... \n";
    for (double x : test) {
        ll.add(x);
        std::cout << x << " is " << ( ll.isMember(x) ? "" : "NOT " )
                  << "a member of the linked list. \n";
    }
    std::cout << "\n";

    double test2[] = { 3.14, 11.8, 60.23, 3.98, 3.97 };
    std::cout << "Testing for membership... \n";
    for (double x : test2) {
        std::cout << x << " is " << ( ll.isMember(x) ? "" : "NOT " )
                  << "a member of the linked list. \n";
    }
    std::cout << "\n";

    double test3[] = { 3.43, 6.022, 3.14, 60.23 };
    std::cout << "Counting member duplicates... \n";
    for (double x : test3) {
        std::cout << x << " appears " << ll.countMember(x) << " time(s) "
                  << "in the linked list. \n";
    }

    return 0;
}