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

int main ()
{
	   std::string s;

	   std::cout <<"Enter String: " <<std::endl;

	   std::getline (std::cin, s);

	   reverse r;
	  // r.str_reverse(s);
	r.reverse_by_k (s, 3);

		std::cout << s <<std::endl;
	   std::cin.get ();

	   return 0;
}
