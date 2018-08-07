#include <stdio.h>

void modify(int *ptr)
{
    *ptr+=10;
}

void main()
{
    int i, arr[]={1,2,3,4,5,6,7,8,9}, size=sizeof(arr)/sizeof(int);
    printf("Before modifying ");
    for(i=0;i<size;i++)
    printf("%d, ",arr[i]);
    printf("\n");
    modify(arr-1+(size+1)/2);
    printf("After modifying ");
    for(i=0;i<size;i++)
    printf("%d, ",arr[i]);
    printf("\n");
}
