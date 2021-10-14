import java.util.*;
public class intocm 
{
    public static void main(String[] args) 
    {
        int inch=0;
        double cm = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter value in inch");
        inch = sc.nextInt();
        // 1 inch = 2.54 cm
        cm=2.54*inch;    
        System.out.println("Value in cm = "+cm);
        sc.close();
    }    
}
