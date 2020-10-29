package searching_and_sorting;

import java.util.Scanner;

public class Insertion_sort {

	static Scanner s = new Scanner(System.in);

	//function to take input
	public static int[] takeInput(){
		
		int size = s.nextInt();
		int[] input = new int[size];
		
		for(int i = 0; i < size; i++){
			input[i] = s.nextInt();
		}
		return input;
	}
	//end
	
	//function to print array
	public static void printArray(int[] arr) {
		
		for(int element : arr) {
			System.out.print(element + " ");
		}
		System.out.println();

	}
	//end

	//function for insertion sort
	public static void insertionSort(int[] arr)
	{
		for(int i = 1; i < arr.length; i++)
		{
			int min = arr[i];
			int j = i - 1;
			
			while((j >= 0 && arr[j] > min))
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = min;
		}
	}
	//end
	
	//main
	public static void main(String[] args) {
		int[] arr = takeInput();

		Insertion_sort.insertionSort(arr);
		printArray(arr);
	}

}
