//
// Created by TheLoneWoof on 3/15/18.
//

#include "DelimiterTester.h"

// Controls
unsigned const DelimiterTester::nBracketTypes = 4;
char DelimiterTester::startingBrackets[DelimiterTester::nBracketTypes] = {
        '(', '{', '[', '<'
};
char DelimiterTester::endingBrackets[DelimiterTester::nBracketTypes] = {
        ')', '}', ']', '>'
};

// Private

// This method returns the index of the starting bracket.
// Returns -1 if not found.
int DelimiterTester::findStartBracket(char c) {
    int index = -1;
    for (int i = 0; i < nBracketTypes; i++) {
        if (c == startingBrackets[i]) {
            index = i;
            break;
        }
    }
    return index;
}

// This method returns the index of the ending bracket.
// Returns -1 if not found.
int DelimiterTester::findEndBracket(char c) {
    int index = -1;
    for (int i = 0; i < nBracketTypes; i++) {
        if (c == endingBrackets[i]) {
            index = i;
            break;
        }
    }
    return index;
}

// Public Methods

bool DelimiterTester::testString(std::string text) {
    std::stack<int> bracketIndexStack;
    char lastBracket, testEndBracket;
    bool isGood = false;

    for (char s : text) {
        // Find character in Starting Brackets
        int idx = findStartBracket(s);
        if (idx != -1) { // If first character is a starting bracket.
            bracketIndexStack.push(idx);
            lastBracket = startingBrackets[idx];
            testEndBracket = endingBrackets[idx];
        } else if (!bracketIndexStack.empty() && s == testEndBracket) {
            // If character is not a starting bracket and
            // the stack is not empty...
            bracketIndexStack.pop();
            if (!bracketIndexStack.empty()) {
                lastBracket = startingBrackets[bracketIndexStack.top()];
                testEndBracket = endingBrackets[bracketIndexStack.top()];
            }
        } else if (findEndBracket(s) != -1) {
            // If the stack is empty ...
            // ... and you've found an ending bracket.
            bracketIndexStack.push(-1);
            break;
        }
    }

    if (bracketIndexStack.empty()) {
        return true;
    } else {
        return false;
    }
}

