#include <iostream>
#include <string>

void search (std::string & s1, std::string& s2)
{
	int m = s1.length();
	int n = s2.length();

	for (int i = 0; i < m; i ++)
	{
		int j =0;
		for (; j < n; j++)
		{
			if (s1[i+j] != s2[j])
			{
				break;
			}
		}
		if (j == n)
		{
			std::cout <<"String found" << std::endl;
			return;
		}
	}
	std::cout <<"String Not found." << std::endl;
}

int main ()
{
	std::string s1;
	std::string s2;
	std::cout << "ENter string: " << std::endl;
	std::getline (std::cin, s1);
	std::cout <<"Enter string to be searched: "<<std::endl;
	std::getline (std::cin, s2);
	search (s1, s2);
	return 0;
}

