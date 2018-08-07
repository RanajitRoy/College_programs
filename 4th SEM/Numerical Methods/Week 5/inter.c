#include <stdio.h>
#include <math.h>
#include "Ranajit.h"

void intpol(int, float *, float *, float *);
void fxi(int, float , float *);

int main()
{
	printf("Enter the no. of data sets\n");
	int n, i;
	scanf("%d", &n);
	float y[n], x[n], sol[n], xi;
	printf("Enter the values\n");
	for(i=0;i<n;i++)
	{
		printf("Y(%d): ",i+1);
		scanf("%f", &y[i]);
		printf("X(%d): ",i+1);
		scanf("%f", &x[i]);
		sol[i]=0;
	}
	printf("Enter the value of Xi:  ");
	scanf("%f", &xi);
	intpol(n, y, x, sol);
	printf("\n\n\n f(x) = ");
	for(i=n-1;i>=0;i--)
	{
		if(sol[i]>0)
			printf("+%0.5f(X^%d) ", sol[i], i);
		else if(sol[i]<0)
			printf("%0.5f(X^%d) ", sol[i], i);
		else continue;
	}
	fxi(n, xi, sol);
	return 0;
}

void intpol(int n, float *y, float *x, float *sol)
{
	int i, j;
	float temp[n], delta[n][n], dif=*(x+1)-(*x); // temp array stores (x-x0)(x-x1)...(x-x(N-1))
	for(i=0;i<n;i++) // copying y in delta matrix and making temp 0
	{
		delta[i][0] = *(y+i);
		temp[i]=0;
	}
	for(i=1;i<n;i++) // creating del^n values in the matrix
		for(j=0;j<n-i;j++)
			delta[j][i]=delta[j+1][i-1]-delta[j][i-1];
	temp[0]=1; // first iteration
	sol[0]=y[0]; // first iteration
	for(i=0;i<n-1;i++) // starts from 2nd iteration
	{
		temp[i+1]=1;
		for(j=i;j>0;j--)
		{
			temp[j]=temp[j-1]-(temp[j]*x[i]);
		}
		temp[0]*=(-*(x+i));
		for(j=0;j<n;j++)
		{
			sol[j]+=temp[j]*(delta[0][i+1]/((float)fac(i+1)*(float)pow(dif,i+1)));
		}
	}
}

void fxi(int n, float xi, float *sol)
{
	int i, j;
	float temp, total=0;
	for(i=0;i<n;i++)
	{
		for(j=0,temp=1;j<i;j++)
			temp*=xi;
		total+=temp*sol[i];
	}
	printf("\n\n F(%0.2f) = %0.5f\n", xi, total);
}
