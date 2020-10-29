// pattern
/* *
    **
    ***
    ****
    ******/
// by utsav jain
// date : 02.10.2020

#include<stdio.h>
void main()
{
    int i=0,j=0,r=0;
    printf ("enter he no of rows");
    scanf("%d", &r);
    for (i=1;i<r;i++)
    {
        for (j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
