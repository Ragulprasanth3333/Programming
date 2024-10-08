#include <stdio.h>

int main() {
    int arr[50], size, i;

    // Input array size
    printf("Enter the size of the array (max 50): ");
    scanf("%d", &size);

    // Input array elements
    printf("Enter %d elements of the array:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display array elements
    printf("Array elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
