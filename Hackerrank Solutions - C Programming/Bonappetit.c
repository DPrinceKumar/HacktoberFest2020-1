//Hactoberfest2020
#include<stdio.h>
int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    int i,a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int sum = 0;
    for(i=0;i<n;i++)
        sum += a[i];
    int paid;
    scanf("%d",&paid);
    int toPaid = sum-a[p];
    if((toPaid)/2==paid)
        printf("Bon Appetit\n");
    else
        printf("%d\n",paid-(toPaid)/2);
    return 0;
}
