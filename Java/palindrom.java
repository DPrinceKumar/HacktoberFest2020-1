class PalindromeExample{  
 public static void main(String args[]){  
  int r,sum=0,temp;    
  int n=454;//It is the number variable to be checked for palindrome  
  
  temp=n;    
  while(n>0){    
   r=n%10;  //getting remainder  
   sum=(sum*10)+r;    
   n=n/10;    
  }    
  if(temp==sum)    
   System.out.println("palindrome number ");    
  else    
   System.out.println("not palindrome");    
}  
}  
//
package string;

public class palindrome {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s="NAMAN";
		String rev="";
		for(int i=s.length()-1;i>=0;i--)
		{
			rev=rev+s.charAt(i);
		}
		if(s.equals(rev))
		{
			System.out.println("It is a Palindrome");
			
		}
		else
		{
			System.out.println("It is not a panlindrome");
		}

	}

}
