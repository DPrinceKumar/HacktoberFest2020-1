/*Redundant Braces
You are given a mathematical formula consisting of '*', '-', '+', '/'. The formula also contains brackets '()'. These formulas are given as assignments to the students 
for evaluation but the Teacher has made a small mistake while preparing the assignment. He has added redundant braces.
If the formula is ((a+b))+c, you can see there is an extra bracket around a+b, which means this formula has 1 redundant bracket.
Your task is to find whether the given formula consists of a redundant bracket or not.

Example
Input
((a+b))
Output
1   */

#include <stdio.h>
#include <stdlib.h>
char stack[1000001];

int top=-1;

char pop(){

	if(top==-1){

		return 0;

	}

	else

		return stack[top--];

}

void push(char x){

	stack[++top]=x;

}
int operator(char x){
	if(x== '+'||x=='-'||x=='*'||x=='/'){
		return 1;
	}
	else
		return 0;

}
int out(char arr[]){
	for(int i=0;arr[i]!='\0';i++){
		char x=arr[i];
		if(operator(x)){
			push(x);
		}
		else if(x=='('){
			push(x);
		}
		else if(x==')'){
			if(stack[top]=='('){
				return 1;
			}
			else if(stack[top]!='('){
			while(stack[top]!='('){
				pop();
			}
			pop();
		}

		}
	}
	return 0;

}
int main() {
	char arr[100001];
	scanf("%s",arr);
	int k=out(arr);
	printf("%d",k);
	return 0;
}
