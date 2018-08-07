#include <stdio.h>
#include <string.h>

void main()
{
    int i, count;
    char str[100];
    printf("Enter the text(<100 characters)\n");
    gets(str);
    for(i=0,count=0;i<strlen(str);i++)
    {
        if(str[i]==';')
            continue;
        else if(str[i]==',')
        {
            str[count]='.';
            count++;
        }
        else
        {
            str[count]=str[i];
            count++;
        }
    }
    str[count]='\0';
    puts(str);
}
