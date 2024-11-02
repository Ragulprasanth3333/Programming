#include <stdio.h>
#include <stdlib.h>

#define N 10
int arr[N] = {5, 9, 17, 23, 25, 45, 59, 63, 71, 89};

int binary_search(int arr[], int n, int data) {
    int l = 0, r = n - 1, mid;

    while (l <= r) {
        mid = (l + r) / 2;

        if (data == arr[mid]) {
            return mid; // Data found at index mid
        } else if (data < arr[mid]) {
            r = mid - 1; // Search in the left half
        } else {
            l = mid + 1; // Search in the right half
        }
    }

    return -1; // Data not found
}

int main() {
    int data = 45; // Element to search
    int result = binary_search(arr, N, data);

    if (result != -1) {
        printf("Element %d found at index %d\n", data, result);
    } else {
        printf("Element %d not found in the array\n", data);
    }

    return 0;
}
