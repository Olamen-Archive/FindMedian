//
// Created by Zixuan on 2/10/20.
//

#include "stdbool.h"
#include "assert.h"

#include "function.h"
#include "test.h"

/*
 * a function that test if given median in parameters list is
 * the median of array arr.
 * Notice the function also assume every element in arr is unique
 * and arr has odd number of elements.
 */
bool isMedian(int arr[], int length, int median) {
    assert(length % 2 != 0);

    int scount = 0; // counter for element that smaller than median
    int bcount = 0;

    for (int i = 0; i < length; i++) {
        assert(arr[i] != median);
        if (arr[i] > median) {
            bcount += 1;
        } else {
            // when arr[i] < median
            scount += 1;
        }
    }

    return scount == bcount;
}


