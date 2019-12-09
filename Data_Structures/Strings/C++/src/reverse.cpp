#include <iostream>
#include <string>
#include <algorithm>
#include "../includes/inc.h"

void reverse::str_reverse (std::string& s)
{
	   int j = s.length() -1;
	   char temp;
	   for (int i = 0; i < j; i ++, j --)
	   {
			 temp = s[i];
			 s[i] = s[j];
			 s[j] = temp;
	   }
	   std::cout <<s <<std::endl;
}

void reverse::reverse_by_k (std::string& s, int k)
{
	   int len = s.length ();

	   for (int i = 0; i < len;) 
	   {
			 if (i + k > len)
				    break;

			 std::reverse (s.begin() +i, s.begin() + i + k);

			 i += 2*k;
	   }
}


void reverse::reverse_vowels (std::string& s)
{
		int j = s.length() -1;
		if ( j == 0 || j == 1)
			return;
		int i = 0;
		std::cout << j <<std::endl;
		while (i < j)
		{
			while (i < j && (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')) 
				i++;

			while (j > i && (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u'))
				j--;
			if (i < j)
				std::swap (s[i], s[j]);
			i++;
			j--;
		}

	   std::cout <<s <<std::endl;
}

void reverse::reverse_words (std::string& s)
{
	int f = 0;
	int len = s.length() ;
	for (int i = 0; i <= len; i ++)
	{
		if (i == (len) || s[i] == ' ')
		{
			std::reverse(&s[f], &s[i]);
			f = i+1;
		}
	}

	std::cout << s <<std::endl;

}

int main ()
{
	   std::string s;

	   std::cout <<"Enter String: " <<std::endl;

	   std::getline (std::cin, s);

	   reverse r;
	   // r.str_reverse(s);
	   r.str_reverse(s);

//	   std::cout << s <<std::endl;
	   std::cin.get ();

	   return 0;
}
