#include <iostream>
#include <string>
#include <vector>
#include "../includes/inc.h"


int is_pangram (std::string& s)
{
	   std::vector <int> test (26, 0);
	   int offset = 0;

	   for (int i = 0; s[i] != '\0'; i ++)
	   {
			 if (s[i] >= 'A' && s[i] <= 'Z')
			 {
				    offset = s[i] - 'A';
			 } else if (s[i] >= 'a' && s[i] <= 'z')
			 {
				    offset = s[i] - 'a';
			 }

			 test [offset] = 1;
	   }

	   for (int i = 0; i < 26; i ++)
	   {
			 if (test[i] == 0)
			 {
				    return -1;
			 }
	   }

	   return 1;
}

int main ()
{
	   int r1 = 0;
	   std::string s;

	   std::cout <<"Enter String: " <<std::endl;

	   std::getline (std::cin, s);

	   r1 = is_pangram (s);

	   (r1 == 1) ? std::cout <<"String is panagram" : std::cout <<"String is not a panagram" << std::endl;

	   //  std::cout << s <<std::endl;

	   std::cin.get ();

	   return 0;
}
