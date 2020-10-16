#include<stdio.h>
void main()
{
    int i=0,num,num1,j=0;
    printf("Enter the last no to be printed :- ");
    scanf("%d",&num);
    num1=num;
    int linecount=0;
    while (num>0)
    {
        if(linecount>9)
        {
            printf("\n");
            linecount=1;
        }
        else linecount++;

        printf("\t %d", num);
        num--;
    }
    printf("\n \n \n");
    i=1;
     while (i<=num1)
    {
        if(linecount>9)
        {
            printf("\n");
            linecount=1;
        }
        else linecount++;

        printf("\t %d", i++);

      }
}
