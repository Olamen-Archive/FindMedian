//
// Created by Zixuan on 2/8/20.
//

#ifndef MEDIAN_FUNCTION_H
#define MEDIAN_FUNCTION_H

int findMedian(int arr[], int length);

/*
 * The first element of given array scope will be choose as pivot, i.e. arr[lb]. Then, all element that
 * smaller than pivot will be move to the left of pivot and elments that bigger than pivot will be move to
 * the right of move. The partition is in-place and will return the position of pivot.
 * lb and rb is inclusive.
 */
int partition(int arr[], int lb, int rb);

/*
 * Fisher–Yates shuffle
 */
void shuffle(int arr[], int length);

/* to swap two integer */
void swap(int* a, int* b);

void printArray(int arr[], int length);

#endif //MEDIAN_FUNCTION_H
