#include <stdio.h>
#include <stdlib.h>

double nwtn_div(int n,double *X, double *Y, double x)
{
	int i, j;
	double total=0, temp, **del;
	del = (double **)malloc(n*sizeof(double *));
	for(i=0;i<n;i++)
	{
		del[i]=(double *)malloc((n-i)*sizeof(double));
		del[i][0]=Y[i];
	}
	for(j=1;j<n;j++)
	{
		for(i=0;i<(n-j);i++)
			del[i][j] = (del[i][j-1]-del[i+1][j-1])/(X[i]-X[i+j]);
	}
	total = Y[0];
	for(i=1;i<n;i++)
	{
		temp=1;
		for(j=0;j<i;j++)
			temp *= (x-X[j]);
		total += temp*del[0][j];
	}
	return total;
} 

int main()
{
	printf("    ----Newton's Divided Difference----\n");
	int n, i, j;
	double *X, *Y, x;
	printf("Enter the degree of the polynomial : ");
	scanf("%d", &n);n++;
	X = (double *)malloc(n*sizeof(double));
	Y = (double *)malloc(n*sizeof(double));
	for(i=0;i<n;i++)
	{
		printf("X[%d] = ", i);
		scanf("%lf", &X[i]);
		printf("Y[%d] = ", i);
		scanf("%lf", &Y[i]);
	}
	printf("Enter the value of x : ");
	scanf("%lf", &x);
	printf("\nThe result is %lf\n\n",nwtn_div(n, X, Y, x));
	return 0;
}
