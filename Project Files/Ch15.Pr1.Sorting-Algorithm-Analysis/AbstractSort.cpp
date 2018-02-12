//
// Created by TheLoneWoof on 2/11/18.
//

#include "AbstractSort.h"

/*
 * This method accepts two integer arguments.
 * It returns true if the first is larger
 * than the second.
 */
bool const AbstractSort::compare(int a, int b) {
    nComparisons++;
    if (a > b) {
        return true;
    } else {
        return false;
    }
}