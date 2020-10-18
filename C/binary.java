import java.util.Scanner;
class Binary
{
   public static void main(String args[])
   {
      int i, n, item, a[], f, l, m;
      Scanner input = new Scanner(System.in);
      System.out.println("Enter number of elements:");
      n=input.nextInt();
      a=new int[n];
      System.out.println("Enter integers");
      for (i = 0; i< n; i++)
          a[i] = input.nextInt();

      System.out.println("Enter the search value:");
      item = input.nextInt();
      f= 0;
      l = n-1;
      m= (f + l)/2;

      while(f<= l )
      {
         if ( a[m] < item )
           f= m+ 1;
         else if ( a[m] == item )
         {
           System.out.println(item + " found at location " + (m + 1) + ".");
           break;
         }
         else
         {
             l=m- 1;
         }
         m=(f + l)/2;
      }
      if ( f > l ){
          System.out.println(item + " is not found.\n");
	  }
   }
}
