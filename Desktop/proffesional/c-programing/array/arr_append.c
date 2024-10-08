#include <stdio.h>

void append() {
    int arr[50],size,pos,i,num;
    printf("Enter the size of an arr : ");
    scanf("%d",&size);
    if(size>50 || size <= 0)
    {
        printf("invalid size");
        return ;
    }
    printf("Enter index : ");
    scanf("%d",&pos);
    if(pos>size || pos <=0)
    {
        printf("invalid size ");
        return ;
    }
    printf("Enter the number : ");
    scanf("%d",&num);
    for(i=0;i<size;i+=1)
    {
        printf("Enter the ELement %d  : ",i+1);
        scanf("%d",&arr[i]);
    }
    //for insertion
    for(i=size-1;i>=pos-1;i-=1)
    {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = num;
    size+=1;
    //printing the array
    for (i=0;i<size;i+=1)
    {
        printf("%d  ",arr[i]);
    }
}