#include <stdio.h>
#include <math.h>

double func(int, double *, double);
double bisect(int, int, double *, double, double);

int main()
{
	int n, sig, i;
	printf("    ----Bisection Method----\n");
	printf("Enter the degree of polynomial: ");
	scanf("%d", &n); n++;
	double pol[n], low, high, result;
	printf("Enter the coefficients\n");
	for(i=0;i<n;i++)
		scanf("%lf", &pol[i]);
	printf("Enter lower limit: ");
	scanf("%lf",&low);
	printf("Enter higher limit: ");
	scanf("%lf",&high);
	printf("Enter the no. of decimal places: ");
	scanf("%d", &sig);
	result=bisect(n, sig, pol, low, high);
	printf("\n\n\nThe root is %0.*lf\n\n\n", sig, result);
	return 0;
}

double func(int n, double *pol, double x)
{
	int i;
	double total=0.0;
	for(i=0;i<n;i++)
		total += (pol[i] * pow(x, (double)i));
	return total;
}

double bisect(int n, int sig, double *pol, double low, double high)
{
	int comp, negative=0, i;
	double fx, bis, dec=1;
	for(i=0;i<sig;i++)
		dec *= 10;
	if(func(n, pol, low)<0)
		negative=1;
	while(1)
	{
		bis = (low+high)/2;
		fx = func(n, pol, bis);
		comp = (int)(fx*dec);
		if(comp==0)
			return bis;
		if(fx < 0)
		{
			if(negative==0)
				high = bis;
			else low = bis;
		}
		else
		{
			if(negative==0)
				low = bis;
			else high = bis;
		}
	}
}
