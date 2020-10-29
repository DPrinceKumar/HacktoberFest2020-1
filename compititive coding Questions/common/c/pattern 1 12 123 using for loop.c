// pattern
/* 1
    12
    123
    1234
    1234*/
// by utsav jain
// date : 02.10.2020
#include<stdio.h>
void main()
{
    int i=1,j=1,num=1,r;
    printf ("enter he no of rows");
    scanf("%d", &r);
    for (i=1;i<=r;i++)
    {
        num=1;
        for (j=1;j<=i;j++)
        {
            printf(" %d ",num);
            num++;
        }
        printf("\n");
    }
}
