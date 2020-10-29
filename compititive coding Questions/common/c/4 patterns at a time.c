#include<stdio.h>

void p1(int n);
void p2(int n);
void p3(int n);
void p4(int n);

void main()
{
    int n;
    printf("Enter the no of rows");
    scanf("%d", &n);
    p1(n);
    printf("\n");
    p2(n);
    printf("\n");
    p3(n);
    printf("\n");
    p4(n);
}

void p1(int n)
{
    int i=0,j=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {

            if (j==i)
            {
                printf("%d",n);
            }

            else printf("$");
        }
        printf("\n");
    }
}

void p2(int n)
{
    int i=0,j=0;
    int k=n;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (j==k-1)
            {
                printf("%d",n);
            }
            else printf("$");
        }
        k--;
        printf("\n");
    }
}

void p3(int n)
{
    int i=0,j=0;
    int k=n;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (j>k-1)
            {
                printf("%d",n);
            }
            else printf("$");
        }
        k--;
        printf("\n");
    }
}

void p4(int n)
{
    int i=0,j=0;
    int k=n;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (j<i)
            {
                printf("%d",n);
            }

            else printf("$");
        }
        printf("\n");
    }
}
