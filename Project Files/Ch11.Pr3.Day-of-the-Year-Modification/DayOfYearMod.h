//
// Created by TheLoneWoof on 2/6/18.
//

#ifndef CH11_PR2_DAY_OF_THE_YEAR_DAYOFYEAR_H
#define CH11_PR2_DAY_OF_THE_YEAR_DAYOFYEAR_H

#include <string>
#include <iostream>

class DayOfYearMod {

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

    DayOfYearMod();
    DayOfYearMod(int);
    DayOfYearMod(std::string, int);
    void setDay(const int);

    bool isInRange(int);
    void addToDay(int);
    void print();

    // Overloaded Operators
    DayOfYearMod operator++(int);
    DayOfYearMod& operator++();

    DayOfYearMod operator--(int);
    DayOfYearMod& operator--();

    friend std::ostream& operator<<(std::ostream&, const DayOfYearMod&);
};


#endif //CH11_PR2_DAY_OF_THE_YEAR_DAYOFYEAR_H
