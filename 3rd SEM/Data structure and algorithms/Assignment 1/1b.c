#include <stdio.h>

void main()
{
	int i,arr[]={0,1,2,3,4,5,6,7,8,9};
	printf("Every alternate elements are ");
	for(i=0;i<9;i=i+2)
	{
		printf("%d, ",arr[i]);
	}
}
