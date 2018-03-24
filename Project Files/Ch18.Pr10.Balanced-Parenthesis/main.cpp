#include <iostream>
#include "DelimiterTester.h"

int main() {
    DelimiterTester dl;

    // FALSE POSITIVE TESTS.
    std::string positiveTests[] = {
        "if ( not [ lorem ipsum ] yes )",
        "[ Error. Brackets not found(). ]",
        "A ( B < class T template( help ) > ) {} object.",
        "template< class T > className { method(); method() }",
        "() () {} () < < > > { () }",
        "Lorem ipsum dolor amet."
    };

    std::cout << "Testing for false positives: \n";
    std::cout << "Arguments should test positive. \n";
    for (std::string s : positiveTests) {
        if (dl.testString(s)) {
            std::cout << "  Tested positive for -- ";
        } else {
            std::cout << "  Tested negative for -- ";
        }
        std::cout << s << "\n";
    }
    std::cout << "\n";

    // FALSE NEGATIVE TESTS.
    // The following functions should return negative.
    std::string negativeTests[] = {
        "if ( not }",
        "[ Error. Brackets not found. :( ]",
        "template< class T > className { method(); method(] }",
        "() () { {} > } }",
        "{ ( vector<int> } ) }",
        ")",
        "Hi... :)"
    };

    std::cout << "Testing for false negatives: \n";
    std::cout << "Arguments should test negative. \n";
    for (std::string s : negativeTests) {
        if (!dl.testString(s)) {
            std::cout << "  Tested negative for -- ";
        } else {
            std::cout << "  Tested positive for -- ";
        }
        std::cout << s << "\n";
    }
    std::cout << "\n";

    return 0;
}