#include<stdio.h>
void main()
{
    int n,b,min=0,max=0,sum=0,i=0;
    float avg;
    while(n!=-1)
    {
        printf("Enter the integer => ");
        scanf("%d",&n);

        if (n>max)
        {
            max=n;
        }
        b=max;

        if (n<min)
        {
            min=n;
        }
        sum+=n;
        i++;
    }
    avg=sum/i;
    printf(" THE MIN , MAX AND AVG ARE :- %d , %d , %f",min,max,avg);

}
