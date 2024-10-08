#include <stdio.h>

int main() {
    int arr[50], i, size, num, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > 50 || size <= 0) {
        printf("Size is out of range.\n");
        return 1; 
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i+=1) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert the number: ");
    scanf("%d", &pos);

    if (pos > size + 1 || pos <= 0) {
        printf("Invalid position!\n");
        return 1; // Exit the program if the position is invalid
    }

    // Shifting elements to the right
    for (i = size-1; i >= pos-1; i-=1) 
    {
        arr[i+1] = arr[i];
    }

    // Inserting the new element
    arr[pos - 1] = num;
    size += 1; // Increment the size

    printf("Array after insertion:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
