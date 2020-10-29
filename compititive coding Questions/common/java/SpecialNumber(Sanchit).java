//A number is known as Special number when sum of the factorial of digits is equal to the original number (given number)
import java.util.Scanner;

public class SpecialNumber
{
    public static void main(String[] args)
    {
        int number, num, rem,
        sumOfFactorial = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number:");
        number = scanner.nextInt();
        num = number;
        while (num > 0)
        {
            rem = num % 10;
            int fact=1;
            for(int i=1;i<=rem;i++)
            {
                fact=fact*i;
            }
            sumOfFactorial = sumOfFactorial+fact;
            num = num / 10;
        }
        if(number==sumOfFactorial)
        {
            System.out.println("Special Number" );
        }
        else
        {
            System.out.println("Not Special Number" );
        }
    }
}
