//
// Created by TheLoneWoof on 2/6/18.
//

#include <iostream>
#include "Numbers.h"

// Number to Text Conversions - Reference
const int Numbers::min = 0;
const int Numbers::max = 9999;
std::string Numbers::lessThan20[ ] = {
        "zero",
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
};
std::string Numbers::tens[ ] = {
        "",
        "ten", "twenty", "thirty", "forty", "fifty",
        "sixty", "seventy", "eighty", "ninety"
};
std::string Numbers::hundred = "hundred";
std::string Numbers::thousand = "thousand";

// Default Constructor
Numbers::Numbers() {
    number = 0;
    text = stringify(number);
}

// Constructor. Accepts int as argument.
Numbers::Numbers(int val) {
    if (!Numbers::isInRange(val)) {
        std::cout << "Number not in range. Exiting program.";
        exit(-1);
    }
    number = val;
    text = stringify(val);
}

// Converts an int value as argument.
// Private function. Assumes value is in range.
std::string Numbers::stringify(int val) {
    if (val == 0) {
        return lessThan20[0];
    }

    std::string temp_str;
    int temp_int;

    // Tens
    temp_int = val % 100;
    if (temp_int < 20 && temp_int != 0) {
        temp_str = lessThan20[temp_int];
    } else {
        temp_str = tens[ temp_int / 10 ];
        temp_int = temp_int % 10;
        if (temp_int != 0) {
            temp_str += "-" + lessThan20[ temp_int % 10 ];
        }
    }

    // Hundred
    temp_int = val % 1000;
    temp_int = temp_int / 100; // Get the hundreds digit.
    if ( temp_int != 0 ) {
        temp_str = lessThan20[ temp_int ]
                   + " " + hundred + " " + temp_str;
    }

    // Thousand
    temp_int = val / 1000;
    if (temp_int != 0) {
        temp_str = lessThan20[temp_int] + " "
               + thousand + " " + temp_str;
    }

    return temp_str;
}

// Tests if value is in accepted range.
bool Numbers::isInRange(const int& val) {
    if (val < min) { return false; }
    else if (val > max ) { return false; }
    else return true;
}

// UX Functions

void Numbers::print() {
    std::cout << text;
}

void Numbers::setNumber(const int val) {
    if (!Numbers::isInRange(val)) {
        std::cout << "Number not in range. Exiting program.";
        exit(-1);
    }
    number = val;
    text = stringify(val);
}