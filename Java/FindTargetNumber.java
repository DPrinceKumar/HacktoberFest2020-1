import java.util.Scanner;

public class FindTargetNumber {

    static Scanner kb = new Scanner(System.in);
    private static int factor = 1000;
    private static int guess = (int)(Math.random() * factor + 1);
    private static int count;


    public static void main(String[] args) {

        System.out.print("Type your target: ");
        int target = kb.nextInt();

        if(target > factor){   // limits size of user input
            System.out.println("Error, please type a number within range of the factor");
            System.exit(0);
        }

        System.out.println("Searching...");

            while (guess != target) {   // loop to continue searching for when target has not been found.
                System.out.print("Keep searching: ");
                System.out.println(guess);
                count++;
                changeValue();
            }

            while (guess == target ){   // loop to find target.
                System.out.println("Found, the number is: " + target);
                count++;
                System.out.println("Target found within: " + count + " attempts");
                break;
            }
        }

    public static int changeValue(){    // method for changing the value of guess

        int newGuess = (int)(Math.random() * factor + 1);
        guess = newGuess;
        return guess;

    }


}
