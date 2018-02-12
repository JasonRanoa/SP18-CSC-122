//
// Created by TheLoneWoof on 2/9/18.
//

#ifndef CH11_PR4_NUM_DAYS_WORKED_NUMDAYS_H
#define CH11_PR4_NUM_DAYS_WORKED_NUMDAYS_H

#include <iostream>

class NumDays {

public:
    static const int hoursPerDay;

private:
    int hours;
    double days;

    void calcDays();

public:
    NumDays();
    NumDays(int);

    int getHours() const { return hours; };
    double getDays() const { return days; };
    void setHours(const int);
    void addHours(const int);

    // All variants of addition
    friend NumDays operator+(NumDays, const NumDays&);
    friend NumDays operator+(int, NumDays);
    friend NumDays operator+(NumDays, int);
    NumDays& operator+=(const NumDays&);
    NumDays& operator+=(const int);

    // All variants of subtraction
    friend NumDays operator-(NumDays, const NumDays&);
    friend NumDays operator-(int, NumDays);
    friend NumDays operator-(NumDays, int);
    NumDays& operator-=(const NumDays&);
    NumDays& operator-=(const int);

    // Printing because I'm lazy. lol
    friend std::ostream& operator<<(std::ostream&, const NumDays&);
};


#endif //CH11_PR4_NUM_DAYS_WORKED_NUMDAYS_H
