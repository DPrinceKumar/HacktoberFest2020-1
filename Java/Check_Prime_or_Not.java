import java.util.Scanner;

public class Check_Prime_or_Not{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter number to check Prime or Not.");
        int num = scan.nextInt();

        if (checkPrime(num)) {
            System.out.println("Entered number is Prime!");
        } else {
            System.out.println("Entered number is not Prime!");
        }
    }
    
    public static boolean checkPrime(int num) {
         if (num % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

//Created by Shrikant Daund
