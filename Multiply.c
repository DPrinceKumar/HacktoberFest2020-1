int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d",a*b);
  return 0;

#include <stdio.h>
//Main method
void main() {
	int num1,num2,multiple;
	printf("Enter first number:");
	scanf("%d",&num1);
	printf("Enter second number:");
	scanf("%d",&num2);
	
	multiple = num1 * num2;
	
	printf("%d * %d = %d",num1,num2,multiple);}
  
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

}
//Created by rupali	
#include<stdio.h>
void main(){
    float n1,n2,mul;
    printf("\nEnter number1:");
    scanf("%float",&n1);
    printf("\n Enter number2:");
    scanf("%f",&n2);
    printf("Result of multiply of two numbers:%f",n1*n2);
}
