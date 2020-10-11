import java.util.*;
class Palindrome
{
    public static void main(String s[])
    {
    Scanner k=new Scanner(System.in);
    System.out.println("Enter the first String");
    String s1=k.nextLine();
    String palindrome="";;
    for(int i=0;i<s1.length();i++)
    {
        palindrome=s1.charAt(i)+palindrome;
    }
    if(palindrome.equals(s1))
    System.out.println("The reversed string is is "+ palindrome +" and it is a palindrome");
    else
    System.out.println("The reversed string is is"+ palindrome +"and it is not a palindrome");
    
}
}
    
    
 