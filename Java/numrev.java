/*class numrev{
	static int nodigits(int n){
		int c=0;
		while(n>0){
			c++;
			n/=10;
		}
		return c;
	}
	static void cal(int num){
		int dig=nodigits(num);
		int powten=(int)Math.pow(10,dig-1);
		for(int i=0;i<dig-1;i++){
			int firstdigit=num/powten;
			int left=((num*10)+firstdigit)-(firstdigit*powten*10);
			System.out.println(left);
			num=left;
		}
	}
		public static void main(String[] args){
			int num=1234;
			cal(num);
		}
}*/
import java.util.*;
public class numrev {

	/*public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		
		for(int i=1; i<=n; i++)
		{
			for (int j = i; j < i + n; j++) {
				int k = j % n;
				if (k==0) {
					k = n;
				}
		        System.out.print(k);
		    }
			
			System.out.println("");
		}
	}*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=1;i<=n;i++){
			for(int j=i;j<i+n;j++){
				int k=j%n;
				if(k==0){
					k=n;
				}
				System.out.print(k);
			}
			System.out.println();
		}
	}
}
			