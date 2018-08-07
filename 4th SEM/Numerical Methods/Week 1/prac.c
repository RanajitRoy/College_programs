#include <stdio.h>

int N;
void func(int[N][N]);

void main()
{
	int arr[4][4],i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d", &arr[i][j]);
	func(arr);
}

void func(int arr[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			printf("%d",arr[i][j]);
}
