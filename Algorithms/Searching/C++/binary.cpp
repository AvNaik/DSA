#include <iostream>

int binarySearch_recursive (int arr[], int lower, int elements, int number)
{
	if (lower <= number)
	{
		int mid = lower + (elements - lower/ 2);

		if (arr[mid] == number)
			return 1;

		if (arr[mid] > number)
		{
			return binarySearch_recursive (arr, lower, mid -1, number);
		} else if (arr[mid] < number)
		{
			return binarySearch_recursive (arr, mid+1, elements, number);
		}
	}

	return -1; 
}


int binarySearch_iterative (int arr [], int lower, int elements, int number)
{

	while (lower <= elements)
	{
		int mid = lower + (elements - lower)/2;

		if (arr [mid] == number)
		{
			return 1;
		} else if (arr [mid] > number)
		{
			elements = mid - 1;
		} else if (arr [mid] < number)
		{
			lower = mid + 1;
		}
	}
	return -1;
}


int main ()
{
	int elements = 0;
	std::cout <<"Enter number of elements in the array" <<std::endl;
	std::cin >> elements;

	int array [elements];
	std::cout <<"ENter elements of the array" << std::endl;
	for (int i = 0; i < elements; i ++)
		std::cin >> array [i];

	int number = 0;
	std::cout << "Enter elements to be searched in thhe array" <<std::endl;
	std::cin >> number;
	std::cin.ignore ();

	int result = binarySearch_iterative (array, 0, elements, number);

	std::cout << result << std::endl;

	std::cin.get();


	return 0;
}
