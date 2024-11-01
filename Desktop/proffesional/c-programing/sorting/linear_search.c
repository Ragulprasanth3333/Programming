#include <stdio.h>
#include <stdlib.h>

#define N 8  // Define constant N as 8

int arr[N] = {15, 5, 20, 35, 2, 42, 67, 17};  // Initialize the array
int data = 42;

void main() {
    int i, found = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] == data) {
            printf("The element is found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("The element was not found.\n");
    }
}
