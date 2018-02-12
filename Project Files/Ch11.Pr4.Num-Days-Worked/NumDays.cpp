//
// Created by TheLoneWoof on 2/9/18.
//

#include <iomanip>
#include "NumDays.h"

// Calculation-relevant members and methods.

const int NumDays::hoursPerDay = 8;

void NumDays::calcDays() {
    days = static_cast<double>(hours) / hoursPerDay;
}

// Constructors

NumDays::NumDays(int h) {
    setHours(h);
}

NumDays::NumDays() : NumDays(0) { }

// Setters

void NumDays::setHours(const int h) {
    hours = ( h >= 0 ) ? h : 0;
    calcDays();
}

void NumDays::addHours(int hx) {
    hours += hx;
    if (hours < 0) hours = 0;
    calcDays();
}

// Addition Operations

NumDays operator+(NumDays n1, const NumDays& n2) {
    n1.addHours( n2.getHours() );
    return n1;
}

NumDays operator+(NumDays n1, int n2) {
    n1.addHours(n2);
    return n1;
}

NumDays operator+(int n1, NumDays n2) {
    n2.addHours(n1);
    return n2;
}

NumDays& NumDays::operator+=(const NumDays& n2) {
    this->addHours( n2.getHours() );
    return *this;
}

NumDays& NumDays::operator+=(const int n2) {
    this->addHours( n2 );
    return *this;
}

// Subtraction Operations

NumDays operator-(NumDays n1, const NumDays& n2) {
    n1.addHours( -n2.getHours() );
    return n1;
}

NumDays operator-(NumDays n1, int n2) {
    n1.addHours(-n2);
    return n1;
}

NumDays operator-(int n1, NumDays n2) {
    n2.addHours(-n1);
    return n2;
}

NumDays& NumDays::operator-=(const NumDays& n2) {
    this->addHours( -n2.getHours() );
    return *this;
}

NumDays& NumDays::operator-=(const int n2) {
    this->addHours( -n2 );
    return *this;
}

// Stream insertion operator.

std::ostream& operator<<(std::ostream& out, const NumDays& nx) {
    static std::ios state(NULL);
    state.copyfmt(out);
    out << std::showpoint << std::fixed << std::setprecision(2);
    out << nx.getDays() << " day" << (nx.getDays() == 1 ? "" : "s");
    out.copyfmt(state); // Removes iomanip formatting.
    return out;
}