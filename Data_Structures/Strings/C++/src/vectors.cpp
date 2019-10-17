#include <iostream>
#include <vector>

std::vector<int> manipulate_temp (std::vector<int>& s)
{
	   std::vector<int> v;
	   int n_days = 0;
	   for (int i = 0; i < (int) (s.size() -1 ); i ++)
	   {
			 if (s[i] <= s[i+1])
			 {
				    n_days = 1;
				    v.emplace_back(n_days);
			 } else if (s[i] > s[i+1])
			 {
				    int j = i +2;
				    n_days = 2;
				    while (s[i] > s[j] && j < (int)s.size())
				    {
						  n_days++;
						  j++;
				    }
				    if (j == (int)s.size())
				    {
						  n_days = 0;
				    }
				    v.emplace_back(n_days);
			 }	
			 }
	   v.emplace_back(0);

	   return v;
}


int main ()
{

	   std::vector<int> s;
	   int numbers = 0;
	   std::cout <<"Enter Tempretures:" << std::endl;
	   for (int i = 0; i < 8; i++)
	   {
			 std::cin >> numbers;
			 s.emplace_back(numbers);
	   }
	   std::cout << s.size() <<std::endl;

	   std::vector <int> t = manipulate_temp(s);

	   for (auto i: t)
			 std::cout <<i << std::endl;
}
