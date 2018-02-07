//
// Created by TheLoneWoof on 2/6/18.
//

#include <iostream>
#include "DayOfYear.h"

const int DayOfYear::dayMax = 365;
const int DayOfYear::numMonths = 12;

// One-based indexing. January = 1.
// Assuming no leap years.
int DayOfYear::daysPerMonth[DayOfYear::numMonths + 1] = {
    0,
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

std::string DayOfYear::monthNames[DayOfYear::numMonths + 1] = {
    "",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};

// Constructors

DayOfYear::DayOfYear(int num) {
    if (!isInRange(num)) {
        std::cout << "Day not in range.";
        exit(-1);
    }
    numDay = num;
    extractDetails();
}

// Constructor delegated
DayOfYear::DayOfYear() : DayOfYear(1) {}

// PRIVATE METHODS

void DayOfYear::extractDetails() {
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

// PUBLIC METHODS

bool DayOfYear::isInRange(int val) {
    if (val > 0 && val <= dayMax) {
        return true;
    } else return false;
}

void DayOfYear::setDay(const int val) {
    if (!isInRange(val)) {
        std::cout << "Day not in range.";
        exit(-1);
    }
    numDay = val;
    extractDetails();
}

void DayOfYear::print() {
    std::cout << month << " " << dayOfMonth;
}