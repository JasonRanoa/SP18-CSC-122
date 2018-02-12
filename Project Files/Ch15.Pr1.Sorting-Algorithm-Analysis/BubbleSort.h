//
// Created by TheLoneWoof on 2/11/18.
//

#ifndef CH15_PR1_SORTING_ALGORITHM_ANALYSIS_BUBBLESORT_H
#define CH15_PR1_SORTING_ALGORITHM_ANALYSIS_BUBBLESORT_H

#include "AbstractSort.h"

class BubbleSort final : public AbstractSort {

public:
    std::string ALGORITHM_NAME() {
        return "Bubble Sort";
    };
    void sort(int[ ], int);

};


#endif //CH15_PR1_SORTING_ALGORITHM_ANALYSIS_BUBBLESORT_H
