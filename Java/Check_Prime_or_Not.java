import java.util.Scanner;

public class Check_Prime_or_Not{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter number to check Prime or Not.");
        int num = scan.nextInt();
        int flag=1;
        for (int i = 2; i < num; i++) {
            if (num % i ==0) {
                System.out.println("Entered number is not Prime!");
                flag =0;
                break;
            }
        }
        if (flag==1) {
            System.out.println("Entered number is Prime!");
        }
    }
}

//Created by Shrikant Daund