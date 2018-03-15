//
// Created by TheLoneWoof on 3/15/18.
//

#ifndef CH18_PR10_BALANCED_PARENTHESIS_DELIMITERTESTER_H
#define CH18_PR10_BALANCED_PARENTHESIS_DELIMITERTESTER_H

#include <string>
#include <vector>
#include <stack>

class DelimiterTester {

private:
    static unsigned const nBracketTypes;
    static char startingBrackets[];
    static char endingBrackets[];

    int findStartBracket(char);
    int findEndBracket(char);

public:
    DelimiterTester() {}
    bool testString(std::string);
};


#endif //CH18_PR10_BALANCED_PARENTHESIS_DELIMITERTESTER_H
