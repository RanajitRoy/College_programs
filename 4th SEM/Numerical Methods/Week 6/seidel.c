#include <stdio.h>
#include <math.h>

int preprocess(int, double *, double *);
void seidel(int, int, double *, double *);

int main()
{
	printf("    ----Gauss-Seidel Method----\nEnter the no. of unknowns :   ");
	int n, i, j, sig, error=0;
	scanf("%d", &n);
	printf("Enter the no. of decimal places :  ");
	scanf("%d", &sig);
	printf("Enter the elements:\n");
	double arr[n][n+1], temp[n][n+2], sol[n];
	for(i=0;i<n;i++)
	{
		sol[i] = temp[i][n+1] = 0;
		for(j=0;j<n+1;j++)
			scanf("%lf", &arr[i][j]);
	}
	error = preprocess(n, *arr, *temp);
	if(error==1)
		return 1;
	seidel(n, sig, temp, sol);
	printf("\n\n");
	for(i=0;i<n;i++)
		printf("variable no. %d = %0.*lf\n", i+1, sig, sol[i]); //* is a specifier of sig here
	return 0;
}

int preprocess(int n, double *arr, double *temp)
{
	int i, j, loc;
	double max, total;
	for(i=0;i<n;i++)
	{
		total = 0;
		max = fabs(*(arr+(i*(n+1)))); // getting the 1st coeff as max
		loc = 0;
		for(j=0;j<n-1;j++) // looping through next n-1 coeffs
		{
			if(max<fabs(*(arr+(i*(n+1))+j+1)))
			{
				total += fabs(max);
				max = fabs(*(arr+(i*(n+1))+j+1));
				loc = j+1;
			}
			else
			{
				total += fabs(*(arr+(i*(n+1))+j+1));
			}
		}
		if(total > max) // convergence criteria
		{
			printf("\n\nnot diagonally dominant\n");
			return 1;
		}
		else
		{
			if(*(temp+loc*(n+2)+n+1)==1)
			{
				printf("\n\nnot diagonally dominant\n"); // already occupied place in temp array
				return 1;
			}
			else
			{
				for(j=0;j<n+1;j++) // else copy the whole row
				{
					*(temp+(loc*(n+2))+j)=*(arr+(i*(n+1))+j);
				}
				*(temp+(loc*(n+2))+n+1)=1;
			}
		}
	}
	return 0;
}

void seidel(int n, int sig, double *temp, double *sol)
{
	int i, j, n1, n2, flag=0;
	double prev[n], total=0.0, fig=1;
	for(i=0;i<sig;i++)
		fig*=10;
	for(i=0;i<n;i++)
		prev[i]=0;
	while(1)
	{
		flag=0;
		for(i=0;i<n;i++) // calculation part
		{
			total = 0.0;
			for(j=0;j<n;j++)
			{
				if(j==i) continue;
				total += (*(temp+i*(n+2)+j))*sol[j];
			}
			total = *(temp+i*(n+2)+n) - total;
			sol[i] = total / *(temp+i*(n+2)+i);
		}
		for(i=0;i<n;i++) // comparing sols with previous sols
		{
			n1=(int)(sol[i]*fig);
			n2=(int)(prev[i]*fig);
			if(n1!=n2)
			{
				flag=1;
				break;
			}
		}
		if(flag==0) // boundary condition
			return;
		for(i=0;i<n;i++) // else copy to prev sols
			prev[i]=sol[i];
	}
}
