#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
} NODE;

NODE *top=NULL;

NODE *alloc()
{
	return (NODE *)malloc(sizeof(NODE));
}
void pop();
void push();
void display();

void main()
{
	NODE *temp;
	int rpt=1, i=0;
	printf("Choose between following operation\n '1' to push operation\n '2' for pop operation\n '3' to display\n");
	do
	{
		printf("Enter the operation command\n");
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
	temp=top;
	while(top!=NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}

void display()
{
	NODE *temp=top;
	if(top==NULL)
	{
		printf("Stack Empty\n");
		return;
	}
	printf("The elements in the stack are \n");
	while(temp!=NULL)
	{
		printf("%d, ",temp->num);
		temp=temp->next;
	}
}

void push()
{
	NODE *temp=alloc();
	if(temp==NULL)
	{
		printf("Unable allcate memory\n");
		return;
	}
	else
	{
		printf("Enter the integer value\n");
		scanf("%d", &temp->num);
		temp->next=top; top=temp;
	}
}

void pop()
{
	NODE *temp;
	if(top==NULL)
	{
		printf("Stack underflow\n");
		return;
	}
	else
	{
		temp=top->next;
		free(top); top=temp;
		printf("deleted\n");
	}
}
