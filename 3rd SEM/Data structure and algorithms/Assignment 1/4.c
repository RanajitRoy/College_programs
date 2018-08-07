#include <stdio.h>

int n, flag=0;
void search(int *a, int max)
{
    if(n==a[max/2])
    {   flag++; return; }
    else if(max==0)
        return;
    else if(n>a[max/2])
        search( (a+(max/2)+1), (max-1)/2 );
    else if(n<a[max/2])
        search( a, (max-1)/2 );
}
void main()
{
    int a[]={1,2,4,7,9,11,15,18,19,20};
    printf("Enter the number\n");
    scanf("%d", &n);
    search( a, (sizeof(a)/sizeof(int))-1 );
    if(flag==1)
        printf("search result: found\n");
    else printf("search result: not found\n");
}
