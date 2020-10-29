#include<stdio.h>
void main()
{
    int n,i,j;
    float sum=0,pro=1,dif;
    printf("Enter the no of terms");
    scanf("%d",&n);
    printf("the sum of the series \n");
    for (i=1;i<=n;i++)
    {
        pro=1;
        for (j=1;j<=i;j++)
        {
            pro*=j;
        }
        if (i==n)
            printf(" 1/(%0.0f) = ", pro);
        else
            printf("1+ 1/(%0.0f) + ", pro);

        sum=1+(1/pro);
    }
    printf("%f",sum);
}
