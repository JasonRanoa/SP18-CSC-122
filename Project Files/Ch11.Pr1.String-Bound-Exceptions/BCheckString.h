//
// Created by TheLoneWoof on 2/15/18.
//

#ifndef CH11_PR1_STRING_BOUND_EXCEPTIONS_BCHECKSTRING_H
#define CH11_PR1_STRING_BOUND_EXCEPTIONS_BCHECKSTRING_H

#include <string>

class BCheckString : public std::string {

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
    char operator[](int);
};


#endif //CH11_PR1_STRING_BOUND_EXCEPTIONS_BCHECKSTRING_H
