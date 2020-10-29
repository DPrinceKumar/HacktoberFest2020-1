// compound interest
// by utsav jain
// date : 02.10.2020
#include<stdio.h>
void main()
{
    int yrs, looper=1;
    double prsnval,fnlval,rte;

    printf("Enter the principal amt value");
    scanf("%lf", &prsnval);

    printf("Enter the period");
    scanf("%d", &yrs);

    printf("Enter the rate of interest");
    scanf("%lf", &rte);

    printf("\n year    final values");
    printf("\n ====    ==========");

    for ( looper = 1 , fnlval = prsnval  ; looper <=yrs ; looper++)
    {
        fnlval=fnlval*(1+rte/100.0);
        printf("\n%3d %11.2lf \n", looper,fnlval);
    }
}
