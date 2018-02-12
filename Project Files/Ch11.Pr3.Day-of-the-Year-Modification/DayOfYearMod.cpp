//
// Created by TheLoneWoof on 2/6/18.
//

#include <iostream>
#include "DayOfYearMod.h"

const int DayOfYearMod::dayMax = 365;
const int DayOfYearMod::numMonths = 12;

// One-based indexing. January = 1.
// Assuming no leap years.
int DayOfYearMod::daysPerMonth[DayOfYearMod::numMonths + 1] = {
        0,
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
};

std::string DayOfYearMod::monthNames[DayOfYearMod::numMonths + 1] = {
        "",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
};

// Constructors

DayOfYearMod::DayOfYearMod(int num) {
    numDay = 0;
    addToDay(num); // This function allows for out-of-range values.
}

// Constructor delegated
DayOfYearMod::DayOfYearMod() : DayOfYearMod(1) { }

// PRIVATE METHODS

void DayOfYearMod::extractDetails() {
    int temp = numDay;
    for (int i = 1; i <= numMonths; i++) {
        temp = temp - daysPerMonth[i];
        if (temp <= 0) {
            numMonth = i;
            month = monthNames[i];
            dayOfMonth = temp + daysPerMonth[i];
            break;
        }
    }
}

void DayOfYearMod::addToDay(int plus) {
    this->numDay = (this->numDay + plus) % DayOfYearMod::dayMax;
    // If r == 0, then the day is the max day.
    if (this->numDay == 0) this->numDay = DayOfYearMod::dayMax;
    this->extractDetails();
}

// PUBLIC METHODS

bool DayOfYearMod::isInRange(int val) {
    if (val > 0 && val <= dayMax) {
        return true;
    } else return false;
}

void DayOfYearMod::setDay(const int val) {
    if (!isInRange(val)) {
        std::cout << "Day not in range.";
        exit(-1);
    }
    numDay = val;
    extractDetails();
}

void DayOfYearMod::print() {
    std::cout << month << " " << dayOfMonth;
}

// OVERLOADED OPERATORS

// Prefix Increment
DayOfYearMod& DayOfYearMod::operator++() {
    this->addToDay(1);
    return *this;
}

// Postfix Increment
// This postfix operator functions the same as the default
// postfix operator, meaning that a copy of the object is
// returned and the current object is incremented.
DayOfYearMod DayOfYearMod::operator++(int) {
    DayOfYearMod copy(*this);
    this->addToDay(1);
    return copy;
}

// Prefix Decrement
DayOfYearMod& DayOfYearMod::operator--() {
    this->addToDay(-1);
    return *this;
}

// Postfix Decrement
// See note on postfix increment.
DayOfYearMod DayOfYearMod::operator--(int) {
    DayOfYearMod copy(*this);
    this->addToDay(-1);
    return copy;
}

// Output stream operator
std::ostream& operator<<(std::ostream& out, const DayOfYearMod& d) {
    out << d.month << " " << d.dayOfMonth;
    return out;
}



