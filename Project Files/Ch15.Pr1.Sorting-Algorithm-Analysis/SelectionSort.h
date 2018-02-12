//
// Created by TheLoneWoof on 2/11/18.
//

#ifndef CH15_PR1_SORTING_ALGORITHM_ANALYSIS_SELECTIONSORT_H
#define CH15_PR1_SORTING_ALGORITHM_ANALYSIS_SELECTIONSORT_H

#include "AbstractSort.h"

class SelectionSort final : public AbstractSort {

public:
    std::string ALGORITHM_NAME() {
        return "Selection Sort";
    };
    void sort(int[ ], int);

};


#endif //CH15_PR1_SORTING_ALGORITHM_ANALYSIS_SELECTIONSORT_H
