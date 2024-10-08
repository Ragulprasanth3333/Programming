#include <stdio.h>

void insertAtBeginning(int arr[], int *size, int num) {
    // Shift elements to the right
    for (int i = *size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = num;  // Insert at beginning
    (*size)++;     // Increase size
}

void insertAtEnd(int arr[], int *size, int num) {
    arr[*size] = num;  // Insert at end
    (*size)++;         // Increase size
}

void insertAtPosition(int arr[], int *size, int num, int pos) {
    // Shift elements to the right starting from the specified position
    for (int i = *size - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = num;  // Insert at the specified position
    (*size)++;           // Increase size
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50], size, choice, num, pos;

    printf("Enter the initial size of the array (max 50): ");
    scanf("%d", &size);

    // Input initial elements
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nChoose an insertion operation:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at a specific position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    switch (choice) {
        case 1:
            insertAtBeginning(arr, &size, num);
            break;
        case 2:
            insertAtEnd(arr, &size, num);
            break;
        case 3:
            printf("Enter the position (1 to %d): ", size + 1);
            scanf("%d", &pos);
            if (pos > 0 && pos <= size + 1) {
                insertAtPosition(arr, &size, num, pos);
            } else {
                printf("Invalid position!\n");
                return 1;
            }
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Display the updated array
    displayArray(arr, size);

    return 0;
}
