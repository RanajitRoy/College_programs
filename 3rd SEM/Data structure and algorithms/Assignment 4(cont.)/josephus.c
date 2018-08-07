#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} NODE;

NODE *first=NULL, *last=NULL;

void create(int);
void jsph(int);

void main()
{
    int in; NODE *temp=first;
    printf("enter the no of players\n");
    scanf("%d",&in);
    if(in==0)
        return;
    create(in);
    printf("enter the no of intervals\n");
    scanf("%d",&in);
    if(in==0)
        return;
    jsph(in);
    last=NULL;
    while(temp!=NULL)
    {
        temp=first->next;
        free(first);
        first=temp;
    }
}

void create(int i)
{
    NODE *new;
    printf("Enter the player separated by spaces\n");
    while(i>0)
    {
        new=(NODE *)malloc(sizeof(NODE));
        if(last==NULL)
        {
            last=first=new;
            first->next=last;
        }
        last->next=new;
        new->next=first;
        last=new;
        scanf("%d",&last->num);
        i--;
    }
}

void jsph(int i)
{
    NODE *temp1=first, *temp2; int j;
    while(temp1!=temp1->next)
    {
        for(j=i;j>1;j--)
            temp1=temp1->next;
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
        temp1=temp1->next;
    }
    printf("the winner is %d\n", temp1->num);
}
