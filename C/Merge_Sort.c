/*Sorting - 4
`````````````
Eg: Input: 	A[]={4,9,6,12,2,8,6,3,1,7}
	Output:	A[]={1,2,3,4,6,6,7,8,9,12}

Observation
```````````
Given two sorted arrays A1[a] A2[b],
they can be "merged" to create a single sorted array with elements of both arrays.

Eg: A1[a]={1,2,4,6,8} A2[b]={3,6,7,9,12} merged into {1,2,3,4,6,6,7,8,9,12}

	Idea for Merge
	``````````````
		* First insert elements of the sorted array A1[a] into a new array B[].
		* Then insert elements of the sorted array A2[b] into the array B[].
		* Here "Insert" is to be done as in the insertion sort idea.
		* Running time of this is O(a*b). Why ?
		In the worst case scenario each element in A2[b] has to compared with each element in A1[a]
		That would take a steps. Doing the same process for b elements would take a*b steps. Therefore O(a*b).


Idea (Merge Sort) - Divide and Conquer approach.
````````````````````````````````````````````````
* 	Arrays of size 1 are sorted.
* 	Use merge idea repeatedly.

	- Input array

		{4,	9,	6,	12,	2,	8,	6,	3,	1,	7}

	- Merge consecutive subarrays of size at most 1.

		{4,	9,	6,	12,	2,	8,	3,	6,	1, 7}

	- Merge consecutive subarrays of size at most 2.

		{4,	6,	9,	12,	2,	3,	6,	8,	1, 7}

	- Merge consecutive subarrays of size at most 4.

		{2,	3,	4,	6,	6,	8,	9,	12, 1,	7}

	- Merge consecutive subarrays of size at most 8.

		{1,	2,	3,	4,	6,	6,	7,	8,	9,	12}

*/

void main()
{
	int A[10]={4,9,6,12,2,8,6,3,1,7};
	int a=10;
	int B[10];

	int size=1;
	while (size<=a)
	{
		int start=0;
		while(start+size<=a)
		{   mid = start + size;
			for(int i=start;i<mid;i++)
            {
                B[i]=A[i]
            }
			start=mid+size;
			size++
		}

		//Swap Arrays A[] and B[]
		int i=0;
		while(i<a)
		{
			int temp=A[i]
			A[i]=B[i];
			B[i]=temp;
			i=i+1;
		}

		// Double size of the subarrays to be merged
		size=2*size;
	}

}



/*

Runtime Analysis
````````````````
For an input array of size n.

  Merge consecutive subarrays of size 1 ~ n/2 * O(1*1)

+ Merge consecutive subarrays of size 2 ~ n/4 * O(2*2)

+ Merge consecutive subarrays of size 4 ~ n/8 * O(4*4)

+ Merge consecutive subarrays of size 8 ~ n/16 * O(8*8)

.
.
.
+										~ STOP when n/(2^k) < 1
_________________________________________

Total = //###########
		//HOMEWORK.
		//###########

*/
