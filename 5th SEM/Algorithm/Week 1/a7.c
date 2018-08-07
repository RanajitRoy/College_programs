#include <stdio.h>
#include <stdlib.h>

float median(int n, int *arr1, int *arr2)
{
	int L1=0,H1=n, L2=0,H2=n;
	float med1, med2, max, min;
	while(L1<H1-2)
	{
		med1 = (((H1-L1)%2==1)? arr1[(L1+H1)/2] : (float)(arr1[(L1+H1-1)/2]+arr1[(L1+H1)/2])/2);
		med2 = (((H2-L2)%2==1)? arr2[(L2+H2)/2] : (float)(arr2[(L2+H2-1)/2]+arr2[(L2+H2)/2])/2);
		if(med1==med2)
			return med1;
		else if(med1<med2)
		{
			L1 = (L1+H1-1)/2;
			H2 = ((L2+H2)/2)+1;
		}
		else
		{
			L2 = (L2+H2-1)/2;
			H1 = ((L1+H1)/2)+1;
		}
	}
	if(arr1[L1]>arr2[L2])
		max = (float)arr1[L1];
	else max = (float)arr2[L2];
	if(arr1[L1+1]>arr2[L2+1])
		min = (float)arr2[L2+1];
	else min = (float)arr1[L1+1];
	return (max+min)/2;
}

int main()
{
	int n, i, *arr1, *arr2;
	printf("Enter N(>1): ");
	scanf("%d", &n);
	arr1 = (int *)malloc(n*sizeof(int));
	arr2 = (int *)malloc(n*sizeof(int));
	printf("Enter the 1st sorted array: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr1[i]);
	printf("Enter the 2nd sorted array: ");
	for(i=0;i<n;i++)
		scanf("%d", &arr2[i]);
	printf("The median is = %0.2f\n", median(n, arr1, arr2));
	return 0;
}
