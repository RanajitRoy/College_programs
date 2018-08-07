#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front=-1, rear=-1;

void del();
void insert();
void display();

void main()
{
	int in,flag=0;
	do
	{
		printf("Enter the command\n '1' to insert\n '2' to delete\n '3' to display\n");
		scanf("%d",&in);
		switch(in)
		{
			case 1:	insert(); break;
			case 2:	del(); break;
			case 3: display(); break;
			default: printf("wrong input\n");
		}
		printf("enter 1 to continue\n");
		scanf("%d",&flag);
	} while(flag==1);
}

void insert()
{
	if((rear+1)%MAX==front)
	{
		printf("queue full\n"); return;
	}
	printf("enter the data\n");
	scanf("%d", &queue[(rear+1)%MAX]);
	if(front==-1)
		front=0;
	rear++;
}

void del()
{
	if(rear==-1 && front==-1)
	{
		printf("queue empty\n"); return;
	}
	printf("deleted\n");
	if(rear%MAX==front%MAX)
	{
		rear=-1; front=-1;
	} else front=(front+1)%MAX;
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
	if(rear<front)
	{
		for(i=0;i<=(front+MAX-rear);i++)
			printf("%d, ", queue[(front+i)%MAX]);
	}
	else
	for(i=front;i<=rear;i++)
		printf("%d, ", queue[i]);
}
