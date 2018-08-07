#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int queue[100], front=-1, rear=-1;

void delete();
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
			case 2:	delete(); break;
			case 3: display(); break;
			default: printf("wrong input\n");
		}
		printf("enter 1 to continue\n");
		scanf("%d",&flag);
	} while(flag==1);
}

void insert()
{
	int i, n=0, flag=0, flag1=0,len;
	char buffer[200];
	if(rear>=99)
	{
		printf("queue full\n"); return;
	}
	printf("enter the data separated by spaces\n");
	fflush(stdin); gets(buffer);
	len=strlen(buffer);
	if(len<1)
	{
		printf("no input\n");
		return;
	} else if(front==-1) front++;
	for(i=0;i<=len;i++)
	{
		if(buffer[i]=='-')
		{
			flag++; continue;
		}
		if(buffer[i]!=' ' && buffer[i]!='\0')
		{
			n=(n*10)+(buffer[i]-'0');
			continue;
		}
		if(flag!=0)
			queue[++rear]=-n;
		else queue[++rear]=n;
		n=0; flag=0;
		if(rear>=99)
		{ flag1++; break;}
	}
	if(flag1==1)
	{
		printf("queue full\n"); return;
	}
}

void delete()
{
	if(rear==-1)
	{
		printf("queue empty\n"); return;
	}
	++front; printf("deleted\n");
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
