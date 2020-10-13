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
  retrn 0;
}
