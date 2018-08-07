#include <stdio.h>

void main()
{
	int i, j, temp, arr[]={1,2,3,2,4,5,1,5,3},len=sizeof(arr)/sizeof(int);
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(arr[j]>=arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("the non-repeated elements are\n%d\n",arr[0]);
	for(i=1,temp=arr[0];i<len;i++)
	{
		if(arr[i-1]==arr[i])
			continue;
		else printf("%d, ",arr[i]);
	}
}
