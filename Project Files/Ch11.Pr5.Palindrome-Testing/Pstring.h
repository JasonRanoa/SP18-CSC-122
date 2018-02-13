//
// Created by TheLoneWoof on 2/9/18.
//

#ifndef CH11_PR5_PALINDROME_TESTING_PSTRING_H
#define CH11_PR5_PALINDROME_TESTING_PSTRING_H

#include <string>

// This derived class is not complete.
// Overloaded operators are not included

class Pstring : public std::string {

private:
    bool statusPalindrome;
    void determineStatus();

public:
    Pstring();
    Pstring(std::string);

    bool isPalindrome() const {
        return statusPalindrome;
    };
};

#endif //CH11_PR5_PALINDROME_TESTING_PSTRING_H
