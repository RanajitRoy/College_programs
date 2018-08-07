#include <stdio.h>

void main()
{
    char c;
    printf("Enter a character\n");
    c=getchar();
    switch(c)
    {
        case 'a': printf("This is a vowel\n"); break;
        case 'e': printf("This is a vowel\n"); break;
        case 'i': printf("This is a vowel\n"); break;
        case 'o': printf("This is a vowel\n"); break;
        case 'u': printf("This is a vowel\n"); break;
        default :  printf("This is not a vowel\n");
    }
}
