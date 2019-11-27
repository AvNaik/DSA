#include <stdio.h>
#include <string.h>
/*
Program to search a substring within a given string i.e. search str2 in str1
*/

int search (char* s1, char* s2)
{
	int m = strlen (s1) -1;
	int n = strlen(s2) -1;
	for (int i = 0; i <= m -n; i++)
	{
		int j = 0;
		for (; j <= n; j++)
		{
			if (s1[i+j] != s2[j])
				break;
		}
		if (j == n)
		{
			return 1;
		}
	}

	return 0;
}

int main ()
{
	char s1[100];
	char s2 [10];
	printf("Larger String: \n");
	fgets(s1, 100, stdin);
	printf("String to be searced: \n");
	fgets (s2, 10, stdin);
	search (s1, s2) ? printf("String is present \n") : printf("String not present \n");
	return 0;
}
