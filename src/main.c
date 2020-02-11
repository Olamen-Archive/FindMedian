#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"
#include "test.h"

#define TEST_SIZE 1000
#define TEST_FREQ 1

int main() {
    /* an naive example to demostrate the algorithm */
    printf("Native example\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    shuffle(arr, 11);
    printArray(arr, 11);

    printf("%d\n", isMedian(arr, 11, findMedian(arr, 11)));
    printArray(arr, 11);

    /*
     * Proving the correctness of algorithm using randomly generated array
     * it will print WRONG if any of the median give by our algorithm is not correct
     * Also notice that the array generated could takes up to 100MB memeory. make sure you
     * machine has enough memory before running this program.
     */
    printf("Start randomized test!\n");
    for (int size = 1; size < TEST_SIZE; size += TEST_FREQ) {
        if (size % 2 == 0) { size += 1; }

        int *arr;
        generateArray(&arr, size);
        int proposedMedian = findMedian(arr, size);

        if (!isMedian(arr, size, proposedMedian)) {
            printf("WRONG!\n");
            break;
        }

        free(arr); // GC

        // update status
        if (size % ((TEST_SIZE / TEST_FREQ) / 100) == 1) {
            printf("%d/%d\n", size, TEST_SIZE);
        }
    }

    return 0;
}
