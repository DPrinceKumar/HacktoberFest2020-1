// pattern
/* 1****
    12***
    123**
    1234*
    12345*/
// by utsav jain
// date : 02.10.2020
#include<stdio.h>
void main()
{
    int i=0,j=0,r=0,c=1;
    printf("enter the value of no of rows");
    scanf("%d", &r);

    for (i=1;i<=r;i++)
    {
        for (j=1;j<=r;j++)
        {
            if (i>=j)
            {
                printf("%d", j);
            }
            else printf("*");
        }
        printf("\n");
    }
}
