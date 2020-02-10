#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    shuffle(arr, 11);
    printArray(arr, 11);

    printf("%d\n", findMedian(arr, 11));
    printArray(arr, 11);
}
