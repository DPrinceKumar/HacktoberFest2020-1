//To find pallindrome words in a sentence
import java.util.*;
class letter
{
    public static void main()
    {
        Scanner in=new Scanner (System.in);
        String s1,w;
        int n,i,l,c=0;
        System.out.println("Enter a sentence");
        s1=in.nextLine();
        s1=s1.toUpperCase();
        StringTokenizer st=new StringTokenizer(s1);
        n=st.countTokens();
        System.out.println("Words starting and ending with same letter are:");
        for(i=0;i<n;i++)
        {
            w=st.nextToken();
            l=w.length();
            if(w.charAt(0)==w.charAt(l-1))
            {
                System.out.println(w);
                c++;
            }
        }
        if(c==0)
        {
            System.out.println("No such word found");
        }
    }
}
