#include<iostream>
using namespace std;
void Swap(int *first, int *second) {
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
 }
void BubbleSort(int array[], int size) {
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]) {
				Swap(&array[i], &array[i + 1]);
				swapped = true;
			}
		}
	}

}                             
	void InsertionSort(int array[], int size) {
		int j;
		int key;
		for (int i = 1; i < size; i++) {
			key = array[i];
			j = i - 1;
				while (j >= 0 && array[j] > key) {
					array[j + 1] = array[j];
					j = j - 1;
				}
			array[j + 1] = key;
		}
	}

void SelectionSort(int array[] , int size) {
	int min_idx;
	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[min_idx]) {
				min_idx = j;
			}
		}
		// we do the swap after the second iteration
		Swap(&array[min_idx], &array[i]);
	}
}
void Merge(int array[], int l, int m, int r) {
	/*
	When creating an array like that, its size must be constant.
	If you want a dynamically sized array,
	you need to allocate memory for it on the heapand you
    'll also need to free it with delete when you're done :
	*/
	int size1 = m - l + 1;
	int  size2 = r - m;
	int* left;
	left = new int[size1];
	int* right;
	right = new int[size2];
	// Create temp arrays
	//int left[size1], right[size2];
	for (int i = 0; i < size1; i++) 
		left[i] = array[l + i];
	
	for (int j = 0; j < size2; j++) 
		right[j] = array[m + 1 + j];

	int x1 = 0, x2 = 0;
	int k = l;
	while (x1 < size1 && x2 < size2) {
		if (left[x1] <= right[x2]) {
			array[k] = left[x1];
			x1++;
		}
		else {

			array[k] = right[x2];
			x2++;
		}
		k++;
	}
	while (x1 < size1) {
		array[k] = left[x1];
		x1++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (x2 < size2) {
		array[k] = right[x2];
		x2++;
		k++;
	}
}

void MergeSort(int array[],int l,int r){
	if (l >= r) {
		return;
	}
	int m = l + (r - l) / 2;
	MergeSort(array, l, m);
	MergeSort(array, m + 1, r);
	Merge(array, l, m, r);

}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}
void DisplayValues(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " \t ";
	} 
	cout << endl;
}


int main() {

	int array[] = {5,1,-5,12,16,2};
	int size = sizeof(array) / sizeof(array[0]);
	int n;
	cin >> n;
	switch (n) {
	case 1:
		BubbleSort(array, size);
		cout << " The Array After Sorted with BubbleSort: " << endl;
		DisplayValues(array, size);
		break;

	case 2:
		InsertionSort(array, size);
		cout << " The Array After Sorted with insertion : " << endl;
		DisplayValues(array, size);
		break;
	case 3:
		SelectionSort(array, size);
		cout << " The Array After Sorted with SelectionSort : " << endl;
		DisplayValues(array, size);
		break;
	case 4:
		MergeSort(array,0, size-1);
		cout << " The Array After Sorted with  MergeSort : " << endl;
		DisplayValues(array, size);
		break;
	case 5:
		QuickSort(array, 0, size - 1);
		cout << " The Array After Sorted with  Quick Sort : " << endl;
		DisplayValues(array, size);
	default:
		break;

	}
	system ("pause");
	return 0;
}
      /*   // Adaptive : means to reduce the numbers of steps if there is some elements already sorted
	       // NOTE THAT 
		   /*
		    1) While sorting if the source list has some elements already sorted
			   the adaptive algorithm will take it into account and will try not to re-order them
			2) While sorting if the source list has some elements already sorted
			   the non_adaptive algorithm will  not take it into account and will try to force
			   every single elemnent to be orderd
			       ///////Adaptive sorting algorithms///////
 
            1.Bubble Sort
            2.Insertion Sort
            3.Quick Sort
          Non-adaptive sorting algorithms:
           1.Selection Sort
           2.Merge Sort
           3.Heap Sort
		   */


           /*
	                                    **********Bubble Sort********* 
	     Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping 
	     the adjacent elements if they are in wrong order.
	     Worst and Average Case Time Complexity: O(n^2).
		 Worst case occurs when array is reverse sorted.
         Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
         Auxiliary Space: O(1)
         Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
         Sorting In Place: Yes
         Stable: Yes
		 adaptive: Yes => As, it doesnt make any swap move if the  two elements are sorted.
         Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm. 
         In computer graphics it is popular for its capability to detect a very small error.
		 this algorithm will not suitable for large data.
	 */


	 /*
							  **********Insertion Sort**********
         Insertion sort is a simple sorting algorithm that works similar to the way you 
		 sort playing cards in your hands. The array is virtually split into a sorted 
		 and an unsorted part. 
		 Values from the unsorted part are picked and placed at the correct position 
		 in the sorted part.
		 Time Complexity: O(n^2)
         Auxiliary Space: O(1)
         Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order.
         And it takes minimum time (Order of n) when elements are already sorted.
		 Algorithmic Paradigm: Incremental Approach
         Sorting In Place: Yes
         Stable: Yes
         Online: Yes
		 Adaptive:Insertion Sort is adaptive, that means it reduces its total
		 number of steps if given a partially sorted list
         Uses: Insertion sort is used when number of elements is small.
		 It can also be useful when input array is almost sorted,
         only few elements are misplaced in complete big array.
		 this algorithm will not suitable for large data.
   */  

   /*
                             **********Selection Sort**********
       Time Complexity: O(n2) as there are two nested loops. in all cases
       Auxiliary Space: O(1) 
       The good thing about selection sort is it never makes more than O(n) 
       swaps and can be useful when memory write is a costly operation. 
	   In Place : Yes, it does not require extra space.

	   // The default implementation is not stable.
	   However it can be made stable. Please see stable selection sort for details.

   */
   /*
                           ************Merge Sort***************
        heap sort == merge sort in all cases and space
	   Merge Sort is a recursive algorithm and time complexity can be expressed as 
	   following recurrence relation.   T(n) = 2T(n/2) + θ(n).
	   time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) 
	   as merge sort always divides the array into two halves and takes linear time to
	   Auxiliary Space: O(n)
	   Algorithmic Paradigm: Divide and Conquer
	   Sorting In Place: No in a typical implementation
       Stable: Yes
	   Slower comparative to the other sort algorithms for smaller tasks.
       is non adaptive          

  */
  /*                    ************Quick Sort********************
     
        Solution of above recurrence is also O(nLogn) in best and worth
        Although the worst case time complexity of QuickSort is O(n2)
		which is more than many other sorting algorithms like Merge Sort and Heap Sort
	    QuickSort is faster in practice, because its inner loop can be efficiently implemented on most 
	    architectures, and in most real-world data. QuickSort can be implemented in different ways by changing 
	    the choice of pivot, so that the worst case rarely occurs for a given type of data
	   However, merge sort is generally considered better when data is huge and stored in external storage. 

   Is QuickSort stable? 
   The default implementation is not stable. 
   However any sorting algorithm can be made stable by considering indexes as comparison parameter. 

  Is QuickSort In-place? 
   As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it
   uses extra space only for storing recursive function calls 
   but not for manipulating the input. 



 */