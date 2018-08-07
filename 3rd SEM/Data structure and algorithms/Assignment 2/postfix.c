#include <stdio.h>
#include <string.h>

int top=-1, optop=-1;
char postfix[100], infix[100], operand[100];

void pop();
void push(char);
void infix_to_postfix();
int precedence(char);

void main()
{
	printf("Enter the infix expression (without any spaces and <90 characters)\n");
	gets(infix);
	infix_to_postfix();
}

void infix_to_postfix()
{
	int i, len=strlen(infix);
	infix[len]=')';
	operand[0]='(';
	optop=0;
	for(i=0;i<len+1;i++)
	{
		if(infix[i]>='a' && infix[i]<='z')
			push(infix[i]);
		else if(infix[i]>='A' && infix[i]<='Z')
			push(infix[i]);
		else if(infix[i]=='(')
		{	operand[optop+1]='('; optop++; }
		else if(infix[i]==')')
		{
			while(operand[optop]!='(')
				{
					push(operand[optop]);
					optop--;
				}
				optop--;
		}
		else if(infix[i]=='^'||'*'||'/'||'+'||'-')
		{
				while(precedence(operand[optop])>=precedence(infix[i]))
				{
					push(operand[optop]);
					optop--;
				}
				operand[optop+1]=infix[i];
				optop++;
		}
		else { printf("invalid statement\n"); return; }
	}
	printf("The postfix statement is %s\n", postfix);
	top=optop=-1;
}

void push(char c)
{
	if(top>=99)
	{
		printf("stack overflow");
		return;
	}
	else
	{
		postfix[top+1]=c;
		top++;
	}
}

void pop()
{
	if(top<0)
	{
		printf("Stack underflow\n");
		return;
	}
	else --top;
}

int precedence(char c)
{
	switch(c)
	{
		case '^':	return 5;
		case '*':	return 4;
		case '/':	return 3;
		case '+':	return 2;
		case '-':	return 1;
		default:	return 0;
	}
}
