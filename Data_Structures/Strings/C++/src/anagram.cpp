#include <iostream>
#include <string>
/*
	Program to test if two strings are anagrams.
*/
int test_anagram (std::string& s1, std::string& s2)
{
	   if (s1.length () != s2.length ())
			 return -1;

	   int val = 0;

	   for (int i = 0; i < (int) s1.length(); i ++)
	   {
			 val = val ^ (int) s1[i];
			 val = val ^ (int) s2[i];
	   }
	   std::cout << val << std::endl;

	   if (val == 0)
			 return 1;
	   else 
			 return -1;
}


int main ()
{
	   std::string s;

	   std::cout <<"Enter String 1: " <<std::endl;

	   std::getline (std::cin, s);

	   std::string t;

	   std::cout <<"Enter string 2: " << std::endl;

	   std::getline (std::cin, t);

	   int result = test_anagram(s, t);

	   (result == 1) ? std::cout << "Strings are Anagrams" : std::cout << "Strings are not anagrams" <<std::endl;

	   std::cin.get ();

	   return 0;
}

