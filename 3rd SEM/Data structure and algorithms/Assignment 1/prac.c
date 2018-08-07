#include <stdio.h>

int main()
{
    int min=1, max=11, k, n, a[]={1,2,4,7,9,11,15,18,19,20,22};
    scanf("%d",&n);
    if(n>a[max-1] || n<a[0])
        printf("absent\n");
    else if(n==a[max-1] || n==a[0])
        printf("present\n");
    else {k=max/2;
    for(;k!=0 && max!=min+1;){
        if(a[k-1]>n){
            max=k;
            k=(min+max)/2;
        } else if(a[k-1]<n){
            min=k;
            k=(min+max)/2;
        } else if(a[k-1]==n){
            printf("present\n"); break;
        }
    }
    if(k==0 || max==(min+1))
        printf("absent\n");
    }
    return 0;
}
