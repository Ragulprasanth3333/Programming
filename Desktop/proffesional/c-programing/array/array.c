#include <stdio.h>

int main() {
    int arr[50],i,size;
    printf("enter the size of arr :");
    scanf("%d",&size);
    if (size > 50)
    {
        printf("it is out of range");
    }
    else if (size < 50)
    {
        for(i=0;i<size;i+=1)
        {
            printf("Enter the element :");
            scanf("%d",&arr[i]);
        }
        for(i = 0;i<size;i+=1)
        {
            printf("%d ",arr[i]);
        }

    }    
}