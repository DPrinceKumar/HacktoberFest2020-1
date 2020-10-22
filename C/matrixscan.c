#include<stdio.h>
void main()
{
	int a[2][3];
	int i=2,j=3;
	//printf("Enter the number of rows: ");
	//scanf("%d",&i);
	//printf("Enter the number of columns: ");
	printf("Enter the elements of the matrix: ");
	for(int p=0;p<i;p++)
	{
		for(int k=0;k<j;k++)
		{
			scanf("%d",&a[p][k]);
		}
	}
	for(int p=0;p<i;p++)
	{
		for(int k=0;k<j;k++)
		{
			printf("%d\t",a[p][k]);
		}
		printf("\n");
	}
}