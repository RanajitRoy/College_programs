#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int low, int high)
{
    int mid=(low+high)/2, lp, rp, stack[4], top = -1;
	if(low == high-2)
	{lp = mid-1; rp = high-1;}
	else if(low == high-3)
	{lp = mid-1; rp = high-2;}
	else {lp = mid-2; rp = high-2;}
    if(low==high-1)
		return;
	else{
        sort(arr, low, mid);
        sort(arr, mid, high);
		while(lp != mid || rp!=high)
		{
			if(lp == mid)
				stack[++top] = arr[rp++];
			else if(rp == high)
				stack[++top] = arr[lp++];
			else if(arr[lp] < arr[rp])
				stack[++top] = arr[lp++];
			else stack[++top] = arr[rp++];
		}
		while(top+1)
		{
			arr[(((high-low)>4)?(high-4):low) +top] = stack[top];
			top--;
		}
	}
}

int main()
{
	int *arr, i, n;
	printf("Enter the no. of elements(>1): ");
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr,0,n);
	printf("The 2nd highest is: %d\n", arr[n-2]);
	printf("\n");
	return 0;
}
