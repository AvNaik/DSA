#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
   Convert Number to binary form
 */
void binary (int number)
{	
	   unsigned i = 1 << 31;
	   while (i > 0)
	   {
			 (number & i) ? printf("1") : printf("0");
			 i = i >> 1;
	   }
	   printf("\n");
}

void i_binary (int number)
{
	   int result = 0;
	   unsigned i = 1 << 31;
	   while (i > 0)
	   {
			 result <<= 1;
			 if (number & i)
			 {
				    printf("1");
				    result |= 1;
			 } else 
			 {
				    printf("0");
				    result |= 0;
			 }
			 i >>= 1;
	   }
	   printf("\n");
	   printf("The binary number is: %d \n", result);
}


/*
   Determine if number is Even or Odd
 */

void determine (int number)
{
	   if (number & 1)
	   {
			 printf("Number is Odd \n");
			 return;
	   }
	   printf("Number is Even \n");
}

/*
   reverse a given number in its binary format
 */

void reverse (int number)
{
	   int count = sizeof(number)*8;
	   int result = 0;
	   while(number >0)
	   {
			 result <<= 1;
			 result |= number & 1;
			 number >>= 1;
			 count --;
	   }
	   printf("%d \n", result);
	   result <<= count;
	   printf("%d \n", result);
	   binary (result);
}

/*
   Check if n is a power of 2.
 */

void check (int number)
{
	   if (!(number & (number -1)))
	   {
			 printf("The given number a power of 2 \n");
	   }
}

/*
   Find the position of rightmost set bit
 */

void findposition (int number)
{
	   int count = 0;
	   if (number & 1)
	   {
			 printf("%d", count);
	   }

	   unsigned i = 1;
	   while (i < pow(2,31))
	   {
			 count ++;
			 if (number &i)
			 {
				    printf("%d \n", count);
				    return;
			 }
			 i <<= 1;
	   }
}
/*
   Determine parity of a binary number.
   The basic idea is to rest the set bits in the number one by one. The way this is achieved is by n&(n-1) which is reset the rightmost set bit of a number. We repeat the process until n becomes 0.
 */
void parity (int n)
{
	   int parity = 0;
	   while (n > 0)
	   {
			 n = n & (n-1);
			 parity ++;
	   }
	   if (parity % 2 == 0)
	   {
			 printf("Even parity. \n");	
	   } else
	   {
			 printf("Odd parity. \n");
	   }
	   return;
}

/*
   calculate the absolute value of number. The basic logic is that in signed representation of a number a negetive number will have its MSB as 1 while an unsigned number will have its MSB as 0. We exploit the same fact through mask of
   n >> 31. If the resultant mask is 0, the number is positive. If the mask is not 0, we EXOR n with the mask to obtain its absolute value.
 */

void absolute (int number)
{
	   int mask = number >> 31;
	   if (mask == 0)
	   {
			 printf("Number is positive. Absolute value is %d \n", number);
			 return;
	   }
	   printf("Number is negetive \n");
	   mask = -1;
	   number = (number ^ mask) +1;
	   printf("Absolute Value is: %d \n", number);
}

/*
   Swap two bits at given positions within the number provided. Initially, we check if the bits at given positions are same. If they are same, no need to exchange. If different we just exor them with 1 so as to swap.
 */
void swap (int number, int k, int m)
{
	   if ((number & (1 << k)) == (number & (1 << m)))
	   {
			 printf("Bits are same \n");
			 return;
	   }

	   number = number ^ (1 << k);
	   number = number ^ (1 << m);
	   printf("%d \n", number);
	   binary (number);
}

void add (int a, int b)
{
	   int carry = 0;
	   int n = sizeof(int) *8;
	   int* array = (int*) malloc (n);
	   int i = 0;
	   for (; i < n; i++)
	   {
			 if (a & (1<<i))
			 {
				    if (b & (1 << i))
				    {
						  if (carry)
						  {
								array[n-i-1] = 1;
						  } else
						  {
								array[n-i-1] = 0;
								carry = 1;
						  }
				    } else
				    {
						  if (carry)
						  {
								array[n-i-1] = 0;
						  } else
						  {
								array[n-i-1] = 1;
						  }
				    }
			 } else
			 {
				    if (b & (1<<i))
				    {
						  if (carry)
						  {
								array[n-i-1] = 0;
						  } else
						  {
								array[n-i-1] = 1;
						  }
				    } else
				    {
						  if (carry)
						  {
								array[n-i-1] = 1;
								carry = 0;
						  } else
						  {
								array[n-i-1] = 0;
						  }
				    }
			 }
	   }
	   printf("The result of addition is: \n");
	   for (int i = 0; i <  n; i ++)
			 printf("%d", array [i]);
	   printf("\n");

}

/*
   Function to find position of the only set bit in the program. The program utilizes the basic logic that only powers of 2 have thier single bit set. In the event the input number is not a power of 2 then return from the function. In
   the event it is, we increment a counter until we find the set bit.
 */

void find_set_bit (int number)
{                 
	   if ((number & number-1))
	   {
			 printf("The number is not a power of two \n");
			 return;
	   }
	   int counter = 0;
	   unsigned i = 1;
	   while (number > 0)
	   {
			 counter ++;
			 if (number &1)
				    break;
			 number >>= 1;
	   }
	   printf("The position is : %d \n", counter);
}

