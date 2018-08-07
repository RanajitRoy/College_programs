#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *left, *right, *mother;
} bst;

bst *head=NULL, *flag=NULL;//flag is used by the find()

bst *alloc()
{
	return (bst *)malloc(sizeof(bst));
}
void insert();
void create( int *, int );
void display( bst * );
void ftree( bst * );
void search();
bst *find( int, bst * );
void del();

int main()
{
	int i,  j;
	printf("Enter the following commands\n '1' to insert\n '2'to display\n '3' to search\n '4' to delete\n");
	do
	{
		printf("Enter the command\n");
		scanf("%d", &j);
		switch(j)
		{
			case 1:	insert(); break;
			case 2:	display( head ); break;
			case 3:	search(); break;
			case 4:	del(); break;
			default: printf("wrong input\n");
		}
		printf("enter 1 to continue\n");
		scanf("%d", &i);
	} while(i==1);
	ftree( head );
	return 0;
}

void ftree( bst *temp )// to free all the nodes before program termination
{
	if(temp!=NULL)
	{
		ftree( temp->left );
		ftree( temp->right );
		free( temp );
	}
}

void insert()//this function scans for input and call create() where all node creation is done
{
	int count, i;
	printf("Enter the no of elements\n");
	scanf("%d", &count);
	int elm[count];
	printf("enter the elements separated by spaces\n");
	for(i=0;i<count;i++)
	{
		scanf("%d", &elm[i]);
	}
	create( elm, count );
}

void create( int *elm, int count )// to create the tree
{
	bst *temp, *new;
	int i;
	temp=head;
	for(i=0;i<count;i++,temp=head)//no of iteration = no of elements to insert
	{
		new=alloc(); new->left=new->right=NULL;
		if(head==NULL)// to create the root node
		{
			head=new;
			head->mother=NULL;
			head->num=elm[i];
			continue;
		}
		while(1)
		{
			if( temp->left!=NULL && temp->right!=NULL )// to travel to the required nodes
			{
				if( elm[i]<temp->num )
					temp=temp->left;
				else if( elm[i]>temp->num )
					temp=temp->right;
			}
			else if( elm[i]<temp->num )
			{
				if(temp->left==NULL)//checking availability
				{
					new->num=elm[i];
					temp->left=new;
					new->mother=temp;
					break;
				}
				else temp=temp->left;//if not available go to next node
			}
			else if( elm[i]>temp->num )
			{
				if(temp->right==NULL)//checking availability
				{
					new->num=elm[i];
					temp->right=new;
					new->mother=temp;
					break;
				}
				else temp=temp->right;//if not available go to next node
			}
		}
	}
}

void search()//this function is only to take input & call find()
{
	printf("Enter the element to search ");
	int elm;
	scanf(" %d", &elm); flag=NULL;
	bst *temp=find( elm, head );
	if( temp==NULL )
		printf("No such element found\n");
	else printf("%d is Found\n",temp->num);
}

bst *find(int elm, bst *temp)//this function does the job of finding for both search and delete operation
{
	if(temp!=NULL && flag==NULL)
	{
		find(elm, temp->left);
		find(elm, temp->right);
		if(elm==temp->num)
			flag=temp;
	}
	return flag;
}

void del()
{
	printf("enter the element to delete ");
	int elm;
	scanf(" %d",&elm ); flag=NULL;
	bst *node=find( elm, head ), *temp;
	if(node==NULL)// if the element is not found
	{
		printf("No such element found\n"); return;
	}
	if(node->left!=NULL)//this block of if statement searches for the leftmost children of the node for replacement
	{
		temp=node->left;
		while(temp->left!=NULL)
			temp=temp->left;
		temp->mother->left=temp->right;//we r replacing the node with the leftmost node and then deleting the leftmost node
		if(temp->right!=NULL)
			temp->right->mother=temp->mother;
		node->num=temp->num;
		free(temp);
	}
	else{// if no left children present
		if(node->right==NULL)//this is just to avoid errors due to statement line 176 (if there is no right child, then node->right->mother is not present)
		{
			if(node->mother->left==node)
				node->mother->left=NULL;
			else node->mother->right=NULL;
		}
		else{
			if(node->mother->left==node)
				node->mother->left=node->right;
			else node->mother->right=node->right;
			node->right->mother=node->mother;
		}
		free(node);
	}
}

void display( bst *temp )
{
	if( temp!=NULL )
	{
		display( temp->left );
		printf("%d, ",temp->num);
		display( temp->right );
	}
}
