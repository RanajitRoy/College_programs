#include <stdio.h>
#include <string.h>
#include <math.h>

int top=-1;
char post[100];	// stack for input of post-fix and evaluation
struct charvalues	// structure to store the variables with their corresponding values
{
	char c;
	int i;
} value[52];

void getvalue();
int calc();

void main()
{
	printf("Enter the post-fix expression (without spaces)\n");
	gets(post);	// input of post-fix expression
	printf("The result is %d\n",calc());
}

void getvalue()
{
	int len=strlen(post), i, j, count=-1;
	char op[60];
	for(i=0;i<len;i++)	//loop to isolate the variables from expression for input
		switch(post[i])
		{
			case 'A'...'Z': op[++count]=post[i]; break;
			case 'a'...'z': op[++count]=post[i]; break;
		}
	value[++top].c=op[0];
	for(i=0;i<=count;i++)	//discarding repeated variables for easier input
	{
		for(j=top;j>=0;j--)
			if(op[i]==value[j].c)
				break;
		if(j==-1)
			value[++top].c=op[i];
	}
	for(i=0;i<=top;i++)	//input for value of the variables in the expression
	{
		printf("\n%c = ", value[i].c);
		scanf("%d", &value[i].i);
	}
}

int calc()
{
	getvalue();
	int i, len=strlen(post), cal[50], temp=-1, j;
	for(i=0;i<=len;i++)	//calculations done here using a stack(cal[]) and top ptr(temp)
	{
		switch(post[i])
		{
			case 'A'...'Z':	for(j=0;j<=top;j++)
								if(post[i]==value[j].c)
									cal[++temp]=value[j].i;
							break;
			case 'a'...'z':	for(j=0;j<=top;j++)
								if(post[i]==value[j].c)
									cal[++temp]=value[j].i;
							break;
			case '^':	cal[temp-1]=(int)pow((double)cal[temp-1], (double)cal[temp]);
						temp--; break;
			case '*':	cal[temp-1]=cal[temp-1]*cal[temp];
						temp--; break;
			case '/':	cal[temp-1]=cal[temp-1]/cal[temp];
						temp; break;
			case '+':	cal[temp-1]=cal[temp-1]+cal[temp];
						temp--; break;
			case '-':	cal[temp-1]=cal[temp-1]-cal[temp];
						temp--; break;
		}
	}
	return cal[0];
}
