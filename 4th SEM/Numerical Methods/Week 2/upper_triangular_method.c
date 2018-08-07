#include <stdio.h>

void func(int);

int main()
{
	int n;
	printf("enter the n: ");
	scanf("%d", &n);
	func(n);
}

void func(int n)
{
	int i, j, k;
	double temp, arr[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%lf", &arr[i][j]);
	for(i=0;i<n-1;i++)
		for(k=1;k<n-i;k++)
		{
			if(arr[i][i]==0)
			{
				i=n-1; break;
			}
			temp=(-1)*(arr[i+k][i]/arr[i][i]);
			for(j=i;j<n;j++)
				arr[i+k][j]=arr[i+k][j]+(temp*arr[i][j]);
		}
	for(i=0,temp=1;i<n;i++)
		temp*=arr[i][i];
	printf("the value of the determinant = %0.2lf", temp);
}
