package java_scratch;
import java.util.*;
public class demo_2 
{

	public static void main(String[] args)
	{
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter  a no. :");
			int yr = sc.nextInt();
			if(yr >= 999 && yr <= 9999)
			{
				if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
					System.out.println(yr + " is a leap year!!");
				else
					System.out.println(yr + " is not a leap year!!");
			}
			else
			{
				System.out.println("Invalid input!!");
			}
	}

}
