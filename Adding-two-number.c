#include <stdio.h>
int main()
{
  int x, y, z;

  printf("Enter two numbers to add\n");
  scanf("%d%d", &x, &y);

  z = x + y;

  printf("Sum of the numbers = %d\n", z);

  return 0;
#include <stdio.h>   
void main() {
	int num1,num2;
	printf("Enter first number:");
	scanf("%d",&num1);
	printf("Enter second number:");
	scanf("%d",&num2);
	
	printf("%d + %d = %d",num1,num2,num1 + num2);
}
  
#include <stdio.h>  
void main() {
    int number1, number2, sum;
    
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);
    sum = number1 + number2;      
    
    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}
