#include "iostream"

void insertion_sort (int arr [], int number)
{
	for (int i = 1; i < number; i ++)
	{
		int key = arr[i];
		int j = i -1 ;
		while (j >= 0 && arr[j] > key)
		{
			arr [j+1] = arr[j];
			j = j-1;
		}

		arr[j+1] = key;
	}
}

/*
Insertion Sort Algorithm to sort a gievn array. The function parameters are the array to be sorted which will passed as a pointer from the calling function to the insertion_sort function and the low and high array indexes between which 
array is to be sorted. For example, if low = 0 and high = 6, the array will be sorted between indexes 0 and 6
*/

void insertion_sort_update(int arr [], int low, int high)
{
	int key = 0;
	for (int i = low; i <= high; i ++)
	{
		key = arr[i];
		int j = i -1;
		while (j >= low && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;
	}
}


int main ()
{
	   int number = 0;
	   std::cout <<"Enter number of elements: " << std::endl;
	   std:: cin >> number;

	   int array [number];

	   std::cout <<"Enter Elements: "<< std::endl;
	   for (int i = 0; i < number; i++)
			 std::cin >> array [i];

	   insertion_sort_update (array, 3, number);

for (int i : array)
	std:: cout << i << std::endl;

	   return 0;
}
