/* *
   **
   ***
   ****
   ***
   **
   *
*/
#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("enetr the no of rows");
    scanf("%d",&n);
    k=n;
    for (i=0;i<n;i++)
    {
        for (j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
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
