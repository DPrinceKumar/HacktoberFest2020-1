#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("Enetr the no of rows");
    scanf("%d",&n);
    k=n;
    for (i=0;i<n;i++)
    {
        for (j=k;j>0;j--)
        {
            printf("*");
        }
        k--;
        printf("\n");
    }
}
