#include <stdio.h>
#define n 6

int arr[n] = {5, 4, 10, 1, 6, 2};

void main() {
    int i, j, temp;
    
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        
        // Shift elements of arr[0..i-1] that are greater than temp
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
    
    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
