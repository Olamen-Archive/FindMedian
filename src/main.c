#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"
#include "test.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    shuffle(arr, 11);
    printArray(arr, 11);

    printf("%d\n", isMedian(arr, 11, findMedian(arr, 11)));
    printArray(arr, 11);

    for (int size = 1; size < 100000000; size += ) {
        if (size % 2 == 0) { size += 1; }

        int *arr;
        generateArray(&arr, size);
        int proposedMedian = findMedian(arr, size);

        if (!isMedian(arr, size, proposedMedian)) {
            printf("wrong!\n");
            break;
        }

        free(arr); // GC
    }

    return 0;
}
