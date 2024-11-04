#include <stdio.h>
#include <stdlib.h>
#define n 5

int arr[n] = {15, 16, 6, 8, 5};

void main() {
    int i, j, temp, flag;
    int k = n - 1;

    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < k; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // Indicate a swap occurred
            }
        }
        if (flag == 0) {
            break; // Exit early if no swaps were made
        }
        k -= 1; // Decrement k after each pass
    }

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
