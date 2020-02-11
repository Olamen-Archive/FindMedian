//
// Created by Zixuan on 2/8/20.
//

#ifndef MEDIAN_FUNCTION_H
#define MEDIAN_FUNCTION_H

int findMedian(int arr[], int length);

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
int partition(int arr[], int lb, int rb);

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
void shuffle(int arr[], int length);

/// swap
/// \param a: pointer of an integer you want swap
/// \param b: pointer of an integer you want swap
/*
 * The procedure takes two pointers of integer type and swap the value of them. This procedure]
 * does not return anything as the integers are passed as pointer
 */
void swap(int* a, int* b);

/// printArray
/// \param arr: the array to be printed
/// \param length: the length of array to be printed
/*
 * This is a procedure for debugging. It takes an array and its length and then print the array
 * in a human readable fashion.
 */
void printArray(int arr[], int length);

#endif //MEDIAN_FUNCTION_H
