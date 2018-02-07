//
// Created by TheLoneWoof on 2/6/18.
//

#ifndef CH11_PR1_CHECK_WRITING_NUMBERS_H
#define CH11_PR1_CHECK_WRITING_NUMBERS_H

#include <string>

class Numbers {

    // Min and Max Definition.
    static const int min;
    static const int max;

    // Int to Text Conversions. Values in Implementation.
    static std::string lessThan20[ ];
    static std::string tens[ ];
    static std::string hundred;
    static std::string thousand;

private:
    int number;
    std::string text;
    std::string stringify(int);

public:
    Numbers();
    Numbers(int);
    bool isInRange(const int&);

    void print();
    std::string getText();
    void setNumber(const int);

};


#endif //CH11_PR1_CHECK_WRITING_NUMBERS_H
