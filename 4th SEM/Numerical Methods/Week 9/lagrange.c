#include <stdio.h>
#include <stdlib.h>

double lagrange(int, double *, double *, double);

int main()
{
	printf("\n\n     ----Lagrange's Interpolation----\n\n");
	int n, i, j;
	double *X, *Y, val_x;
	printf("Enter the degree of the polynomial : ");
	scanf("%d", &n); n++;
	X = (double *)malloc(n*sizeof(double));
	Y = (double *)malloc(n*sizeof(double));
	printf("\nEnter the values of\n");
	for(i=0;i<n;i++)
	{
		printf("X[%d] -> ", i);
		scanf("%lf", &X[i]);
		printf("Y[%d] -> ", i);
		scanf("%lf", &Y[i]);
	}
	printf("\nEnter the value of 'X' where u want to find the value of F(X) :  ");
	scanf("%lf", &val_x);
	printf("\nThe result is %lf\n\n", lagrange(n, X, Y, val_x));
	free(X);
	free(Y);
	return 0;
}

double lagrange(int n, double *X, double *Y, double val_x)
{
	int i, j;
	double result=0, coeff;
	for(i=0;i<n;i++)
	{
		coeff = 1;
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			coeff = coeff * (X[i] - X[j]);
		}
		coeff = Y[i]/coeff;
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			coeff *= (val_x - X[j]);
		}
		result += coeff;
	}
	return result;
}
