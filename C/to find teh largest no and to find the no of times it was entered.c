// to be done to enter n nos and to find maximum of those nos and to to find no of times the no occured

#include<stdio.h>

int counter(int n)
{
    int num1,j=0;
    int num2;
    num1=n;
    num2=num1;
    if (num2==num1)
    {
        j+=1;
    }
    else if (num2!=num1)
    {
        j=0;
    }
    return j;
}
void main()
{
    int n=0,i=0,j=0,num=0,num1=0,num2=0;

    while (n!=-1)
    {
        printf("Enter a no (-1 to end ) => ");
        scanf("%d",&n);

        if (n>=num)
        {
            num = n;
            num1=n;
            j=counter(n);
        }
    }

    printf("the greatest no is %d and the no of times it occur is %d", num,j);
}
