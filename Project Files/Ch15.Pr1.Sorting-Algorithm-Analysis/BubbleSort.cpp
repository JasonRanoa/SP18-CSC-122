//
// Created by TheLoneWoof on 2/11/18.
//

#include "BubbleSort.h"

void BubbleSort::sort(int nlist[], int size) {
    int temp;
    bool hasSwaps;

    do {
        hasSwaps = false;
        for (int i = 0; i < size - 1; i++) {
            if (compare(nlist[i], nlist[i + 1])) {
                hasSwaps = true;
                temp = nlist[i];
                nlist[i] = nlist[i + 1];
                nlist[i + 1] = temp;
            }
        }
    } while (hasSwaps);
}
