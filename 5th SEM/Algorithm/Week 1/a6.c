#include <stdio.h>
#include <stdlib.h>

int search1(int low, int high, int *arr, int x)
{
	int mid, res=-1;
	while(low<=high-3)
	{
		mid = (low+high)/2;
		if(arr[mid]>=x)
			high = mid+1;
		else
			low = mid+1;
	}
	if(low==high-2)
	{
		if(arr[low]==x)
			return low;
		else if(arr[low+1]==x)
			return low+1;
		else return res;
	}
	else if(low==high-1)
		if(arr[low]==x)
			return low;
		else return res;
	return res;
}

int search2(int low, int high, int *arr, int x)
{
	int mid, res=-1;
	while(low<=high-3)
	{
		mid = (low+high)/2;
		if(arr[mid]<=x)
			low = mid;
		else
			high = mid;
	}
	if(low==high-2)
	{
		if(arr[low+1]==x)
			return low+1;
		else if(arr[low]==x)
			return low;
		else return res;
	}
	else if(low==high-1)
		if(arr[low]==x)
			return low;
		else return res;
	return res;
}

int main()
{
	int n, pos1, pos2, i, x, *arr;
	printf("Enter N: ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the array: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("Enter the value: ");
	scanf("%d", &x);
	pos1 = search1(0, n, arr, x);
	pos2 = search2(0, n, arr, x);
	if(pos1==-1 || pos2==-1)
		printf("Error\n");
	else
		printf("No. of occurences = %d\n", (pos2-pos1)+1);
	return 0;
}
