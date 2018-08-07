void mult(int row, int t, int col, float *A, float *B, float *C)
{
	int i, j, k;
	float temp;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			for(k=0,temp=0.0;k<t;k++)
				temp+=(*(A+i*t+k))*(*(B+k*col+j));
			*(C+i*col+j)=temp;
		}
}

float val_det(int n, float *ori)
{
	int i, j, k;
	float temp, arr[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=*(ori+i*n+j);
	for(i=0;i<n-1;i++)
		for(k=1;k<n-i;k++)
		{
			if(arr[i][i]==0)
			{
				i=n-1; break;
			}
			temp=(-1)*(arr[i+k][i]/arr[i][i]);
			for(j=i;j<n;j++)
				arr[i+k][j]=arr[i+k][j]+(temp*arr[i][j]);
		}
	for(i=0,temp=1;i<n;i++)
		temp*=arr[i][i];
	return temp;
}

int fac(int n)
{
	if(n<=0)
		return 1;
	else return (n*fac(n-1));
}


