#include <stdio.h>
#include <string.h>

void main()
{
    int i, n, len;
    char str[100],strcopy[100];
    printf("Enter the text(<100 characters)\n");
    gets(str);
    len=strlen(str);
    printf("Enter the number of last characters for copying\n");
    scanf("%d",&n);
    for(i=n;i>0;i--)
    {
        if(str[len-i]>='a'&&str[len-i]<='z')
            strcopy[n-i]=str[len-i]-('a'-'A');
        else strcopy[n-i]=str[len-i];
    }
    strcopy[n]='\0';
    puts(str);
    puts(strcopy);
}
