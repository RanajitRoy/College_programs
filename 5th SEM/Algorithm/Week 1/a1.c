#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int low, int high)
{
    int mid=(low+high)/2;
    if(low>=high-1)
		return;
	else{
        sort(arr, low, mid);
        sort(arr, mid, high);
        merge(arr, low, high);
	}
}

void merge(int *arr, int low, int high)
{
    int i, lp=low, rp=(low+high)/2, temp[high-low];
    for(i=0;i<high-low;i++)
	{
        if(lp==(low+high)/2)
			temp[i]=arr[rp++];
		else if(rp==high)
			temp[i]=arr[lp++];
        else if(arr[lp]>arr[rp])
			temp[i]=arr[rp++];
		else if(arr[lp]<=arr[rp])
			temp[i]=arr[lp++];
	}
	for(i=0;i<high-low;i++)
		arr[i+low]=temp[i];
}

int main()
{
	int *arr, i, n;
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr,0,n);
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d, ", arr[i]);
	printf("\n");
	return 0;
}
