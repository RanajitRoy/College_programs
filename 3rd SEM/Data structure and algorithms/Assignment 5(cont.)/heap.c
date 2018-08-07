#include <stdio.h>
#include <stdlib.h>

void build_heap(int *,int);
void heapify(int *, int, int);
void heapsort(int *, int *,int);
void display(int *, int);
void swap(int *,int *);

void main()
{
	printf("Enter the number of elements\n");
	int count, i;
	scanf("%d", &count);
	int heap[count];
	printf("Enter the numbers with with spaces between them\n");
	for(i=0;i<count;i++)
		scanf("%d", &heap[i] );
	build_heap(heap, count);
	int arr[count];
	heapsort(arr, heap, count);
	display(arr, count);
}

void build_heap(int *heap, int count)
{
	int i;
	for(i=count-1;i>=0;i--)
		heapify(heap, i, count);
}

void heapify(int *heap, int i, int count)
{
	int *large=NULL;
	if((2*i+1)<count)
	{
		if(heap[i]<heap[2*i+1])
			large=&heap[2*i+1];
		else large=&heap[i];
	}
	if((2*i+2)<count)
	{
		if(*large<heap[2*i+2])
			large=&heap[2*i+2];
	}
	if(large!=&heap[i] && large!=NULL)
	{
		swap(large, &heap[i]);
		heapify(heap, (large==&heap[2*i+1])? 2*i+1 : 2*i+2 , count);
	}
}

void heapsort(int *arr,int *heap, int count)
{
	int i;
	for(i=count-1;i>=0;i--)
	{
		swap(heap, &heap[i]);
		arr[i]=heap[i];
		heapify(heap, 0, i);
	}
}

void swap(int *ptr1, int *ptr2)
{
	int temp;
	temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}

void display(int *arr, int count)
{
	printf("The sorted array is \n");
	while(count--)
	{
		printf("%d, ",arr[count]);
	}
}
