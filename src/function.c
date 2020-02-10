//
// Created by Zixuan on 2/10/20.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"

/*
 * The function return median of an array
 * As side effects, all elements smaller than median will be placed to the left-side of median, and all elements that
 * bigger than median will be placed to the right-side of median.
 */
int findMedian(int arr[], int length) {
    assert(length % 2 != 0); // make sure that array has odd length

    /* left and right bound of the search space */
    int lb = 0;
    int rb = length - 1;
    const int medianPos = length / 2; // position of median

    shuffle(arr, length); // shuffle the arr to ensure that the pivot is picked randomly

    while (lb < rb) {
        int pivotPos = partition(arr, lb, rb);
        if (pivotPos == medianPos) { // "binary" search
            return arr[pivotPos];
        } else if (pivotPos > medianPos) {
            rb = pivotPos - 1;
        } else {
            // pivotPos < medianPos
            lb = pivotPos + 1;
        }
    }

    return arr[lb];
}

/*
 * The first element of given array scope will be choose as pivot, i.e. arr[lb]. Then, all element that
 * smaller than pivot will be move to the left of pivot and elments that bigger than pivot will be move to
 * the right of move. The partition is in-place and will return the position of pivot.
 * lb and rb is inclusive.
 */
int partition(int arr[], int lb, int rb) {
    /* set first element as pivot and skip it */
    int indexOfPivot = lb;
    lb += 1;

    while (lb <= rb) {
        assert(arr[lb] != arr[indexOfPivot]); // assertion: element should be unique

        if (arr[lb] < arr[indexOfPivot]) {
            lb += 1;
        } else {
            // then arr[lb] > arr[pivot]
            swap(&arr[lb], &arr[rb]);
            rb -= 1;
        }
    }

    swap(&arr[indexOfPivot], &arr[rb]); // swap pivot to pos of rb
    return rb;
}

/*
 * Fisher–Yates shuffle
 */
void shuffle(int arr[], int length) {
    srand(time(0)); // use the current time as seed for rand

    for (int i = length-1; i >= 1; i--) { // no need for swap first element
        int j = rand() % (i+1); // choose an index between [0, i]
        swap(&arr[i], &arr[j]);
    }
}

/* to swap two integer */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}