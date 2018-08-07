#include <stdio.h>
#include <stdlib.h>

void qsrt(int n, int *arr)
{
	int left = -1, right = n, pivot = arr[0], i=0, temp;
	if(n<=1)
		return;
	while(left!=right-1)
	{
		if(i%2 == 0)
		{
			if(pivot>=arr[left+1])
			{
				left++;
			}
			else
			{
				temp = arr[left+1];
				arr[left+1] = arr[right-1];
				arr[right-1] = temp;
				right--;
			}
		}
		else
		{
			if(pivot<=arr[right-1])
			{
				right--;
			}
			else
			{
				temp = arr[left+1];
				arr[left+1] = arr[right-1];
				arr[right-1] = temp;
				left++;
			}
		}
		i++;
	}
	if(left!=-1)
	{
		arr[0] = arr[left];
		arr[left] = pivot;
	}
	qsrt(left, arr);
	qsrt(n-right, &arr[right]);
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
	qsrt(n, arr);
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d, ", arr[i]);
	printf("\n");
	return 0;
}
