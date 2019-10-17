#include <iostream>
#include <string>

std::string& remove_spaces (std::string& s)
{
	   int j = 0;

	   for (int i = 0; i < (int) (s.length()); i ++)
	   {
			 if (s[i] != ' ')
			 {
				    s[j] = s[i];
				    j++;
			 }
	   }

	   s.erase (j, s.length());

	   s[j] = '\0';

	   return s;

}
/*
   Move spaces to the beggining of a string
 */

std::string& move_spaces_b (std::string& s)
{
	   auto len = s.length ();

	   for (int i = len ; i >=0; i --)
			 if (s[i] != ' ')
				    std::swap (s[i], s[len--]);

	   return s;
}

std::string& amend_sentences (std::string& s)
{
	std::string s1 = {' '};
	for (int i = 0; i < (int) s.length() -1; i ++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			
//			s[i] = s[i] + 32;
			s.insert (i, s1);
		}
	}

	return s;
}


int main ()
{
	   std::string s;

	   std::cout <<"Enter String: " <<std::endl;

	   std::getline (std::cin, s);

	   std::cout << s <<std::endl;

	   s = amend_sentences (s);

	   std::cout << s << std::endl;

	   std::cin.get ();

	   return 0;
}