/*
   Check if two signs are opposite. Two numbers will provided. the function checks if thier signs are oposoite are same. The program takes advantage of sign bit, last bit of integers which is 0 for poistive integers and 1 for negetive ints.
 */

void check_sign (int a, int b)
{
	   if ((a>>31) & (b>>31))
	   {
			 printf("Signs are same \n");
			 return;
	   }
	   printf("Signs of two intgers are different. \n");
	   return;
}
/*
   Add one to a given number. To undertake the operation, we flip all the ones encountered in the number, until the rightmost zero i.e. till the rightmost zero we turn all ones to zero.. FInally, we flip the rightmost bit as well.
 */
void add_1 (int number)
{
	   unsigned i = 1;
	   while (number &i)
	   {
			 number ^= i;
			 i <<= 1;
	   }

	   number ^= i;

	   printf("The new number: %d \n", number);
}
/*
   Multiply a number by 3.5. We can multiply a number by 3.5 by multiplying the number by 2, dividing it by 2 individually and then adding the two operations with the original number. Multiplication by 2 is left shify by 1, dividing a
   number by 2 is right shift by 1.
 */

void mul_3 (int number)
{
	   number = number + (number >>1) + (number << 1);
	   printf("The new number multiplied by 3.5 is: %d \n", number);
}
/*
   Rotate the binary representation of a number by k bits. Initially what we do is store the k bits of the number to be rotated in a variable. Then we shift the number left or right by k. Las, we do an OR operation.
 */
void rotate_right (int number, int k)
{	
	   unsigned size = sizeof(int) *8;
	   int result = 0;
	   result = number << (size - k);
	   number = number >> k;
	   number = number | result;
	   printf("The rotated number is: %d \n", number);
	   binary (number);
}

void rotate_left (int number, int k)
{
	   unsigned size = sizeof(int)*8;
	   int result = 0;
	   result = number >> (size-k);
	   number = number << k;
	   number = number | result;
	   printf("The rotated number is: %d \n", number);
	   binary (number);

}

/*
   FUnction to check pverflow in addition of two numbers. The function utlizes the property that there can be overflow only when sign of the two input numbers is same and the sign of the answer is different.
 */

void chk_overflow (int a, int b)
{
	   int sum = a + b;

	   if ((a >> 31) == (b>>31))
	   {
			 if ((sum>>31) == (a >> 31))
			 {
				    printf("No overflow in addition \n");
			 } else
			 {
				    printf("Overflow in addition \n");
			 }
	   } else
	   {
			 printf("There cannnot be overflow \n");
	   }
}

void count_set_bits (int number)
{
	   unsigned i = 1;
	   int count = 0;
	   while (number > 0)
	   {
			 if (number & i)
				    count++;
			 number >>= 1;
	   }

	   printf("The number of bits in are: %d \n", count);
}

void bits_to_convert (int num1, int num2)
{
	   int num3 = num1 ^ num2;
	   unsigned i = 1;
	   int count = 0;
	   while (num3 > 0)
	   {
			 if (num3 & i)
			 {
				    count ++;
			 }
			 num3 >>= 1;
	   }

	   printf("the number of bits to be changed: %d \n", count);
}

/*
   Function to find a number occuring odd number of times in an array. The basic idea is to use EXOR upon all elements of the array. AT the end, we will get the element as a number EXOR-ed with itself yields that very number.
 */
/*
   void occurance (int* a)
   {
   int odd = 0;
   for (int i = 0; i < 9; i ++)
   {
   odd ^= a[i];
   }

   printf ("The element occuring odd number of times is: %d \n", odd);
   }
 */
int min (int a, int b)
{
	   return a + (a&b) - (a&b >> (sizeof (int) * 8 -1));
}

void greatest (int a, int b, int c)
{
	   int x = min (a, min(b, c));
	   printf("The minimum of the three numbers is: %d \n", x);
}

/*
	Function to swap even and odd numbered bits in a number. Basic idea is to use mask of 0xAAAAAAAA since it has all even bits set and 0x55555555 since it has all odd bits set. We use these masks so as to obtain the even and odd bits
	within the number. Then we shift the even bits right by 1 and odd bits left by 1 since that its what the task desires at the very basic level. We then combine the results.
*/

void swap_oe (int number)
{
	   int m1 = 0xAAAAAAAA;
	   int m2 = 0x55555555;
	   int r1 = number & m1;
	   int r2 = number & m2;
	   r1 >>= 1;
	   r2 <<= 1;
	   int final = r1 | r2;
	   printf("The exchanged number is: %d \n", final);
	   binary (final);
}

int main ()
{
	   int number = 0;
	   printf("Enter number: \n");
	   scanf("%d", &number);
	   binary (number);
	   determine (number);
	   reverse (number);
	   check (number);
	   findposition (number);
	   parity (number);
	   absolute (number);
	   swap (number, 2, 3);
	   add (18, 29);
	   find_set_bit (number);
	   check_sign (number, -100);
	   add_1 (number);
	   mul_3 (number);
	   rotate_right (number, 2);
	   i_binary (number);
	   chk_overflow(2147483647, 2147483647);
	   count_set_bits (number);
	   bits_to_convert (6, 7);
#if 0
	   int array [9];
	   printf("Enter elements: \n");
	   for (int i = 0; i < 9; i ++)
	   {
			 scanf("%d", &array[i]);
	   }
	   occurance (array);
#endif
	   greatest (1, 2, 3);
	   swap_oe (number);
	   return 0;

}


