/* ============
   *          *
   *          *
   *          *
   *          *
   ============
*/
#include<stdio.h>

void p1(int l, int b)
{
    int i=0,j=0;

    for (i=0;i<l;i++)
    {

            for (j=0;j<b;j++)
            {
                if (i==0 || i==l-1)
                    {
                        printf("=");
                    }
                    else if (j==0 || j==b-1)
                        {
                            printf("*");
                        }
                        else printf(" ");
            }
            printf("\n");

    }
}

void main()
{
        int l,b;
        printf("Enter the length of rectangle");
        scanf("%d", &l);
        printf("Enter the breadth of rectangle");
        scanf("%d", &b);
        p1(l,b);
}
