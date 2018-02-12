//
// Created by TheLoneWoof on 2/11/18.
//

#ifndef CH15_PR1_SORTING_ALGORITHM_ANALYSIS_ABSTRACTSORT_H
#define CH15_PR1_SORTING_ALGORITHM_ANALYSIS_ABSTRACTSORT_H

#include <string>

/*
 * All the sorting algorithms derived from this class
 * can only sort integer values.
 * This restriction is produced from the req. that
 * that class should have the following method.
 *     void sort(int arr[ ], int size)
 */

class AbstractSort {

protected:
    int nComparisons;
    // This function cannot be re-defined.
    bool const compare(int, int);

public:
    AbstractSort() {
        nComparisons = 0;
    }

    virtual void sort(int[ ], int) = 0;
    virtual std::string ALGORITHM_NAME() = 0;

    int const getComparisons() const {
        return nComparisons;
    };
    void const reset() {
        nComparisons = 0;
    }
};


#endif //CH15_PR1_SORTING_ALGORITHM_ANALYSIS_ABSTRACTSORT_H
