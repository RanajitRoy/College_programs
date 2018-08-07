#include <stdio.h>

int n;

void cramer();
double val_det(double arr[n][n]);

int main()
{
	printf("Enter the no. of unknown variables: ");
	scanf("%d",&n);
	cramer();
	return 0;
}

void cramer()
{
	int i,j,k;
	double arr[n][n+1],arrc[n][n], sol[n], D;
	printf("Enter the coefficient matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%lf", &arr[i][j]);
	printf("Enter the constant matrix:\n");
	for(i=0;i<n;i++)
		scanf("%lf", &arr[i][n]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arrc[i][j]=arr[i][j];
	D=val_det(arrc);
	if(D==(double)0)
	{
		printf("No solution\n");
		return;
	}
	else
	{
		for(k=0;k<n;k++)
		{
			for(j=0;j<n;j++)
			{

				for(i=0;i<n;i++)
				{
					if(j==k)
						arrc[i][j]=arr[i][n];
					else arrc[i][j]=arr[i][j];
				}
			}
			sol[k]=val_det(arrc);
		}
	}
	for(i=0;i<n;i++)
		printf("variable no. %d is = %0.3lf\n",i+1,sol[i]/D);
}

double	val_det(double arr[n][n])
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
			for(k=i;k<n;k++)
				arr[j+1][k]-=arr[i][k]*temp;
		}
	}
	for(i=0,temp=1;i<n;i++)
		temp*=arr[i][i];
	return temp;
}
