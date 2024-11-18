#include <stdio.h>
#define n 6

int arr[] = {7, 4, 10, 8, 3, 1};

void main() {
    int min, i, j, temp;
    
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // Swap without using pointers
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    
    // Print the sorted array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
