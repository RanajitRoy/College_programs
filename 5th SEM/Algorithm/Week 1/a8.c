#include <stdio.h>
#include <stdlib.h>

int min_arr(int n, int *arr)
{
	int mid, low=0, high=n;
	while(low<high-2)
	{
		mid = (low+high)/2;
		if(arr[mid]<arr[mid-1])
			return arr[mid];
		else if(arr[mid]<arr[0])
			high = mid+1;
		else low = mid;
	}
	if(low==0 || high==n)
		return arr[0];
	if(arr[low]>arr[low+1])
		return arr[low+1];
	else return arr[low];
}

int main()
{
	int n, i, *arr;
	printf("Enter N(>1): ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the array(distinct element): ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("The minimum element is = %d\n", min_arr(n, arr));
	return 0;
}
