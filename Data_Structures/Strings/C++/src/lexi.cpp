#include <iostream>
#include <string>

#if 0
Lexicographically smallest string of length N and sum K.
Approach:

Initialize char array of size N and fill all the element by ‘a’.
Start traversing from the end of the array and replace the elements of the array by ‘z’ if K ≥ 26 or replace it by the character having ASCII value (K + 97 – 1).
At the same time decrease the value of K by replaced element value i.e. for a = 1, b = 2, c = 3, …, z = 26.
Also, note that we are subtracting previous element value i.e. (total ‘a’) before current element and adding the same before the end of for loop.
Check for K < 0 condition and break the for loop.
Return the new string formed by the elements of the char array as the answer.
#endif

void lexi (int n, int k)
{
	std::string s;
	for (int i = 0; i < n ; i ++)
	{
		s.push_back('a');
	}
	for (int i = n-1; i>=0; i --)
	{
		k -= i;
		if (k >0)
		{
			if (k>= 26)
			{
				s[i] = 'z';
				k -= 26;
			} else
			{
				s[i] = (char)(97+k -1);
				k = k - (s[i] - 'a' +1);
			}
		} else
		{
			break;
		}
		k = k+i;
	}

	std::cout <<s <<std::endl;
}

int main ()
{
	int n=0 , k=0;
	std::cout <<"Enter values of n and k" <<std::endl;
	std::cin >> n >> k;
	std::cout << n <<"    " << k <<std::endl;
	lexi (n, k);

	std::cin.ignore();
	std::cin.get();
	return 0;


}
