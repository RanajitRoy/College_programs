#include <stdio.h>

void main()
{
	int i, count0=0, arr[]={1,0,1,1,1,0,0,1,0,0};
	for(i=0;i<sizeof(arr)/sizeof(int);i++)
	{
		if(arr[i]==0)
			count0++;
	}
	printf("The modified array is ");
	for(i=0;i<sizeof(arr)/sizeof(int);i++,count0--)
	{
		if(count0>0)
			arr[i]=0;
		else arr[i]=1;
		printf("%d, ",arr[i]);
	}
	printf("\n");
}
