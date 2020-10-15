
import java.util.Scanner;
public class armstrong {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       Scanner sc = new Scanner(System.in);
       System.out.println("Enter a number");
       int n = sc.nextInt();
       int f=n;
       int sum=0;
       if(n==0)
       {
    	   System.out.println("Armstrong number");
    	   
       }
       else
       {
    	   while(n!=0)
    	   {
    		   int a = n%10;
    		   sum += a*a*a;
    		   n=n/10;
    	   }
    	   if(sum==f)
    	   {
    		   System.out.println("Armstrong number");
    	   }
    	   else
    	   {
    		   System.out.println("Not an Armstrong number");
    	   }
       }
	}

}
