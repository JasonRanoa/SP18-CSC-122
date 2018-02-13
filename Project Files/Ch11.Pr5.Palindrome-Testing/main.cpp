#include <iostream>
#include "Pstring.h"
using namespace std;

int main() {
    Pstring ps[ ] = {
        Pstring("Mama"),
        Pstring("Racecar"),
        Pstring("Dad"),
        Pstring("Altema"),
        Pstring("Llonora")
    };
    int SIZE = sizeof(ps) / sizeof(ps[0]);

    for (int i = 0; i < SIZE; i++) {
        cout << ps[i] << " "
             << ( ps[i].isPalindrome() ? "is" : "is NOT" )
             << " a palindrome.\n";
    }

    return 0;
}