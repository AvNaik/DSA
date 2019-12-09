#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
/*
   The below function returns the lexographically first non repeating character within the string.
 */
void occurance (std::string& s)
{
	   int n = s.length();
	   int index = 0;
	   std::cout <<s <<std::endl;
	   int array [26] = {0};
	   for (int i = 0; i < n; i ++)
	   {
			 if (s[i] >= 'a' && s[i] <= 'z')
			 {
				    index = (int) (s[i] - 'a');
				    array[index] ++;
			 } else if (s[i] >= 'A' && s[i] <= 'Z')
			 {
				    index = (int)(s[i] - 'A');
				    array[index]++;
			 }
	   }
	   for (int i = 0; i < 26; i ++)
	   {
			 if (array[i] == 1)
			 {
				    std::cout << i+1 << "   "<<(char) (i + 'a') <<std::endl;
				    return;
			 }
	   }
}

#if 0
The idea is to use a DLL (Doubly Linked List) to efficiently get the first non-repeating character from a stream. The DLL contains all non-repeating characters in order, i.e., the head of DLL contains first non-repeating character, the second node contains the second non-repeating and so on.
We also maintain two arrays: one array is to maintain characters that are already visited two or more times, we call it repeated[], the other array is array of pointers to linked list nodes, we call it inDLL[]. The size of both arrays is equal to alphabet size which is typically 256.

Create an empty DLL. Also create two arrays inDLL[] and repeated[] of size 256. inDLL is an array of pointers to DLL nodes. repeated[] is a boolean array, repeated[x] is true if x is repeated two or more times, otherwise false. inDLL[x] contains pointer to a DLL node if character x is present in DLL, otherwise NULL.
Initialize all entries of inDLL[] as NULL and repeated[] as false.
To get the first non-repeating character, return character at head of DLL.
Following are steps to process a new character ‘x’ in a stream.
If repeated[x] is true, ignore this character (x is already repeated two or more times in the stream)
If repeated[x] is false and inDLL[x] is NULL (x is seen first time). Append x to DLL and store address of new DLL node in inDLL[x].
If repeated[x] is false and inDLL[x] is not NULL (x is seen second time). Get DLL node of x using inDLL[x] and remove the node. Also, mark inDLL[x] as NULL and repeated[x] as true.
Note that appending a new node to DLL is O(1) operation if we maintain tail pointer. Removing a node from DLL is also O(1). So both operations, addition of new character and finding first non-repeating character take O(1) time.
#endif

int main ()
{
	   std::string s;
	   std::cout <<"Enter String" <<std::endl;
	   std::getline (std::cin, s);
	   occurance (s);
	   std::cin.get();
	   return 0;
}
