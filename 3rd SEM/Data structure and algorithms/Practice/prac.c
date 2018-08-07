#include <stdio.h>
int flag=0, elm;
void search(int *arr,int max)
{
	if(arr[max/2]==elm)
		{flag++;}
	else if(max==0)
		return;
	else if(arr[max/2]<elm)
	{
		search(&arr[(max/2)+1], (max-1)/2);
	}
	else if(arr[max/2]>elm)
	{
		search(arr, (max-1)/2);
	}
}

int main()
{
	int arr1[]={1,2,3,4,5,6};
	printf("Enter the search element   ");
	scanf("%d", &elm);
	search(arr1, (sizeof(arr1)/sizeof(int))-1);
	if(flag==1)
		printf("Search: found\n");
	else printf("Search: Not Found\n");
	return 0;
}
