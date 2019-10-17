#include "stdio.h"
/*
   Iterative and Recursive functions copying one string into another.
 */
void copy_str_recursive (char s1[], char s2[], int index)
{
	   s2[index] = s1[index];
	   if (s1[index] == '\0')
			 return;

	   copy_str_recursive (s1, s2, index +1);
}

void copy_str_iterative (char s1[], char s2[])
{
	   int i = 0;
	   for (; s1[i] != '\0'; i++)
	   {
			 s2[i] = s1[i];
	   }
	   s2[i] = '\0';
}

int main ()
{
	   int number = 0;
	   printf("Enter Lenth of string: \t");
	   scanf("%d", &number);

	   char s [2];
	   fgets(s, 2, stdin);

	   char s1 [number];
	   char s2 [number];
	   char s3[number];

	   printf("Enter string to be copied into another string: \n");
	   fgets (s1, number, stdin);

	   printf("String Entered is: %s \n", s1);

	   copy_str_recursive (s1, s2, 0);
	   copy_str_iterative (s1, s3);

	   printf("The New String is: %s \n", s2);

	   printf("The new copied string is: %s \n", s3);

	   return 0;
}
