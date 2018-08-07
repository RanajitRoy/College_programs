#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int queue[100], front=-1, rear=-1;

void deletef();
void insertf();
void deleter();
void insertr();
void display();

void main()
{
	int in,flag=0;

	do
	{
		printf("Enter the command\n '1' to insert in front\n '2' to delete from front\n '3' to insert rear\n '4' to delete from rear\n '5' to display\n");
		scanf("%d",&in);
		switch(in)
		{
			case 1:	insertf(); break;
			case 2:	deletef(); break;
			case 3:	insertr(); break;
			case 4:	deleter(); break;
			case 5: display(); break;
			default: printf("wrong input\n");
		}
		printf("enter 1 to continue\n");
		scanf("%d",&flag);
	} while(flag==1);
}

void insertr()
{
	if(rear>=99)
	{
		printf("queue full\n"); return;
	}
	printf("Enter the Data\n");
	scanf("%d", &queue[rear+1]);
	if(front==-1)
		front=0;
	rear++;
}

void deletef()
{
	if(rear==-1 && front==-1)
	{
		printf("queue empty\n"); return;
	}
	++front; printf("deleted\n");
	if(rear<front)
	{
		rear=-1; front=-1;
	}
}

void insertf()
{
	if(front==0)
	{
		printf("no space in front\n"); return;
	}
	printf("Enter the Data\n");
	if(front==-1)
	{
		scanf("%d", &queue[0]);
		front=0; rear=0; return;
	}
	scanf("%d", &queue[front-1]);
	front--;
}

void deleter()
{
	if(rear==-1 && front==-1)
	{
		printf("queue empty\n"); return;
	}
	--rear; printf("deleted\n");
	if(rear<front)
	{
		rear=-1; front=-1;
	}
}

void display()
{
	int i;
	if(rear==-1)
	{
		printf("queue empty\n");
		return;
	}
	printf("The elements in the queue are\n");
	for(i=front;i<=rear;i++)
		printf("%d, ", queue[i]);
}
