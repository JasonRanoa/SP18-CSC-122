#include <iostream>
#include <random>

// Definitions
template<class T> T min(T, T);
template<class T> T max(T, T);

int main() {
    int a, b;
    double ax, bx;

    // Test case
    a = 123;
    b = 234;

    ax = 123.5;
    bx = 123.7;

    std::cout << "Testing two integers, " << a << " and " << b << ": \n";
    std::cout << "The smaller is " << min(a, b) << "\n";
    std::cout << "The larger is " << max(a, b) << "\n\n";

    std::cout << "Testing two doubles, " << ax << " and " << bx << ": \n";
    std::cout << "The smaller is " << min(ax, bx) << "\n";
    std::cout << "The larger is " << max(ax, bx) << "\n";

    return 0;
}

// Implementation

template<class T> T min(T t1, T t2) {
    if (t1 < t2) {
        return t1;
    } else {
        return t2;
    }
}

template<class T> T max(T t1, T t2) {
    if (t1 > t2) {
        return t1;
    } else {
        return t2;
    }
}