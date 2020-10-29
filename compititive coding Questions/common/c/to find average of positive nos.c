#include<stdio.h>
void main()
{
    int n=0,i=0,j=0, sum=0;
    float avg;
    while (n!=-1)
    {
        printf("Enter a no (-1 to end ) => ");
        scanf("%d",&n);

        if (n>0)
        {
            sum+=n;
            j++;
        }
    }
    avg=sum/j;
    printf("the average of the nos is => %0.2f",avg);

}
