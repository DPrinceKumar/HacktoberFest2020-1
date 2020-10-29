#include <stdio.h>

int main()
{
    long decimalnum, quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];

    printf("Enter decimal number: ");
    scanf("%ld", &decimalnum);

    quotient = decimalnum;

    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    // display integer into character
    for (i = j; i >= 0; i--)
            printf("%c", hexadecimalnum[i]);
    return 0;
}
