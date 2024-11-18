#include <stdio.h>
#define n 6
int arr[n] = {7, 4, 10, 8, 3, 1};
void main()
{
    int min,i,j,temp;
    for( i=0; i<n; i+=1)
    {
        min = i;
        for( j = i + 1; j < n; j += 1 )
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min !=i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for(i = 0; i < n; i+=1) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}