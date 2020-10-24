package searching_and_sorting;

import java.util.Scanner;

public class Merge_sort {

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
	
	//function to merge sort
	public static int[] merge(int arr1[], int arr2[])
	{
		int i = 0, j = 0;
		int k = 0;
		int size = arr1.length + arr2.length;
		int arr3[] = new int [size];
		
		while(i < arr1.length && j < arr2.length)
		{
				if(arr1[i] < arr2[j])
				{
					arr3[k] = arr1[i];
					i++;
					k++;
				}
				else
				{
					arr3[k] = arr2[j];
					j++;
					k++;
				}
		}
		
		while(i < arr1.length)
		{
			arr3[k] = arr1[i];
			i++;
			k++;
		}
		while(j < arr2.length)
		{
			arr3[k] = arr2[j];
			j++;
			k++;
		}
		return arr3;
	}
	//end
	
	public static void main(String[] args) 
	{
		int[] arr1 = takeInput();
		int[] arr2 = takeInput();
		int ans[] = Merge_sort.merge(arr1, arr2);
		for(int i = 0; i < ans.length; i++)
		{
			System.out.print(ans[i] + " ");
		}
	}
	
}
