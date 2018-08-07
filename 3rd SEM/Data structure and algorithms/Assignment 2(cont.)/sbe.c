#include <stdio.h>

int top1=-1, top2=100;
int stack[100];

void push();
void pop();
void display();

void main()
{
	int i,n=0;
	do
	{
		printf("Enter the following commands\n '1' to push\n '2' to pop\n '3' to display\n");
		scanf("%d", &i);
		switch(i)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			default: printf("wrong input\n");
		}
		printf("Enter 1 to continue\n");
		scanf("%d", &n);
	} while(n==1);
}

void push()
{
	if(top1==top2-1)
	{
		printf("Stack overflow"); return;
	}
	printf("Enter \n '1' for stack 1\n '2' for stack 2\n");
	int i;
	scanf("%d", &i);
	if(i==1)
	{
		printf("Enter the integer\n");
		top1++; scanf("%d", &stack[top1]);
	}
	else if(i==2)
	{
		printf("Enter the integer\n");
		top2--; scanf("%d", &stack[top2]);
	}
}

void pop()
{
	printf("Enter to stack no. for popping\n '1' for stack 1\n '2' for stack 2\n");
	int i;
	scanf("%d",&i);
	if(i==1)
	{
		if(top1<0)
		{
			printf("Stack underflow"); return;
		}
		top1--; printf("popped\n");
	}
	else if(i==2)
	{
		if(top2>99)
		{
			printf("Stack underflow"); return;
		}
		top2++; printf("popped\n");
	}
}

void display()
{
	int i;
	if(top1<0)
		printf("stack 1 is empty\n");
	else
	{
		printf("The elements in stack 1 are ");
		for(i=0;i<=top1;i++)
			printf("%d, ", stack[i]);
		printf("\n");
	}
	if(top2>99)
		printf("stack 2 is empty\n");
	else
	{
		printf("The elements are ");
		for(i=99;i>=top2;i--)
			printf("%d, ", stack[i]);
		printf("\n");
	}
}
