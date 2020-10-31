#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 500
int top=-1;
char stk[SIZE];
void push(char e)
{
	stk[++top]=e;
}
char pop()
{
	return stk[top--];
}
void main()
{
	char postfix[SIZE],infix[SIZE];
	int i,index=0;
	clrscr();

	puts("Enter the postfix:");
	gets(postfix);

	for(i=strlen(postfix)-1;i>=0;i--)
	{
		switch(postfix[i])
		{
			case '+':
			case '-':
			case '/':
			case '*':
			case '$':
			case '^':
				push(postfix[i]);  // simply push it to stack if operator comes in postfix.
				break;
			default:
				infix[index++]=postfix[i];  // this instruction to add oprand to the infix exp(output)
				infix[index++]=pop(); // this instruction to add operator from stack to infix exp(output)
		}

	}
	infix[index]=NULL;  // '\0' backslash zero
	printf("\nThe infix expression = %s",infix);
	getch();
}
