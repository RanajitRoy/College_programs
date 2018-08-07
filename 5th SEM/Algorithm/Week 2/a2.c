#include <stdio.h>
#include <stdlib.h>

int inver_count(int *arr, int low, int high)
{
	int mid=(low+high)/2, i, lp=low, rp=(low+high)/2, count_inver=0, temp[high-low];
	if(low>=high-1)
		return 0;
	else{
		count_inver+=inver_count(arr, low, mid);
		count_inver+=inver_count(arr, mid, high);
		for(i=0;i<high-low;i++)
		{
			if(lp==mid)
				temp[i]=arr[rp++];
			else if(rp==high)
				temp[i]=arr[lp++];
			else if(arr[lp]>arr[rp])
			{
				temp[i]=arr[rp++];
				count_inver+=mid-lp;
			}
			else if(arr[lp]<=arr[rp])
				temp[i]=arr[lp++];
		}
		for(i=0;i<high-low;i++)
			arr[i+low]=temp[i];
		return count_inver;
	}
}

int main()
{
	int n, i, *arr;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the array: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("No. of inversion pairs = %d\n", inver_count(arr, 0, n));
	free(arr);
	return 0;
}
