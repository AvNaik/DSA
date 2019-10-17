#include <stdio.h>


int binarySearch_recursive (int arr[], int number, int lower, int element)
{
	   if (number >= lower)
	   {
			 int mid = lower + (number - lower)/2;


			 if (arr[mid] == element)
				    return 1;

			 if (arr[mid] > element)
			 {
				    return binarySearch_recursive (arr, mid -1, lower, element);
			 } else if (arr[mid] < element)
			 {
				    return binarySearch_recursive (arr, number, mid+1, element);
			 }
	   }
	   return -1;
}

int binarySearch_iterative (int arr[], int number, int lower, int element)
{
	   while (number >= lower)
	   {
			 int mid = lower + (number - lower)/2;

			 if (arr[mid] == element)
				    return 1;

			 else if (arr[mid] > element)
				    number = mid -1;

			 else if (arr[mid] < element)
				    lower = mid+1;
	   }

	   return -1;
}
int main ()
{
	   int number = 0;
	   printf("Enter number of elements in the array: \n");
	   scanf("%d", &number);

	   int element = 0;
	   printf ("Enter the element to be searched \n");
	   scanf("%d", &element);

	   int lower = 0;
	   int array [number];

	   printf("Enter elements of the array: \n");
	   for (int i = 0; i < number; i ++)
			 scanf("%d", (array+i));

	   int result = binarySearch_iterative (array, number, lower, element);

	   printf ("%d \n", result);

	   return 0;
}

