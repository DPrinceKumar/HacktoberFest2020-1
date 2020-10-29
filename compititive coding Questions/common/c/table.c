# include <stdio.h>
#include<conio.h>

int main() 
{
    int a;
    Clrscr();
    printf("Enter the number : \n");
    scanf("%d" , &a);
    for(int i=1;i<=10;i++){
        printf("a*i = %d\n", a*i );
    }
    getch ();
    return 0;
}
