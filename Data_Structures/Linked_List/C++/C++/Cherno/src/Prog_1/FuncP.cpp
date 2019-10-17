#include <iostream>
#include <sstream>
#include <string>
#include "include/l.h"

int var = 25;
void logs (const char *message)
{
	   std:: cout << var << std::endl;
	   std::cout << message <<std::endl;
}

auto GetName ()
{
	   return "Avadhut Naik";
}

/*
   Pointers, Call by Value, Call by Reference
 */

int* calculation (int a, int *b, int& c, char* d)
{

	   int result;
	   int* r = &result;

	   if (*d =='a' || *d == 'A')
	   {
			 *r = a+ (*b) + c;
	   } else if (*d == 'm' || *d == 'M')
	   {
			 *r = a * (*b) *c;
	   }

	   return r;


}

