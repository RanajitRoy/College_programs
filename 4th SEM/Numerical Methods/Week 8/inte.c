#include <stdio.h>
#include <stdlib.h>

double weddle(int, double *, double *);
double simps1_3(int, double *, double *);
double simps3_8(int, double *, double *);
double trape(int, double *, double *);

double func(double x)
{
	return 1/(x*x+1);
	//return 4*x - 3*x*x;
}

int main()
{
	int n, i;
	double *X, *Y;
	printf("    ----Integration----\n\n");
	X=(double *)malloc(n*sizeof(double));
	Y=(double *)malloc(n*sizeof(double));
	printf("Enter the number of intervals: ");
	scanf("%d", &n);n++;
	printf("Enter the values of\n");
	for(i=0;i<n;i++)
	{
		printf("X[%d] = ", i);
		scanf("%lf", &X[i]);
		/*printf("Y[%d] = ", i);
		scanf("%lf", &Y[i]);*/
		Y[i] = func(X[i]);
	}
	if((n-1)%6 == 0)
		printf("\nThe result is %lf\n", weddle(n,X,Y));
	else if((n-1)%3 == 0)
		printf("\nThe result is %lf\n", simps3_8(n,X,Y));
	else if((n-1)%2 == 0)
		printf("\nThe result is %lf\n", simps1_3(n,X,Y));
	else printf("\nThe result is %lf\n", trape(n,X,Y));
	free(X);
	free(Y);
	return 0;
}

double weddle(int n, double *X, double *Y)
{
	int i;
	double total=0;
	printf("    ----Weddle's Rule----\n");
	total = Y[0] + Y[n-1];
	for(i=1;i<n-1;i++)
	{
		if(i%6==0)
			total += 2*Y[i];
		else if(i%6 == 1 || i%6 == 5)
			total += 5*Y[i];
		else if(i%6 == 2 || i%6 == 4)
			total += Y[i];
		else total += 6*Y[i];
	}
	total *= (X[1] - X[0])*3;
	total /= 10;
	return total;
}

double simps3_8(int n, double *X, double *Y)
{
	int i;
	double total=0;
	printf("    ----Simpson's 3/8th Method----\n");
	total = Y[0] + Y[n-1];
	for(i=1;i<n-1;i++)
	{
		if(i%3==0)
			total += 2*Y[i];
		else total += 3*Y[i];
	}
	total *= (X[1] - X[0])*3;
	total /= 8;
	return total;
}

double simps1_3(int n, double *X, double *Y)
{
	int i;
	double total=0;
	printf("    ----Simpson's 1/3rd Method----\n");
	total = Y[0] + Y[n-1];
	for(i=1;i<n-1;i++)
		total += (i%2)? 4*Y[i] : 2*Y[i];
	total *= (X[1] - X[0]);
	total /= 3;
	return total;
}

double trape(int n, double *X, double *Y)
{
	printf("    ----Trapezoidal Method----\n");
	int i;
	double total=0;
	total = Y[0] + Y[n-1];
	for(i=1;i<n-1;i++)
		total += 2*Y[i];
	total *= (X[1] - X[0]);
	total /= 2;
	return total;
}
