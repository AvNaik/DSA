#include <stdio.h>
#include "ls.h"

void incre()
{	
	x++;
	x++;
	static int a = 0;
	a++;


	printf("%d \n", x);
	printf("%d \n", a);
}
#if 0
int main ()
{

	incre ();
	a++;
	a++;
	printf("%d \n", a);
}
#endif
