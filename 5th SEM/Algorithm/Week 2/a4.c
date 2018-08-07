#include <stdio.h>

int kth(int n, int *arr, int pos)
{
	int left = -1, right = n, pivot = arr[0], i=0, temp, res=0;
	if(n<=1)
		return arr[0];
	while(left!=right-1)
	{
		if(i%2 == 0)
		{
			if(pivot>=arr[left+1])
				left++;
			else{
				temp = arr[left+1];
				arr[left+1] = arr[right-1];
				arr[right-1] = temp;
				right--;
			}
		}
		else{
			if(pivot<=arr[right-1])
				right--;
			else{
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
	if(left>pos)
		res=kth(left, arr, pos);
	else if(left<pos)
		res=kth(n-right, &arr[right], pos-left-1);
	else return arr[left];
	return res;
}

int main()
{
	int n, i;
	printf("Enter the size(>1) of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("The neighbor elements are %d & %d\n", kth(n, arr, ((n/2)-1)), kth(n, arr, ((n+1)/2)));
	return 0;
}
