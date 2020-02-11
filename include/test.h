//
// Created by Zixuan on 2/10/20.
//

#ifndef MAINPROJECT_TEST_H
#define MAINPROJECT_TEST_H

/// isMedian
/// \param arr: the array to be tested
/// \param length: the length of arr
/// \param median: the proposed meidian of arr to be examinated
/// \return 1 if median is the median of array, 0 otherwise
/*
 * a function that test if given median in parameters list is the median of array arr.
 * Notice the function also assume every element in arr is unique and arr has odd number of elements.
 */
int isMedian(int arr[], int length, int median);

/// generateArray
/// \param arr: a pointer to a pointer of int address
/// \param size: size of array to generate
/*
 * Purpose: to generate a array of given size with no repeated element and in random order
 * Produce: this function does not return any thing but as an side effect the arr pointer that
 *          passed in will be pointed to a memory address of a start of an array.
 */
void generateArray(int** arr, int size);

#endif //MAINPROJECT_TEST_H
