
/*###########################Program start################################## */

/*OUTPUT
enter the size of the array
5
enter the elements of the array
5
4
1
8
9
the sorted array is
1	4	5	8	9*/

/*insertion sort*/
#include<stdio.h>
void main()
{
	int a[100];
	int i,j,n,temp,key;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	printf("enter the elements of the array\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>=0 && a[i]>key)
		{
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
			i=i-1;
		}
		temp=a[i+1];
		a[i+1]=key;
			key=temp;
	}
	printf("the sorted array is ");
	for(i=0;i<n;i++)
	{
	printf("%d\t",a[i]);
	}
}


/*###########################Program End################################## */
