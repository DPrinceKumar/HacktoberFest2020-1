HELLO!!

import java.util.*;
class Palprime
{
    public int Pal(int n)
    {
        int d=0;int s=0;
        for(int i=n;i>0;i=i/10)
        {
            {
                d=i%10;
                s=s*10+d;
            }
        }
        return(s);
    }
     public int prime(int n)
     {
            int c=0;
            for(int i=1;i<=n;i++)
            {
             if(n%i==0)
            {
            c++;
            }
            }
            return(c);
     }
     public static void main()
     {
         Scanner in=new Scanner(System.in);
         System.out.println("Enter the no");
         int n=in.nextInt();
         Palprime obj=new Palprime();
         int s1=obj.Pal(n);
         int c1=obj.prime(n);
         if((s1==n)&&(c1==2))
         System.out.println("Palprime no"+n);
         else
         System.out.println("Not a palprime no"+n);
     }
}
