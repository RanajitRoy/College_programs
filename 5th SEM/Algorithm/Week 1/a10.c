#include <stdio.h>
#include <stdlib.h>

int min_arr(int n, int *arr)
{
	int mid, low=0, high=n;
	while(low<high-2)
	{
		mid = (low+high)/2;
		if(arr[mid]<arr[mid-1])
			high = mid+1;
		else if(arr[mid]>arr[mid-1])
			low = mid;
	}
	if(arr[low]>arr[low+1])
		return low+1;
	else return low+2;
}

int main()
{
	int n, i, *arr;
	printf("Enter N(>1): ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the Bitonic sequence: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("The Bitonic point is = %d\n", min_arr(n, arr));
	return 0;
}
