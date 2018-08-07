#include <stdio.h>

void sarrus(int);

int main()
{
	int n;
	printf("Enter the order of determinant: ");
	scanf("%d", &n);
	sarrus(n);
	return 0;
}

void sarrus(int n)
{
	int i, j, temp=1, sum1=0, sum2=0, arr[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d", &arr[i][j]);
	for(i=0;i<n;i++,temp=1)
	{
		for(j=0;j<n;j++)
			temp*=arr[j][(i+j)%n];
		sum1+=temp;
	}
	for(i=0,temp=1;i<n;i++,temp=1)
	{
		for(j=n-1;j>=0;j--)
			temp*=arr[j][(n+i-j-1)%n];
		sum2+=temp;
	}
	printf("The value of the determinant is = %d",(sum1-sum2));
}
