#include <iostream>
#include "../inc/inc.h"

int main ()
{
	   Node* root = nullptr;
	   int number = 0;
	   std::cout <<"Please enter the number of Nodes within the binary tree" <<std::endl;
	   std::cin >> number;
	   int* array = new int [number];
	   std::cout <<"Enter elements within the array" <<std::endl;
	   for (int i = 0; i < number; i++)
			 std::cin >> array[i];

	   /*
		 for (int i = 0; i < number; i ++)
		 root->create_r (&root, array[i]);

		 std::cout <<"INORDER: \t";
		 root->inorder(root);
		 std::cout <<std::endl;

		 root->delete_node (root, 35);

		 std::cout <<"INORDER: \t";
		 root->inorder(root);
		 std::cout <<std::endl;
	    */
	   root->construct (&root, array, number);

	   std::cout <<"INORDER: \t";
	   root->inorder(root);
	   std::cout <<std::endl;

	   std::cin.ignore();
	   std::cin.get();
	   return 0;
}
