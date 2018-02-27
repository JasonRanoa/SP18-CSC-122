//
// Created by TheLoneWoof on 2/22/18.
//

#ifndef CH16_PR9_SORTABLEVECTOR_CLASS_TEMPLATE_SORTABLEVECTOR_H
#define CH16_PR9_SORTABLEVECTOR_CLASS_TEMPLATE_SORTABLEVECTOR_H

// Header file copied from book example, per requirement.
#include "SimpleVector.h"

template <class T>
class SortableVector : public SimpleVector<T> {

public:
    SortableVector(int size) : SimpleVector<T>(size) {} // Constructor
    SortableVector(const SortableVector &v) : SimpleVector<T>(v) {}
    void sort();

};

template <class T>
void SortableVector<T>::sort() {
    T min_val;
    int min_idx;

    for (int i = 0; i < this->arraySize; i++) {
        min_idx = i;
        min_val = this->aptr[i];
        // Getting smallest value.
        for (int j = i + 1; j < this->arraySize; j++) {
            if (this->aptr[j] < min_val) {
                min_idx = j;
                min_val = this->aptr[j];
            }
        }
        // Swapping if smallest value is not
        // in the beginning.
        if (min_val != (this->aptr)[i]) {
            std::swap(this->aptr[min_idx], this->aptr[i]);
        }
    }
}

#endif //CH16_PR9_SORTABLEVECTOR_CLASS_TEMPLATE_SORTABLEVECTOR_H
