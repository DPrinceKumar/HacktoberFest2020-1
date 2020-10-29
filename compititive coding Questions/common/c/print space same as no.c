#include<stdio.h>
void main()
{
    int n,i=1,j=0;
    char ch=' ';
    scanf("%d",&n);
    while (i<=n)
    {   j=0;
        while (j<i)
            {
                printf("%c",ch);
                j++;
            }

        printf ("%d",i);
        i++;
    }
}
