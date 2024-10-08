#include <stdio.h>

// Function to delete the element at the beginning
void deleteAtBeginning(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;  // Decrease size after deletion
}

// Function to delete the element at the end
void deleteAtEnd(int *size) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    (*size)--;  // Decrease size after deletion
}

// Function to delete the element at a specific position
void deleteAtPosition(int arr[], int *size, int pos) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (pos < 1 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;  // Decrease size after deletion
}

// Function to display the array elements
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50], size, choice, pos;

    printf("Enter the initial size of the array (max 50): ");
    scanf("%d", &size);

    // Input initial elements
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nChoose a deletion operation:\n");
    printf("1. Delete at beginning\n");
    printf("2. Delete at end\n");
    printf("3. Delete at a specific position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteAtBeginning(arr, &size);
            break;
        case 2:
            deleteAtEnd(&size);
            break;
        case 3:
            printf("Enter the position (1 to %d): ", size);
            scanf("%d", &pos);
            deleteAtPosition(arr, &size, pos);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Display the updated array
    displayArray(arr, size);

    return 0;
}
