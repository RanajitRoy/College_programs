#include <stdio.h>
#define MAX 99

int top=-1;
int stack[100];

void pop();
void push();
void display();

void main()
{
	int rpt=1;
	int i=0;
	int stack[100];
	do
	{
		printf("Choose between following operation\n '1' to push operation\n '2' for pop operation\n '3' to display\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			default : printf("Wrong input\n");
				  continue;
		}
		printf("Do u want to continue? if yes then press '1' or else press any key\n");
		fflush(stdin);
		scanf("%d", &rpt);
	} while (rpt == 1);
}

void display()
{
	int i;
	if(top<0)
	{
		printf("Stack Empty\n");
		return;
	}
	printf("The elements in the stack are \n");
	for(i=0;i<=top;i++)
	{
		printf("%d, ", stack[i]);
	}
}

void push()
{
	if(top==MAX)
	{
		printf("Stack overflow\n");
		return;
	}
	else
	{
		printf("Enter the integer value\n");
		scanf("%d", &stack[top+1]);
		top++;
	}
}

void pop()
{
	if(top<0)
	{
		printf("Stack underflow\n");
		return;
	}
	else --top;
}
