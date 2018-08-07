#include <stdio.h>

void radixsort(int arr[], int n)
{
	int max=arr[0], i, j, temp[n];
	for(i=1;i<n;i++)
		if(max<arr[i])
			max = arr[i];
	for(i=1;max/i>0;i*=10)
	{
		int  count[10]={0};
		for(j=0;j<n;j++)
			count[(arr[j]/i)%10]++;
		for(j=1;j<10;j++)
			count[j]+=count[j-1];
		for(j=n-1;j>=0;j--)
		{
			temp[count[(arr[j]/i)%10]-1]=arr[j];
			count[(arr[j]/i)%10]--;
		}
		for(j=0;j<n;j++)
			arr[j]=temp[j];
	}
}

int main()
{
	int n, i;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	radixsort(arr, n);
	printf("The sorted array: ");
	for(i=0;i<n;i++)
		printf("%d, ",arr[i]);
	printf("\n");
	return 0;
}
