#include <stdio.h>
#include <math.h>

void merge(int arr[], int low, int mid, int high)
{
int a = (mid - low) + 1;
int b = high - mid;

int temp1 [a+1];
int temp2 [b+1];

for (int i = 0; i < a; i++)
	temp1[i] = arr [low +i];

for (int i = 0; i < b; i ++)
	temp2[i] = arr [mid +1 + i];

temp1[a] = (int) pow (2,31);
temp2[b] = (int) pow (2,31);

int i = 0;
int j = 0;
for (int k = low; k <= high; k++)
{
	if (temp1[i] <= temp2[j])
	{
		arr[k] = temp1[i];
		i++;
	} else
	{
		arr[k] = temp2[j];
		j++;
	}
}


}
void merge_sort (int arr[], int low, int high)
{
	   if (low < high)
	   {
			 int mid = (low + high) /2;
			 merge_sort (arr, low, mid);
			 merge_sort (arr, mid+1, high);
			 merge (arr, low, mid, high);
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

	   merge_sort (array, 0, number - 1);

	   for (int i = 0; i < number; i ++)
			 printf("%d \n", *(array+ i));

	   return 0;
}

