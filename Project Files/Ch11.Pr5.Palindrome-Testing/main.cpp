#include <iostream>
#include "Pstring.h"
using namespace std;

int main() {
    Pstring p("abcd");
    Pstring pone("abcba");

    cout << p << " " << p.isPalindrome() << "\n";
    cout << pone << " " << pone.isPalindrome() << "\n";

    return 0;
}