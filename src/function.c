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


/// partition
/// \param arr: array to be paritioned
/// \param lb: left bound of the part of array you want to be partitioned
/// \param rb: right bound of the part of array you want to be partitioned
/// \return the index of "pivot" in arr
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

/// shuffle
/// \param arr: array you want to shuffle
/// \param length: length of the array you want to shuffle
/*
 * This is an implementation of famous "fisher-yates" algorithm. The purpose of this shuffle algorithm
 * is to prevent the most case scenario, sorted array, from happening also, for non-random input, the
 * shuffle increase the chance of finding a pivot such that size of each subarray is close to each other.
 * This procedure return anything. As side effects, it will change the arr you passed in into a randomly
 * shuffled array.
 */
void shuffle(int arr[], int length) {
    srand(time(0)); // use the current time as seed for rand

    for (int i = length-1; i >= 1; i--) { // no need for swap first element
        int j = rand() % (i+1); // choose an index between [0, i]
        swap(&arr[i], &arr[j]);
    }
}

/// swap
/// \param a: pointer of an integer you want swap
/// \param b: pointer of an integer you want swap
/*
 * The procedure takes two pointers of integer type and swap the value of them. This procedure]
 * does not return anything as the integers are passed as pointer
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/// printArray
/// \param arr: the array to be printed
/// \param length: the length of array to be printed
/*
 * This is a procedure for debugging. It takes an array and its length and then print the array
 * in a human readable fashion.
 */
void printArray(int arr[], int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        if (i == length - 1){
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("]\n");
}