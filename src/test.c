//
// Created by Zixuan on 2/10/20.
//

#include <assert.h>
#include <stdlib.h>

#include "function.h"
#include "test.h"

/*
 * a function that test if given median in parameters list is
 * the median of array arr.
 * Notice the function also assume every element in arr is unique
 * and arr has odd number of elements.
 */
int isMedian(int arr[], int length, int median) {
    assert(length % 2 != 0);

    int scount = 0; // counter for element that smaller than median
    int bcount = 0;

    for (int i = 0; i < length; i++) {
        //assert(arr[i] != median);
        if (arr[i] > median) {
            bcount += 1;
        } else if (arr[i] < median) {
            // when arr[i] < median
            scount += 1;
        }
    }

    return scount == bcount;
}

void generateArray(int** arr, int size) {
    assert(size %  2 != 0); // can only generate array with odd elements
    *arr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        (*arr)[i] = i; // ensure our generated array is half negative and half positive
    }

    shuffle(*arr, size);
}


