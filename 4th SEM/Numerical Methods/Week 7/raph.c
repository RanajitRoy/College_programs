#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(int, double *, double);
double de_func(int, double *, double);
double raph(int, double *, double, int);

int main()
{
	int n, i, sig;
	printf("      ---- Newton-Raphson Method ----\n");
	printf("Enter the degree of the polynomial:  ");
	scanf("%d", &n); n++;
	double *pol, near;
	pol = (double *)malloc(n*sizeof(double));
	printf("Enter the polynomial coefficients for\n");
	for(i=0;i<n;i++)
	{
		printf("x^[%d] -> ", i);
		scanf("%lf", &pol[i]);
	}
	printf("Enter a value near root :  ");
	scanf("%lf", &near);
	printf("Enter the no. of decimal places :  ");
	scanf("%d", &sig);
	printf("\n\nThe Root of the polynomial is =  %0.*lf\n", sig, raph(n, pol, near, sig));
	free(pol);
	return 0;
}

double func(int n, double *pol, double x)
{
	int i;
	double total=0;
	for(i=0;i<n;i++)
	{
		total += pow(x, i)*pol[i];
	}
	return total;
}

double de_func(int n, double *pol, double x)
{
	int i;
	double total, *dpol = (double *)malloc((n-1)*sizeof(double));
	for(i=n-1;i>0;i--)
	{
		dpol[i-1] = pol[i]*i;
	}
	total = func(n-1, dpol, x);
	free(dpol);
	return total;
}

double raph(int n, double *pol, double near, int sig)
{
	int i=1;
	double x=near, prev=near;
	while(i)
	{
		x = x - (func(n, pol, x)/de_func(n, pol, x));
		if(prev == (int)(x*pow(10, sig)))
			i=0;
		prev = (int)(x*pow(10, (double)sig));
	}
	return x;
}
