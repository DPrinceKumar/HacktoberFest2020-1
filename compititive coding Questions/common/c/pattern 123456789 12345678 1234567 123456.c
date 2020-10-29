/* 123456789
   12345678
   1234567
   123456
   12345
   1234
   123
   12
   1
*/

#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("Enter a no for pattern");
    scanf("%d",&n);
    k=n;
    for (i=0;i<n;i++)
        {
                for (j=k;j>0;j--)
                {
                    printf(" %d ",k);
                }
                k--;
                printf("\n");

        }


}
