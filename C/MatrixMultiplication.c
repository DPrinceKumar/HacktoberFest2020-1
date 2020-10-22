#include<stdio.h>

void main()
{
	int a[3][3],b[3][3],c[3][3];
	printf("Enter the elements of first matrix: ");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements of second matrix: ");
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<3;i++)
		{
			scanf("%d",&b[j][i]);
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{	c[i][j]=0;
			for(int k=0;k<3;k++)
			{
				c[i][j]=a[i][k]*b[k][j]+c[i][j];
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
}