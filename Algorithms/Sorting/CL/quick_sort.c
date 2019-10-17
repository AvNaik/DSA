#include <stdio.h>

void swap(int*a , int*b)
{
	   int temp = *a;
	   *a = *b;
	   *b = temp;
}

int partition (int arr[], int low, int high)
{
	   int pivot = arr [high];
	   int i = low -1;

	   for (int j = low; j < high; j++)
	   {
			 if (arr[j] <= pivot)
			 {
				    i = i +1;
				    swap (&arr[i], &arr[j]);
			 }
	   }

	   swap (&arr[i+1], &arr[high]);

	   return i+1;
}

void quick_sort (int arr [], int low, int high)
{
	   if (low < high)
	   {
			 int pivot = partition (arr, low, high);
			 quick_sort (arr, low, pivot-1);
			 quick_sort (arr, pivot +1 , high);
	   }
}

int main ()
{
	   int number = 0;
	   printf("Enter size of array: \n");
	   scanf ("%d", &number);

	   int array [number];
	   printf("Enter Elements: \n");
	   for (int i = 0; i < number; i ++)
			 scanf("%d", (array +i));

	   quick_sort (array, 0, number - 1);

	   for (int i = 0; i < number; i ++)
			 printf("%d \n", *(array+ i));

	   return 0;

}

