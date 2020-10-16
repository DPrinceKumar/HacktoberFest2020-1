import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Subset {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
	    int test = sc.nextInt();
	    for(int i=0 ; i<test ;i++){
	        int num = sc.nextInt();
	        int [] arr = new int[num];
	        for(int j=0 ; j<num ; j++){
	            arr[j] = sc.nextInt();
	        }
	        Arrays.sort(arr);
	        ArrayList<String> al = new ArrayList<>();
	        subset(arr,0,num-1,"",al);
	        Collections.sort(al);
	        for(String a: al){
	            System.out.print("("+a+")");
	        }
	        System.out.println();
	    }

	}
	public static void subset(int[] arr , int left , int right, String string,ArrayList<String>al){
	     if(left>right){
	         string = string.trim();
	         if(!al.contains(string))
	            al.add(string);
	         return;
	     }
	     subset(arr ,left+1 , right , string,al);
	     string = string+arr[left]+" ";
	     subset(arr,left+1,right,string,al);
	 }

}
