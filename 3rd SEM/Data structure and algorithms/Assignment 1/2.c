#include <stdio.h>

typedef struct dts
{
    int kms, mts;
} distance;

void substract(distance *dist)
{
    if(dist[0].mts>=dist[1].mts)
    {
        dist[0].kms=dist[0].kms-dist[1].kms;
        dist[0].mts=(dist[0].mts-dist[1].mts)%1000;
    }
    if(dist[0].mts<dist[1].mts)
    {
        dist[0].kms=dist[0].kms-dist[1].kms-1;
        dist[0].mts=(dist[0].mts-dist[1].mts+1000)%1000;
    }
    printf("The result is %dkm %dmts\n",dist[0].kms,dist[0].mts);
}
void add(distance *dist)
{
    dist[0].kms=dist[0].kms+dist[1].kms+(dist[0].mts+dist[1].mts)/1000;
    dist[0].mts=(dist[0].mts+dist[1].mts)%1000;
    printf("The result is %dkm %dmts\n",dist[0].kms,dist[0].mts);
}

void main()
{
    char c;
    distance dist[2];
    printf("Enter the 1st distance in kms and then in metres \n");
    scanf("%d %d",&dist[0].kms,&dist[0].mts);
    printf("Enter the 2st distance in kms and then in metres \n");
    scanf("%d %d",&dist[1].kms,&dist[1].mts);
    printf("Enter '+' to add and '-' to substract\n");
    fflush(stdin);
    scanf("%c",&c);
    switch(c)
    {
        case '+': add(dist); break;
        case '-': substract(dist); break;
        default : printf("wrong symbol\n");
    }
}
