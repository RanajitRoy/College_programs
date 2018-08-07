#include <stdio.h>

void add()
{
	int i, j, row, col;
	printf("enter no of rows: ");
	scanf("%d", &row);
	printf("enter no of columns: ");
	scanf("%d", &col);
	int arr1[row][col], arr2[row][col];
	printf("Enter the 1st matrix:\n");
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d", &arr1[i][j]);
	printf("Enter the 2nd matrix:\n");
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			scanf("%d", &arr2[i][j]);
			arr1[i][j]+=arr2[i][j];
		}
	printf("The resultant matrix is:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%4d", arr1[i][j]);
		printf("\n");
	}
}

void sub()
{
	int i, j, row, col;
	printf("enter no of rows: ");
	scanf("%d", &row);
	printf("enter no of columns: ");
	scanf("%d", &col);
	int arr1[row][col], arr2[row][col];
	printf("Enter the 1st matrix:\n");
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d", &arr1[i][j]);
	printf("Enter the 2nd matrix:\n");
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			scanf("%d", &arr2[i][j]);
			arr1[i][j]-=arr2[i][j];
		}
	printf("The resultant matrix is:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%4d", arr1[i][j]);
		printf("\n");
	}
}

void mult()
{
	int i, j, k, row1, col1, row2, col2;
	printf("enter no of rows in 1st matrix: ");
	scanf("%d", &row1);
	printf("enter no of columns in 1st matrix: ");
	scanf("%d", &col1);
	printf("enter no of rows in 2nd matrix: ");
	scanf("%d", &row2);
	printf("enter no of columns in 2nd matrix: ");
	scanf("%d", &col2);
	if(col1!=row2)
	{
		printf("Cannot multiply\n");
		return;
	}
	int arr1[row1][col1], arr2[row2][col2], arr3[row1][col2];
	printf("Enter the 1st matrix:\n");
	for(i=0;i<row1;i++)
		for(j=0;j<col1;j++)
			scanf("%d", &arr1[i][j]);
	printf("Enter the 2nd matrix:\n");
	for(i=0;i<row2;i++)
		for(j=0;j<col2;j++)
			scanf("%d", &arr2[i][j]);
	for(i=0;i<row1;i++)
		for(j=0;j<col2;j++)
			for(k=0,arr3[i][j]=0;k<row2;k++)
				arr3[i][j]+=arr1[i][k]*arr2[k][j];
	printf("The product is:\n");
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
			printf("%4d",arr3[i][j]);
		printf("\n");
	}
}

void transpose()
{
	int i, j, row, col;
	printf("enter no of rows: ");
	scanf("%d", &row);
	printf("enter no of columns: ");
	scanf("%d", &col);
	int arr[row][col];
	printf("Enter the matrix:\n");
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d", &arr[i][j]);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%4d", arr[j][i]);
		printf("\n");
	}
}

int main()
{
	int n;
	printf("enter the command:\n 1 for Addition\n 2 for Subtraction\n 3 for Multiplication\n 4 for transpose\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1: add(); break;
		case 2:	sub(); break;
		case 3:	mult(); break;
		case 4:	transpose(); break;
		default: printf("Wrong input\n");
	}
	return 0;
}
