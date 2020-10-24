#include<stdio.h>
void main()
{
    int i=6;
    for (i=6;i<=66;i+=2)
        printf("%d   ",i);

    printf("\n \n \n");

    for (i=7;i<=67;i+=2)
        printf("%d   ",i);
    int sum=0;

    printf("\n \n \n");

    for(i=1;i<=15;i++)
    {
        sum=sum+i;
        if (i==15)
            printf("%d = %d",i,sum);
        else printf (" %d + ",i);
    }


    printf("\n \n \n");

    for(i=15;i<=45;i+=2)
    {
        sum=sum+i;
        if (i==45)
            printf("%d = %d",i,sum);
        else printf (" %d + ",i);
    }


    printf("\n \n \n");

    for(i=1;i<=50;i+=3)
    {
        sum=sum+i;
        if (i==49)
            printf("%d = %d",i,sum);
        else printf (" %d + ",i);
    }




}
