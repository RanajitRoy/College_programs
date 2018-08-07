#include <stdio.h>
#include <stdlib.h>

int min_arr(int n, int *arr)
{
	int mid, low=0, high=n, dif=(arr[n-1]-arr[0])/n, req;
	while(low<high-2)
	{
		mid = (low+high)/2;
		req = arr[0]+(mid*dif);
		if(arr[mid]>req || arr[mid]<req)
			high = mid+1;
		else if(arr[mid]==req)
			low = mid;
	}
	return arr[0]+(low+1)*dif;
}

int main()
{
	int n, i, *arr;
	printf("Enter N(>1): ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the array: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("The minimum element is = %d\n", min_arr(n, arr));
	return 0;
}
