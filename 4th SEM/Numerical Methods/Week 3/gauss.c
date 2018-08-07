#include <stdio.h>

int n;

void gauss();
double val_det(double arr[n][n+1]);

int main()
{
	printf("Enter the no. of unknown variables: ");
	scanf("%d",&n);
	gauss();
	return 0;
}

void gauss()
{
	int i,j;
	double arr[n][n+1], sol[n];
	printf("Enter the coefficient matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%lf", &arr[i][j]);
	printf("Enter the constant matrix:\n");
	for(i=0;i<n;i++)
		scanf("%lf", &arr[i][n]);
	if(val_det(arr)==(double)0)
	{
		printf("No solution\n");
		return;
	}
	else
	{
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<n-i-1;j++)
				arr[i][n]-=arr[i][n-j-1]*sol[n-j-1];
			sol[i]=arr[i][n]/arr[i][i];
		}
	}
	for(i=n-1;i>=0;i--)
		printf("variable no. %d is = %0.3lf\n",n-i,sol[i]);
}

double	val_det(double arr[n][n+1])
{
	int i,j,k;
	double temp;
	for(i=0;i<n;i++)
	{
		for(j=i,temp=0;j<n-1;j++)
		{
			if(arr[i][i]!=0)
				temp=arr[j+1][i]/arr[i][i];
			else return 0;
			for(k=i;k<=n;k++)
				arr[j+1][k]-=arr[i][k]*temp;
		}
	}
	for(i=0,temp=1;i<n;i++)
		temp*=arr[i][i];
	return temp;
}
