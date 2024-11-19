#include <stdio.h>
#define n 7

int arr[n] = {10, 15, 1, 2, 9, 16, 11};

// Function to partition the array
int partition(int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of smaller element
    int temp;

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the partitioning index
}

// Function to perform Quick Sort
void quickSort(int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(low, high);

        // Recursively sort elements before and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// Main function
void main() {
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the Quick Sort function
    quickSort(0, n - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
