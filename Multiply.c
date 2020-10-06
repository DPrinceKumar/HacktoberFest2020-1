#include<stdio.h>
void main()
{
    int num1, num2, product;
    printf("\n=== PRODUCT CALCULATOR ===\n");
  
    // Getting the input
    printf("\nEnter the First Number: ");
    scanf("%d",&num1);
    printf("\nEnter the Second Number: ");
    scanf("%d",&num2);
  
    // Calculating the product
    product = num1 * num2;
  
    printf("\nThe Product of those numbers is %d", product);
}
