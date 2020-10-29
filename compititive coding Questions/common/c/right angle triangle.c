#include<stdio.h>
void main()
{
    int i=0,j=0,n=0;
    printf("Enter the no of rows");
    scanf("%d",&n);


    for (i=0;i<n;i++)
    {
        for (j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
