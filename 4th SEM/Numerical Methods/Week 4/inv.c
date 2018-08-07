#include <stdio.h>
#include "Ranajit.h"

void inverse(int, float *, float *);

int main()
{
	int n;
	printf("Enter the no. of unknowns\n");
	scanf("%d",&n);
	int i, j;
	float cof[n][n], cons[n], inv[n][n], result[n];
	printf("enter the coefficient matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%f", &cof[i][j]);
	printf("Enter the constant matrix\n");
	for(j=0;j<n;j++)
		scanf("%f", &cons[j]);
	inverse(n, cof, inv);
	mult(n,n,1,inv,cons,result);
	for(i=0;i<n;i++)
		printf("variable no. %d is = %0.3f\n", i+1, result[i]);
	return 0;
}

void inverse(int n, float *arr, float *inv)
{
	int i, j, x, y;
	float temp[n-1][n-1], D=val_det(n, arr);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(x=0;x<n-1;x++)
				for(y=0;y<n-1;y++)
					temp[x][y]=*(arr+((x>=i)? x+1 : x)*n+((y>=j)? y+1 : y));
			if((i+j)%2==0)
				*(inv+j*n+i)=val_det(n-1, temp)/D;
			else *(inv+j*n+i)=-(val_det(n-1, temp)/D);
		}
	}
}
