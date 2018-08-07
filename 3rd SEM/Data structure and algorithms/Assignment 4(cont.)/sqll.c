#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int num;
	struct node *next;
} NODE;

NODE *front=NULL, *rear=NULL;

void create_node(int);
void delete();
void insert();
void display();

void main()
{
	NODE *temp;
	int in,flag=0;
	printf("Enter the following commands\n '1' to insert\n '2' to delete\n '3' to display\n");
	do
	{
		printf("Enter the Command\n");
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
	temp=front;
	while(front!=NULL)
	{
		temp=front;
		front=front->next;
		free(temp);
	}
}

void create_node(int i)
{
	NODE *new=(NODE *)malloc(sizeof(NODE));
	if(new==NULL)
	{
		printf("Could not allocate memory\n");
		exit(1);
	}
	if(front==NULL)
		front=rear=new;
	else{
		rear->next=new;
		rear=new;
	}
	rear->next=NULL;
	rear->num=i;
}

void insert()
{
	int i, n=0, flag=0, len;
	char buffer[200];
	printf("enter the data separated by spaces\n");
	fflush(stdin); gets(buffer);
	len=strlen(buffer);
	if(len<1)
	{
		printf("no input\n");
		return;
	}
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
			create_node(0-n);
		else create_node(n);
		n=0; flag=0;
	}
}

void delete()
{
	NODE *temp;
	if(rear==NULL)
	{
		printf("queue empty\n"); return;
	}
	printf("deleted\n");
	if(rear==front)
	{
		free(front);
		rear=front=NULL;
	}
	else {
		temp=front;
		front=front->next;
		free(temp);
	}
}

void display()
{
	NODE *temp=front;
	if(rear==NULL)
	{
		printf("queue empty\n");
		return;
	}
	printf("The elements in the queue are\n");
	while(temp!=NULL)
	{
		printf("%d, ", temp->num);
		temp=temp->next;
	}
}
