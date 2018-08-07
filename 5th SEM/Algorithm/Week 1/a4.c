#include <stdio.h>
#include <stdlib.h>

void find_sum(int n, int *arr, int x)
{
	int right=n-1, left=0;
	while(left<right)
	{
		if(arr[left]+arr[right] == x)
		{
			printf("%d, %d\n", arr[left], arr[right]);
			left++; right--;
		}
		else if(arr[left]+arr[right] > x)
			right--;
		else left++;
	}
}

int main()
{
	int n, i, x, *arr, *result=NULL;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the sum value: ");
	scanf("%d", &x);
	find_sum(n,arr,x);
	return 0;
}
