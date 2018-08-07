#include <stdio.h>

int func(int n ,int arr[n][n])
{
	int i, j, k, temp=0;
	if(n>2)
	{
	  int copy[n-1][n-1];
		for(i=0;i<n;i++)
		{
      for(j=0;j<n-1;j++)
        for(k=0;k<n-1;k++)
          copy[j][k]=arr[j+1][(k>=i)? k+1 : k];//excluding the i'th column
			if(i%2==0)
        temp=temp+arr[0][i]*func(n-1, copy);
      else temp=temp-arr[0][i]*func(n-1, copy);
		}
	}
	else if(n==2)
		return ((arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]));
	else if(n==1)
        return arr[0][0];
	return temp;
}

int main()
{
	printf("enter the n: ");
	int n;
	scanf("%d", &n);
	int arr[n][n], i, j;
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d", &arr[i][j]);
	printf("The value of the determinant is %d",func(n, arr));
	return 0;
}
