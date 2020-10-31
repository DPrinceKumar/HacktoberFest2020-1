#include<stdio.h>
#include<conio.h>
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
	char prefix[SIZE],infix[SIZE];
	int i,index=0;
	clrscr();

	puts("Enter the postfix:");
	gets(prefix);

	for(i=0;prefix[i]!=NULL;i++)
	{
		switch(prefix[i])
		{
			case '+':
			case '-':
			case '/':
			case '*':
			case '$':
			case '^':
				push(prefix[i]);  // simply push it to stack if operator comes in prefix.
				break;
			default:
				infix[index++]=prefix[i];  // this instruction to add oprand to the infix exp(output)
				infix[index++]=pop(); // this instruction to add operator from stack to infix exp(output)
		}

	}
	infix[index]=NULL;  // '\0' backslash zero
	printf("\nThe infix expression = %s",infix);
	getch();
}
