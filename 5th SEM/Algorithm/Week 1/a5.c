#include <stdio.h>
#include <stdlib.h>

int find_row(int n, int **arr, int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i][0]>x)
			break;
	}
	return i-1;
}

void find(int n, int m, int **arr, int x)
{
	int res, rs = find_row(n, arr, x);
	if(rs == -1)
		printf("Not Found\n");
	else
		res = search(0, m, arr[rs], x);
		if(res == -1)
			printf("Not Found\n");
		else printf("Found in arr[%d][%d]\n", rs, res);
}

int search(int low, int high, int *arr, int x)
{
	int mid = (low+high)/2, res=-1;
	if(low==high-1)
		if(arr[low] == x)
			return low;
		else res;
	else if(arr[mid] == x)
		return mid;
	else if(arr[mid] > x)
		res = search(low, mid, arr, x);
	else if(arr[mid] < x)
		res = search(mid, high, arr, x);
	return res;
}

int main()
{
	int n, m, i, j, x, **arr, *result=NULL;
	printf("Enter N: ");
	scanf("%d", &n);
	printf("Enter M: ");
	scanf("%d", &m);
	arr = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		arr[i] = (int *)malloc(m*sizeof(int));
	printf("Enter the matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d", &arr[i][j]);
	printf("Enter the value: ");
	scanf("%d", &x);
	find(n, m,arr,x);
	return 0;
}
