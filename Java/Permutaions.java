import java.util.Scanner;

class Student_Orders{
    String[] swap(String[] student_array, int index1, int index2){
        String temp= student_array[index1];
        student_array[index1]= student_array[index2];
        student_array[index2]= temp;
        return student_array;
    }

    void printArray(String[] student_array){
        for(int i=0;i<student_array.length;i++){
            System.out.print(student_array[i]+" ");
        }
        System.out.println();
    }

    void permute_results(String[] student_array, int initial_index){
        if(initial_index == student_array.length-1){
            printArray(student_array);
        }

        for(int i=initial_index;i<student_array.length;i++){
            swap(student_array,i,initial_index);
            permute_results(student_array,initial_index+1);
            swap(student_array,i,initial_index);
        }
    }

    long number_of_possible_permutations(String[] student_array){
        long factorial=1;
        for(int i=2;i<=student_array.length;i++){
            factorial*=i;
        }
        return factorial;
    }
}


public class Permutaions{
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        Student_Orders combinations= new Student_Orders();
        System.out.println("Enter the number of students in the row: ");
        int number_of_students= sc.nextInt();
        String[] student_array= new String[number_of_students];
        System.out.println("Enter the student names: ");
        for(int i=0;i<number_of_students;i++){
            student_array[i]= sc.next();
        }
        System.out.println("The number of combinations that are possible are: "+combinations.number_of_possible_permutations(student_array));
        System.out.println("All possibilities are: ");
        combinations.permute_results(student_array,0);
    }
}