#include <stdio.h>

void incr(int *, int);

void main()
{
	int i,arr[]={0,1,2,3,4,5,6,7,8};
	incr(arr, sizeof(arr)/sizeof(int));
}

void incr(int *arr, int len)
{
	int i;
	printf("The incremented values are ");
	for(i=0;i<len;i++)
	{
		printf("%d, ",++*(arr+i));
	}
}
