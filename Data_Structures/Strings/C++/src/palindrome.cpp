#include <iostream>
#include <string>

void is_p(std::string& s)
{
	int n = s.size()-1;
	for (int i = 0; i < n; i ++, n--)
	{
		if (s[i] != s[n])
		{
			std::cout<<"String is not a palindrome" <<std::endl;
			return;
		}
	}
	std::cout << "String is a plaindrome" <<std::endl;
}

#if 0

We can do it in O(n) time using a count array. Following are detailed steps.
1) Create a count array of alphabet size which is typically 256. Initialize all values of count array as 0.
2) Traverse the given string and increment count of every character.
3) Traverse the count array and if the count array has more than one odd values, return false. Otherwise return true.
#endif

void check_p (std::string& s)
{
	int array[256] = {0};
	int n = s.length ();
	int odd_values = 0;
	for (int i = 0; i < n; i ++)
	{
		array [(int)s[i]]++;
	}
	std::cout << (int)s[2] << std::endl;

	for (int i = 0; i < 256; i ++)
	{
		if (array[i] %2 == 1)
			odd_values ++;
		if (odd_values > 1)
		{
			std::cout <<"The string cannot be a palindrome" << std::endl;
			return;
		}
	}	
	std::cout <<"String is a palindrome" <<std::endl;	
}

int main ()
{
	   std::string s;
	   std::cout <<"Enter String:" <<std::endl;
	   std::getline (std::cin, s);
	   std::cout << s <<std::endl;
	   check_p(s);
	   std::cin.get();
}
