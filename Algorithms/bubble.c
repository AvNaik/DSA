#include <stdio.h>

void bubbleSort (int arr[], int n)
{
int temp = 0;

for (int i = 0; i < n; i ++)

for (int j = 0; j < n-i; j++)

if (arr[j] > arr[j+1])
{
temp = arr [j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}

int main ()
{
int number;
printf("Please enter size. \n");
scanf ("%d", &number);

int array [number];

for (int i = 0; i < number ; i ++)
scanf("%d", &array[i]);

bubbleSort (array, number);

for (int i = 0; i < number; i++)
printf("%d \n", array [i]);

return 0;
}

