//Fibronocci Patterns
#include<stdio.h>
void main()
	{
		int n,b,c;
		printf("How many number of terms do you want to print:");
		scanf("%d",&n);
		for(int i=1,b=0,c=1;i<=n;i++)
		{
			printf("%d\t",c);
			int temp=c;
			c=c+b;
			b=temp;
		}
	}