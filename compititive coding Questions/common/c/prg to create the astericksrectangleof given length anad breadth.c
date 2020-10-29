#include<stdio.h>
void main()
{
    int l,b,i,j;
    printf("Enter the length of rectangle :- ");
    scanf ("%d", &l);

        printf("Enter the breadth of rectangle :- ");
    scanf ("%d", &b);

    for (i=0;i<b;i++)
    {
        for (j=0;j<l;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
