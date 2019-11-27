#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define MAX_CHARS 26
#define MAX_SYMBOLS 128

bool str_compare (std::string& s1, std::string& s2)
{
	   return (s1.length() < s2.length());
}

/*
   Sort an array of strings. Vector is being used here as it is much more efficient than a conventional array of strings.
 */
void sort_vector (std::vector<std::string>& s)
{

	   std::sort (s.begin (), s.end(), str_compare);
}

/*
   Sort a string with no spacecs.
 */

int* str_sort (std::string& s)
{
	   int* array = new int[MAX_CHARS];

	   for (int i = 0; i < (int) s.length(); i++)
	   {
			 if (s[i] >= 'a' && s[i] <= 'z')
			 {
				    array [s[i] - 'a'] ++;
			 } else if (s[i] >= 'A' && s[i] <= 'Z')
			 {
				    array[s[i] - 'A'] ++;
			 }
	   }

	   return array;
}

std::string occurances (std::vector <std::string>& s)
{
	   std::map <std::string, int> m;

	   for (auto i: s)
			 m[i] ++;

	   int max_votes = 0;
	   std::string winner;

	   for (std::map <std::string, int>::iterator it = m.begin(); it !=m.end(); ++it)
	   {
			 if (max_votes < it->second)
			 {
				    max_votes = it->second;
			 }
	   }
	   for (std::map <std::string,int>::iterator it = m.begin(); it!= m.end(); ++it)
	   {
			 if (it-> second == max_votes)
			 {
				    winner = it->first;
			 }
	   }

	   return winner;


}
int main ()
{
	   std::vector <std::string> s;
	   std:: cout << "Enter number of entries to be made in te strings: " << std::endl;
	   int number = 0;
	   std::cin >> number;
	   std::string temp;

	   std::cout <<"Enter data: " << std::endl;

	   for (int i = 0; i <= number; i ++)
	   {
			 std::getline (std::cin, temp);
			 s.emplace_back(temp);
	   }

	   temp = occurances (s);
	   std::cout<<"Winner is: "<<temp<<std::endl;
	   /*
		 for (auto i: s)
		 std::cout << i << std::endl;

		 sort_vector(s);

		 for (auto i: s)
		 std::cout << i << std::endl;
	    *//*

		    std::string a;
		    std::cout << "Enter contents of the string: " << std:: endl;
		    std::getline (std::cin, a);

		    int *p = str_sort (a);

		    for (int i = 0; i < MAX_CHARS; i ++)
		    {
		    for (int j = 0; j < p[i]; j++)
		    {
		    std::cout << (char) ('a' + i);
		    }
		    }*/
	   std::cin.get ();

	   return 0;
}

