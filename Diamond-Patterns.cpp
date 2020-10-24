// C++ program to print diamond shape 
// with 2n rows 
#include <bits/stdc++.h> 
using namespace std; 

// Prints diamond pattern with 2n rows 
void printDiamond(int n) 
{ 
	int space = n - 1; 

	// run loop (parent loop) 
	// till number of rows 
	for (int i = 0; i < n; i++) 
	{ 
		// loop for initially space, 
		// before star printing 
		for (int j = 0;j < space; j++) 
			cout << " "; 

		// Print i+1 stars 
		for (int j = 0; j <= i; j++) 
			cout << "* "; 

		cout << endl; 
		space--; 
	} 


	space = 0; 


	for (int i = n; i > 0; i--) 
	{ 
		
		for (int j = 0; j < space; j++) 
			cout << " "; 

		
		for (int j = 0;j < i;j++) 
			cout << "* "; 

		cout << endl; 
		space++; 
	} 
} 

int main() 
{ 
	printDiamond(5); 
	return 0; 
}
..//java
import java.util.*; 

class diamond
{ 
	
	static void printDiamond(int n) 
	{ 
		int space = n - 1; 
	
		for (int i = 0; i < n; i++) 
		{ 
			
			for (int j = 0; j < space; j++) 
				System.out.print(" "); 
	
			for (int j = 0; j <= i; j++) 
				System.out.print("* "); 
	
			System.out.print("\n"); 
			space--; 
		} 
	
	
		space = 0; 
	
		
		for (int i = n; i > 0; i--) 
		{ 
			// loop for initially space, 
			// before star printing 
			for (int j = 0; j < space; j++) 
				System.out.print(" "); 
	
			// Print i stars 
			for (int j = 0; j < i; j++) 
				System.out.print("* "); 
	
			System.out.print("\n"); 
			space++; 
		} 
	} 
	
	public static void main(String[] args) 
	{ 
		printDiamond(5); 
		
	} 
} 


