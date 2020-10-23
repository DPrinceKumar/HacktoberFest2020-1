
import java.util.*;

public class Find_Sum_Of_Fibonacci {
    private static int getFibonacciSumNaive(int n) {
            if (n <= 1)
                return n;
            
            int current;
            int m=100000007;
            int sum[][]=new int[2][2];
            int I[][]=new int[2][2];
            I[0][1]=1;I[0][0]=1;
            I[1][0]=1;I[1][1]=0;
            sum[0][1]=0;sum[0][0]=1;
            sum[1][0]=0;sum[1][1]=1;

            findsum(I,sum,n+1,m);
            if(sum[0][0]==0) return 9;
            current=sum[0][0]-1;
            return current;
        }
        
        public static void finmu(int sum[][],int a[][],int m){
            int t1=((sum[0][0]%m*a[0][0]%m)%m+(sum[0][1]%m*a[1][0]%m)%m)%m;
            int t2=((sum[0][0]%m*a[0][1]%m)%m+(sum[0][1]%m*a[1][1]%m)%m)%m;
            int t3=((sum[1][0]%m*a[0][0]%m)%m+(sum[1][1]%m*a[1][0]%m)%m)%m;
            int t4=((sum[1][0]%m*a[0][1]%m)%m+(sum[1][1]%m*a[1][1]%m)%m)%m;
            sum[0][0]=t1;sum[0][1]=t2;sum[1][0]=t3;sum[1][1]=t4;
        }
        public static void findsum(int a[][],int sum[][],int n,int m){
            if(n==0){
                return;
            }
            if(n%2==0){
                finmu(a,a,m);
                findsum(a,sum,n/2,m);
            }
            else{
                finmu(sum,a,m);
                
                findsum(a,sum,n-1,m);
            }
        }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int s = getFibonacciSumNaive(n);
        System.out.println(s);
    }
}

