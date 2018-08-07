#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *ptr;
} NODE;

NODE *head=NULL;

NODE *alloc()
{
	return (NODE *)malloc(sizeof(NODE));
}
void insert_beg();
void insert_end();
void insert_any();
void del_beg();
void del_end();
void del_any();
void rev_prnt();
void search();
int count_node();
void split();
void display();

void main()
{
	NODE *temp;
	int inp, flag=0;
	do
	{
		printf("Enter the following commands\n '1' to insert at beginning\n '2' to insert at end\n '3' to insert at specific position\n '4' to delete from beginning\n '5' to delete from end\n '6' to delete a data\n '7' to reverse print\n '8' to search\n '9' to count nodes\n '10' to split in half\n '11' to display\n");
		scanf("%d", &inp);
		switch(inp)
		{
			case 1:	insert_beg(); break;
			case 2:	insert_end(); break;
			case 3:	insert_any(); break;
			case 4:	del_beg(); break;
			case 5:	del_end(); break;
			case 6:	del_any(); break;
			case 7:	rev_prnt(); break;
			case 8:	search(); break;
			case 9:	printf("there are %d nodes in the linked list\n", count_node()); break;
			case 10:split(); break;
			case 11:display(); break;
			default: printf("wrong input");
		}
		printf("enter 1 to continue\n");
		scanf("%d", &flag);
	} while(flag==1);
	temp=head;
	while(head!=NULL)
	{
		head=temp->ptr;
		free(temp);
		temp=head;
	}
}

void insert_beg()
{
	NODE *temp=head;
	head=alloc();
	if(head==NULL)
	{
		printf("error\n"); return;
	}
	head->ptr=temp;
	printf("enter the data\n");
	scanf("%d", &head->num);
}

void insert_end()
{
	NODE *temp=head;
	while(temp->ptr!=NULL)
		temp=temp->ptr;
	temp->ptr=alloc();
	if(temp->ptr==NULL)
	{
		printf("error\n"); return;
	}
	temp=temp->ptr;
	temp->ptr=NULL;
	printf("Enter the data\n");
	scanf("%d", &temp->num);
}
void insert_any()
{
	NODE *temp1=head, *temp2=head, *new; int pos;
	printf("enter the position\n");
	scanf("%d", &pos);
	if(pos==0)
	{
		insert_beg(); return;
	}
	while(pos-- && temp1!=NULL)
	{
		temp2=temp1; temp1=temp1->ptr;
	}
	new=alloc();
	if(new==NULL)
	{
		printf("error\n"); return;
	}
	new->ptr=temp1;
	temp2->ptr=new;
	printf("enter the data\n");
	scanf("%d", &new->num);
}
void del_beg()
{
	NODE *temp;
	if(head==NULL)
	{
		printf("no nodes to delete\n"); return;
	}
	temp=head->ptr;
	free(head);
	head=temp;
	printf("deleted\n");
}
void del_end()
{
	NODE *temp=head, *temp2=head;
	if(head==NULL)
	{
		printf("no nodes to delete\n"); return;
	}
	while(temp->ptr!=NULL)
	{
		temp2=temp;
		temp=temp->ptr;
	}
	free(temp2->ptr);
	temp2->ptr=NULL;
	printf("deleted\n");
}
void del_any()
{
	NODE *temp1=head, *temp2=head; int elm;
	if(head==NULL)
	{
		printf("no nodes to delete\n"); return;
	}
	printf("enter the data to delete\n");
	scanf("%d", &elm);
	while(temp1!=NULL)
	{
		if(head->num==elm)
		{
			del_beg(); temp1=head; temp2=head;
		}
		else if(temp1->num==elm)
		{
			temp2->ptr=temp1->ptr;
			free(temp1);
			temp1=temp2->ptr;
			printf("deleted\n");
		} else {temp2=temp1;
		temp1=temp1->ptr;}
	}
}

void rev_prnt()
{
	NODE *temp1, *temp2, *temp3=NULL;
	temp1=head;
	if(head==NULL)
	{
		printf("no elements to print\n"); return;
	}
	while(temp1!=NULL)
	{
		temp1=temp1->ptr;
		temp2=head;
		while(temp2->ptr!=temp3)
			temp2=temp2->ptr;
		temp3=temp2;
		printf("%d, ", temp2->num);
	}
}

void search()
{
	NODE *temp=head;
	int elm, flag=0, loc=0;
	if(head==NULL)
	{
		printf("no elements to search for\n"); return;
	}
	printf("Enter the element to search\n");
	scanf("%d",&elm);
	while(temp!=NULL)
	{
		if(temp->num==elm)
		{
			flag++; break;
		}
		temp=temp->ptr;
		loc++;
	}
	if(flag==0)
		printf("no such record is found\n");
	else printf("the element '%d' is present in %d location\n", elm, loc);
}

int count_node()
{
	NODE *temp=head; int count=0;
	while(temp!=NULL)
	{
		temp=temp->ptr;
		count++;
	}
	return count;
}

void split()
{
	int n=count_node()/2;
	NODE *head2, *temp=head;
	if(n==0)
	{
		printf("Not enough elements to split\n"); return;
	}
	while(n-1)
	{
		temp=temp->ptr; n--;
	}
	head2=temp->ptr;
	temp->ptr=NULL;
	temp=head; printf("Elements in 1st linked list are ");
	while(temp!=NULL)
	{
		printf("%d, ", temp->num);
		temp=temp->ptr;
	}
	temp=head2; printf("\nElements in 2nd linked list are ");
	while(temp!=NULL)
	{
		printf("%d, ", temp->num);
		temp=temp->ptr;
	}
}
void display()
{
	NODE *temp=head;
	if(head==NULL)
	{
		printf("no elements to display\n"); return;
	}
	printf("Elements in the linked list are ");
	while(temp!=NULL)
	{
		printf("%d, ", temp->num);
		temp=temp->ptr;
	}
}
