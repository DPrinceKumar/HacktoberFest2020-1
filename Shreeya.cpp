#include<stdio.h>
#include<conio.h>
int main()
{
int number, reverse_number = 0, temp_number;
printf("Enter a number to check palindrome value:"); // allow user to enter a number
scanf("%d", &number); // takes value from user
temp_number = number;  //store number to temp_number
while (number != 0)
{
reverse_number = reverse_number * 10;
reverse_number = reverse_number + number % 10;
number = number / 10;
}
if(temp_number == reverse_number) // check reverse number with original number
{
printf("Given number is palindrome"); //if match, print palindrome
}
else
{
printf("Given number is not palindrome"); // If it don’t match with original print not palindrome
}
return 0;
}
