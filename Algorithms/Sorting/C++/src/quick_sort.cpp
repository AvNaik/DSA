#include <iostream>

void swap (int& a, int& b)
{
	   int temp = a;
	   a = b;
	   b = temp;
}

int partition (int arr [], int low, int high)
{
	   int pivot = arr[high];
	   int j = low -1;

	   for (int i = low; i < high; i ++)
	   {
			 if (arr[i] <= pivot)
			 {
				    j = j +1;
				    swap (arr[j], arr[i]);
			 }	
	   }

	   swap (arr[j+1], arr[high]);
	   return j+1;
}

void quick_sort (int arr[], int low, int high)
{
	   if (low < high)
	   {
			 int pivot = partition (arr, low, high);
			 quick_sort (arr, low, pivot -1);
			 quick_sort (arr, pivot +1, high);
	   }
}

int main ()
{
	   int number = 0;
	   std::cout <<"Enter Size: " << std::endl;
	   std:: cin >> number;

	   int* array = new int[number];
	   std::cout << "Enter Elements: " << std:: endl;
	   for (int i = 0; i < number; i ++)
	   {
			 std::cin >> array[i];
	   }
	   quick_sort (array, 0, number -1);
	   for (int i = 0; i < number; i ++)
			 std::cout << array[i] << std::endl;

	   std::cin.get ();
	   std::cin.get();
	   return 0;

}
