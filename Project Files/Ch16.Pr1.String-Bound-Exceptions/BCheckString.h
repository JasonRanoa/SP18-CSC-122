//
// Created by TheLoneWoof on 2/15/18.
//

#ifndef CH11_PR1_STRING_BOUND_EXCEPTIONS_BCHECKSTRING_H
#define CH11_PR1_STRING_BOUND_EXCEPTIONS_BCHECKSTRING_H

#include <string>

class BCheckString : public std::string {

private:
    // This is a pointer to the first character,
    // since after overloading my own [] operator,
    // the string original [] operator gets
    // overwritten and is lost.
    char * firstChar;
    // Note that this only works after construction.
    // I haven't overwritten the = operators.

public:
    // Exception Class
    class BoundsException {
    private:
        int attemptedIndex;
    public:
        BoundsException(int idx) {
            attemptedIndex = idx;
        }
        int getErrorIndex() const {
            return attemptedIndex;
        };
    };

    BCheckString();
    BCheckString(std::string);
    ~BCheckString() {
        firstChar = nullptr;
    }
    char& operator[](int);
};


#endif //CH11_PR1_STRING_BOUND_EXCEPTIONS_BCHECKSTRING_H
