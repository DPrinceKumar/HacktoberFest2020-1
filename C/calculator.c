// Program to solve a simple calculation  
#include<stdio.h>

int main()
{
    char operator;
    float num1, num2;

    printf("Enter calculation: ");
    scanf("%f %c %f", &num1, &operator, &num2);     // Taking the input
    // Calculation for output
    switch(operator)
    {
        case '+': printf("%.2f ",num1+num2);    // For addition
                break;

        case '-': printf("%.2f ",num1-num2);    // For subtraction
                break; 

        case '*': printf("%.2f ",num1*num2);    // For multiplication
                break; 

        case '/': printf("%.2f ",num1/num2);    // For division
                break; 

        default: printf("Invalid operator!");   // For Invalid operator
    }
    
}
