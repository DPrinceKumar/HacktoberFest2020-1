#include<stdio.h>
void main()
{
	int A[5]={3,2,1,4,1},a=5;
	for(int i=0;i<a;i++)
	{
		int min=i,j=i+1;
		while(j<a)
		{
			if(A[j]<A[min])
			{
				min=j;
			}
			j++;
		}
		//swap A[min] and A[i]
		int temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}
	for(int i=0;i<a;i++)
	{
		printf("%d",A[i]);
	}
}