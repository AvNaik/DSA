#include <iostream>
#include <cmath>

void merge (int arr [], int low, int mid, int high)
{
	   int a = (mid - low) +1;
	   int b = high - mid;

	   int arr1 [a+1];
	   int arr2 [b+1];

	   for (int i = 0; i < a; i ++)
			 arr1[i] = arr[low + i];
	   for (int i = 0; i < b; i++)
			 arr2[i] = arr[ mid+1+i];

	   arr1[a] = (int) pow (2, 31);
	   arr2[b] = (int) pow (2, 31);

	   int i = 0;
	   int j = 0;

	   for (int k = low; k <= high; k++)
	   {
			 if (arr1[i] <= arr2[j])
			 {
				    arr[k] = arr1[i];
				    i++;
			 } else
			 {
				    arr[k] = arr2[j];
				    j++;
			 }
	   }

}
void merge_sort (int arr[], int low, int high)
{
	   if (low < high)
	   {
			 int mid = (low + high) / 2;
			 merge_sort (arr, low, mid);
			 merge_sort (arr, mid+1, high);
			 merge(arr, low, mid, high);
	   }
}
int main ()
{
	   int number = 0;
	   std::cout <<"Enter Size: " << std::endl;
	   std:: cin >> number;

	   int array [number];
	   std::cout << "Enter Elements:; " << std::endl;

	   for (int i = 0; i < number; i ++)
			 std::cin >> array[i];

	   merge_sort (array, 0, number -1);
	   for (int i : array)
			 std::cout << i << std::endl;

	   std::cin.get ();
	   std::cin.get();
	   return 0;

}
