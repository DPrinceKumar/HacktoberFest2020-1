import java.util.Scanner;

public class PrimeOrNot {
	public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter number to check Prime or Not.");
        int num = scan.nextInt();
        
        primeOrNot(num);
        
    }
	
	public static void primeOrNot(int num){
        int count = 0;
        
        if(num == 1){
            System.out.println("1 is nether a prime number nor a composite number");
        }
        else
        {
            for(int i=1;i<=num;i++){
                if(num%i == 0){
                    count++;
                }
                
            }
            if(count==2){
                System.out.println("Prime Number");
            }
            else
            {
                System.out.println("Not a prime number");
            }
        }
    }
}


//Created by Atul Jha
