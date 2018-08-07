#include <stdio.h>
#include <string.h>

void sort(int *, int *, int);
void merge(int *, int *, int);

int main()
{
	int i, max;
	printf("Enter the no. of elements\n");
	scanf("%d", &max);
	int array1[max], array2[max];
	printf("Enter the array elements (separated by spaces)\n");
	for(i=0;i<max;i++)
	{
		scanf("%d", &array1[i]);
		array2[i]=array1[i];
	}
	sort(array1, array2, max-1);
	printf("The sorted array is\n");
	for(i=0;i<max;i++)
	{
		printf(" %d,", array1[i]);
	}
}

void sort(int *array1, int *array2, int max)
{
	if(max!=0)
	{
		sort(array2, array1, (max-1)/2);
		sort(&array2[(max+1)/2], &array1[(max+1)/2], max/2);
		merge(array1, array2, max);
	}
}

void merge(int *base0, int *base1, int max)
{
	int i, i0=0,i1=(max+1)/2;
	for(i=0;i<=max;i++)
        {
            if(i0==(max+1)/2)
                base0[i]=base1[i1++];
            else if(i1==max+1)
                base0[i]=base1[i0++];
            else if(base1[i0]<base1[i1])
                base0[i]=base1[i0++];
            else base0[i]=base1[i1++];
        }
}
