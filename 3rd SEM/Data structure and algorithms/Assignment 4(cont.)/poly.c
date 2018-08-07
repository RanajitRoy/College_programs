#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff, expo;
    struct node *next;
} NODE;

NODE *head1=NULL, *head2=NULL, *head3=NULL;

NODE *alloc()
{
    return (NODE *)malloc(sizeof(NODE));
}

NODE *str_to_ll(char *, NODE *);
void addition();
void display(NODE *);

int main()
{
    char str1[100], str2[100];
    printf("Enter the simplified 1st polynomial expression (single variable)\n");
    scanf("%[^\n]s", str1); fflush(stdin);
    printf("Enter the simplified 2nd polynomial expression (single variable)\n");
    scanf("%[^\n]s", str2);
    head1=str_to_ll(str1, head1); head2=str_to_ll(str2, head2);
    addition(); display(head3);
    NODE *temp=head3;
    while(head3!=NULL)
    {
        temp=head3->next; free(head3);
        head3=temp;
    }
    return 0;
}

NODE *str_to_ll(char arr[], NODE *head)
{
    int i=0, flag_ex=0, neg=0, total=0, flag=0, count=0; NODE *temp, *new;
    do
    {
        if(arr[i]=='-')
            neg++;
        if(arr[i]>='0' && arr[i]<='9')
        {
            total=(total*10)+arr[i]-'0';
            flag++;
        }
        else if((arr[i]<'0' || arr[i]>'9') && flag!=0)
        {
            if(count==0)
                new=alloc();
            if(new==NULL)
            {
                printf("Error(could not allocate memory)\n"); exit(1);
            }
            if(flag_ex!=0)
                if(neg==0)
                    new->expo=total;
                else { new->expo=0-total; neg=0; }
            else
                if(neg==0)
                    new->coeff=total;
                else { new->coeff=0-total; neg=0; }
            flag=flag_ex=total=0; count++;
        }
        if(arr[i]=='^')
            flag_ex++;
        if(count==2)
        {
            if(head==NULL)
            {
                head=new; temp=head;
            }
            temp->next=new;
            temp=temp->next;
            count=0;
        }
    }while(arr[i++]!='\0');
    temp->next=NULL;
    return head;
}

void addition()
{
    NODE *temp, *new, *prev;
    while(head1!=NULL || head2!=NULL)
    {
        if(head1==NULL)
            while(head2!=NULL)
            {
                new=alloc();
                if(new==NULL)
                {
                    printf("Error(could not allocate memory)\n"); exit(1);
                }
                new->next=NULL;
                new->coeff=head2->coeff;
                new->expo=head2->expo;
                prev=head2; head2=head2->next; free(prev);
                if(head3==NULL) head3=new;
                else temp->next=new;
                temp=new;
            }
        else if(head2==NULL)
            while(head1!=NULL)
            {
                new=alloc();
                if(new==NULL)
                {
                    printf("Error(could not allocate memory)\n"); exit(1);
                }
                new->next=NULL;
                new->coeff=head1->coeff;
                new->expo=head1->expo;
                prev=head1; head1=head1->next; free(prev);
                if(head3==NULL) head3=new;
                else temp->next=new;
                temp=new;
            }
        else if(head1->expo==head2->expo)
        {
            new=alloc();
            if(new==NULL)
            {
                printf("Error(could not allocate memory)\n"); exit(1);
            }
            new->next=NULL;
            new->coeff=head1->coeff+head2->coeff;
            new->expo=head1->expo;
            prev=head1; head1=head1->next; free(prev);
            prev=head2; head2=head2->next; free(prev);
            if(head3==NULL) head3=new;
            else temp->next=new;
            temp=new;
        }
        else if(head1->expo>head2->expo)
        {
            new=alloc();
            if(new==NULL)
            {
                printf("Error(could not allocate memory)\n"); exit(1);
            }
            new->next=NULL;
            new->coeff=head1->coeff;
            new->expo=head1->expo;
            prev=head1; head1=head1->next; free(prev);
            if(head3==NULL) head3=new;
            else temp->next=new;
            temp=new;
        }
        else if(head1->expo<head2->expo)
        {
            new=alloc();
            if(new==NULL)
            {
                printf("Error(could not allocate memory)\n"); exit(1);
            }
            new->next=NULL;
            new->coeff=head2->coeff;
            new->expo=head2->expo;
            prev=head2; head2=head2->next; free(prev);
            if(head3==NULL) head3=new;
            else temp->next=new;
            temp=new;
        }
    }
}

void display(NODE *temp)
{
    printf("The final expression is\n");
    while(temp!=NULL)
    {
        printf("[(%d)*x^(%d)]", temp->coeff, temp->expo);
        if(temp->next!=NULL)
            printf("+");
        temp=temp->next;
    }
    printf("\n");
}
