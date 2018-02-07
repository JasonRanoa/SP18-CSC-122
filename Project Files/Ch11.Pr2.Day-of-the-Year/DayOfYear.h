//
// Created by TheLoneWoof on 2/6/18.
//

#ifndef CH11_PR2_DAY_OF_THE_YEAR_DAYOFYEAR_H
#define CH11_PR2_DAY_OF_THE_YEAR_DAYOFYEAR_H

#include <string>

class DayOfYear {

public:
static const int dayMax;
static const int numMonths;
static int daysPerMonth[ ]; // One-based indexing. 1 = January
static std::string monthNames[ ];

private:
    int numDay; // -nth day of the year

    // Results
    int numMonth;
    std::string month;
    int dayOfMonth;

    void extractDetails();

public:
    DayOfYear();
    DayOfYear(int);

    void setDay(const int);
    bool isInRange(int);
    void print();


};


#endif //CH11_PR2_DAY_OF_THE_YEAR_DAYOFYEAR_H
