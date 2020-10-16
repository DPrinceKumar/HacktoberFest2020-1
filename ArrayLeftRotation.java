public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //Enter size of array...

        int n = scan.nextInt();
        //Enter length of array which you want to rotate

        int d = scan.nextInt();
        int[] array = new int[n];

        for(int i=0; i<n;i++) {
            array[(i+n-d)%n] = scan.nextInt();
        }
        //printing the final array.....
        for(int i=0; i<n;i++) {
            System.out.print(array[i] + " ");
        }      
    }
}
