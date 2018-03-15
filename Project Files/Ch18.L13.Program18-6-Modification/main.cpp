// This program demonstrates the DynIntQeue class
#include <iostream>
#include "DynIntQueue.h"
using namespace std;

int main()
{
    DynIntQueue iQueue;

    cout << "Testing for underflow... \n";
    cout << "Enqueuing 5 items...\n";

    // Enqueue 5 items
    for (int k = 1; k <= 5; k++)
        iQueue.enqueue(k*k);

    cout << "The first six values in the queue were: \n";
    for (int i = 0; i < 6; i++) {
        try {
            int value;
            iQueue.dequeue(value);
            cout << value << "  ";
        } catch(DynIntQueue::Underflow& e) {
            cout << "[ Error: Queue is empty. ] ";
        }
    }

    cout << "\n";

    return 0;
}