// number series using a for loop

#include<stdio.h>
void main()
{
    int i=0, j=0, num=0;
    printf("Enter the last no to be printed (0 to 10) :- ");
    scanf("%d",&num);
    for (i=1;i<=num;i++)
    {
        printf("\t %d \n", i);
    }


}
