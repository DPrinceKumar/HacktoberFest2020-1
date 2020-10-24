import java.util.*;

 class Diamond  {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of rows");
        int row_number = scanner.nextInt();
        int space= row_number/2;
        int spacecount= 1;
        int row = 1;
        while(row<=row_number){
            for (int i = 1; i <= space; i++) {
                System.out.print(" ");
            }
            for (int j = 1; j <= spacecount ; j++) {
                System.out.print("*");
            }
            System.out.print("\n");
            if(row <=row_number/2){
                space--;
                spacecount=spacecount+2;
            }else{
                space++;
                spacecount =spacecount-2;
            }

            row++;
        }
    }
}
