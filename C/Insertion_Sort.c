#include<stdio.h>
void main()
{
    int A[]={21,23,20,14,8};
    int a=5;
    for(int i=1;i<=a;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(A[j]<A[j-1])
            {
                int temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
    for(int i=0;i<a;i++)
    {
        printf("%d\t",A[i]);
    }
}

