import java.util.*;
class Factorial
{
  public static void main() //main function
   {
      Scanner in =new Scanner(System.in);
      System.out.println("Enter number ");
      int n =in.nextInt(); //accepting no.
      Factorial obj = new Factorial();
      long f = obj.fact(n);
      System.out.println("Factorial ="+f); //displaying factorial
   }
  public long fact(int n) //recursive fact()
  {
      if(n<2)
      return 1;
      else 
      return (n*fact(n-1)); 
  }
}
