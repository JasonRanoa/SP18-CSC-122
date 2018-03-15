#include <iostream>
#include "DelimiterTester.h"

int main() {
    DelimiterTester dl;

    std::string positiveTests[] = {
        "if ( not [ lorem ipsum ] yes )",
        "[ Error. Brackets not found(). ]",
        "A ( B < class T template( help ) > ) {} object.",
        "template< class T > className { method(); method() }",
        "() () {} () < < > > { () }",
        "Lorem ipsum dolor amet."
    };

    for (std::string s : positiveTests) {
        if (dl.testString(s)) {
            std::cout << "Worked. \n";
        } else {
            std::cout << "Didn't work. \n";
        }
    }

    std::string negativeTests[] = {
        "if ( not }",
        "[ Error. Brackets not found. :( ]",
        "template< class T > className { method(); method(] }",
        "() () { {} > } }",
        "{ ( vector<int> } ) }",
        ")",
        "Woof... :("
    };

    for (std::string s : negativeTests) {
        if (!dl.testString(s)) {
            std::cout << "Worked. \n";
        } else {
            std::cout << "Didn't work. \n";
        }
    }

    return 0;
}