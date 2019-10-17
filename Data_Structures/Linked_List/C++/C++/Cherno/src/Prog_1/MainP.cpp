#include <iostream>
#include <string>
#include "include/l.h"
#include "FuncP.cpp"

extern int var;
int main ()
{

	   logs("Hello World");
	   //	std::cout<<var <<std::endl;
	   var++;
	   std::cout<<var <<std::endl;

	   int p, q, r, a;
	   char d;
	   int& x = r;

	   std::cout<<"Numbers: "<<std::endl;
	   std::cin >> p >> q >> x;

	   std::cin.ignore(256, '\n');
	//   char* s = &d;
	   std::cout<<"Choice: " <<std::endl;
	   std::cin.getline (&d, 2);
	   //	   std::cin >> *s;


	   int *w = calculation (p, &q, x, &d);

	   std::cout << *w << std::endl;

	   std::string name = GetName ();
	   a = name.size();
	   std::cout << name <<std::endl << a <<std::endl;

	   std::cin.get();

	   return 0;	
}

