#include<stdio.h>

int main()
{
	int a,b,sub;

	//Read value of a
	printf("Enter the first no.: ");
	scanf("%d",&a);

	//Read value of b
	printf("Enter the second no.: ");
	scanf("%d",&b);

	//formula of subtraction
	sub= a-b;
	printf("subtract is = %d\n", sub);

	return 0;

#include<stdio.h>
int main()
{
  int a,b,c;
  printf("Enter Two numbers: ");
  scanf("%d %d",&a,&b);
  if(a>b)
  {
    c=a-b;
  }
  else if(b>a)
  {
    c=b-a;
  }
  printf("Subtraction of given two numbers is %d",c);
  return 0;

#include<stdio.h>

int main(){
int a,b;
 scanf("%d %d",&a,&b);
  printf("%d",a-b);
#include<iostream>
using namespace std;

int main()
{
  int num1, num2;
  
  cin>>num1>>num2;
  
  if(num1 > num2)
    cout<<(num1 - num2);
  else
   cout<<(num2 - num1);

}
