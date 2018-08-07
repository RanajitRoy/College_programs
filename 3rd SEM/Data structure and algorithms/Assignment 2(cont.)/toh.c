#include <stdio.h>

void move(int,char,char,char);

void main()
{
	int n;
	printf("Enter the number of rings\n");
	scanf("%d",&n);
	move(n,'s','d','t');
}

void move(int n, char src, char dest, char temp)
{
	if(n>0)
	{
		move(n-1, src, temp, dest);
		printf("shift %d disk from %c to %c\n", n, src, dest);
		move(n-1, temp, dest, src);
	}
}
