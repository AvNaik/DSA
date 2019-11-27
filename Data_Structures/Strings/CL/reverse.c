#include <stdio.h>

int str_length (char []);

void swap (char* s1, char*s2)
{
	#if 0
	   char s = *s1;
	   *s1 = *s2;
	   *s2 = s;
	   #endif 
	   *s1 = *s1 ^ *s2;
	   *s2 = *s1 ^ *s2;
	   *s1 = *s1 ^ *s2;
}

void reverse (char s[], int length)
{
	   int j = length;
	   for (int i = 0; i < j; i++, j--)
	   {
			 swap (&s[i], &s[j]);
	   }
}

void reverse_words (char s [])
{
	int length = str_length (s);

	for (int i = length; i >= 0; i --)
	{
		if (s[i] == ' ')
		{
			s[i] = '\0';
			printf("%s \t", &(s[i]) + 1);
		}
	}
	printf("%s", s);
}
/*
char* reverse_by_k (char* s, int k, int index)
{
	int length = str_length (s);
	int j = k;


}*/

int str_length(char s[])
{
	   int i = 0;
	   for (; s[i] != '\0'; i ++)
	   {
	   }

	   return i -1;
}

int main ()
{
	   int len = 0;
	   int number = 0;
	   printf("Enter Lenth of string: \t");
	   scanf("%d", &number);

	   char s [2];
	   fgets(s, 2, stdin);

	   char s1 [number];

	   printf("Enter string: \n");
	   fgets (s1, number, stdin);

	   printf("Entered String is: %s", s1);

	   len = str_length (s1);
	   printf("Length of a string is: %d \n", len);

//	   reverse_by_k (s1, 2, 0);

	   reverse (s1, len);
	   printf("The reversed String is: %s \n", s1);


	   return 0;
}

