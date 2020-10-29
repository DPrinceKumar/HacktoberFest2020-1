#include<stdio.h>
#include<math.h>

void pie(int n);

void main()
{
    int n;
    printf("Enter the limit");
    scanf("%d",&n);
    pie(n);
}

void pie(int n)
{
    int i=1,sq=0;
    float sum=0, theta,inv;
    for (i=1;i<n+1;i++)
    {
        sq=i*i;
        inv=1/sq;
        sum=sum+inv;
        printf("\n sum is => %f,%f",inv,sum);
    }
    theta= sqrt(6*(sum));
    printf("\n the value of pie is %f", theta);

}
