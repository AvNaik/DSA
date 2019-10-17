#include <stdio.h>

/*
   Function to check if the string entered is pangram. The function will also print the missing characters from the string, if any. 
   A pangram is a sentence containing every letter in the English Alphabet.
 */
int pangram_check(char s[])
{
	   int array [26];
	   int index = 0;
	   int test = 0;
	   char miss;
	   for (int i = 0; i < 26; i ++)
			 array[i] = 0;

	   for (int i = 0; s[i] != '\0'; i ++)
	   {
			 if ('a' <= s[i] && s[i] <= 'z')
			 {
				    index = s[i] - 'a';
				    array[index] = 1;
			 } else if ('A' <= s[i] && s[i] <= 'Z')
			 {
				    index = s[i] - 'A';
				    array[index] = 1;
			 }
	   }
	   printf("Missing Characters, if any: \n");

	   for (int i = 0; i < 26; i ++, test++)
	   {
			 if (array [i] == 0)
			 {
				    miss = 'a' + i;
				    printf ("%c \n", miss);
				    if (test >= 25)
						  return -1;
			 }
	   }

	   return 1;
}

int main ()
{
	   int number = 0;
	   printf("Enter Lenth of string: \t");
	   scanf("%d", &number);

	   char s [2];
	   fgets(s, 2, stdin);

	   char s1 [number];

	   printf("Enter string the string to be checked: \n");
	   fgets (s1, number, stdin);

	   printf("Entered String is: %s", s1);

	   int r = pangram_check (s1);
	   (r == 1) ? printf("String is panagram \n") : printf("The String is not a panagram \n");

	   return 0;
}

