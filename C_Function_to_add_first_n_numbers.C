#include <stdio.h>
#include<conio.h>
int getsum(int );
void main()
{
int n;
clrscr();
printf("Enter last number n : ");
scanf("%d",&n);
printf("\n SUM of first %d numbers = %d",n,getsum(n));
getch();
}
int getsum(int a)
{
return ((a*(a+1))/2);
}
