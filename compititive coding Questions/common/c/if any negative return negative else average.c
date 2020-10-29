#include<stdio.h>
void main()
{
    int sum=0,n,i=0;
    float avg;
    while (n!=-1)
    {
        printf("Enter the no => ");
        scanf("%d",&n);

        if (n<0)
        {
            printf("YOU ENTERED A NEGATIVE NO i.e. %d",n);
            exit(0);
        }
        if (n>0)
        {
            sum+=n;
            i++;
        }

    }
    avg=sum/i;
    printf("The average of the nos entered is %0.2f", avg);
}
