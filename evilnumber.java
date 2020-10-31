import java.io.*;
class evil
{
    public static void main()throws IOException
    {int n=0,c=0,a=0;
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("enter the number");
        n=Integer.parseInt(in.readLine());
        for(int i=n;i>0;i=i/2)
        {
            a=i%2;
        }
        if(a==1)
        {
            c++;
        }

        if(c/2==0)
        {
            System.out.println("evil number");
        }
        else
        {
            System.out.println("not");
        }
    }
}
