#include <stdio.h>


int linearSearch_iterative (int arr[], int n, int element)
{
	   for (int i = 0; i < n; i ++)
	   {
			 if (arr [i] == element)
				    return i;
	   }

	   return -1;
}

int linearSearch_recursive (int arr [], int m, int element)
{
if (m < 0)
return -1;
else if (arr[m] == element)
return 1;
else
return linearSearch_recursive (arr, m-1, element);
}
int main ()
{
	   int number = 0;
	   int element = 0;
	   printf("Number of elements in the array: \n");
	   scanf("%d", &number);

	   int array [number];

	   printf("Enter elements of Array: \n");

	   for (int i = 0; i < number; i++)
	   {
			 scanf("%d" ,(array+i));
	   }

	   printf ("enter elememnt to be searched: \n");
	   scanf("%d", &element);

	   int index = linearSearch_recursive (array, number, element);

	   printf ("%d \n", index);

	   return 0;
}
