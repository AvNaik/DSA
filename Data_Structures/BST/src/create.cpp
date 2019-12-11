#include <iostream>
#include "../inc/inc.h"

void Node::create_i (Node** root, int value)
{
	   Node* new_element = new Node (value);
	   Node* element = *root;
	   Node* tail = nullptr;
	   if (element == nullptr)
	   {
			 *root = new_element;
			 return;
	   }

	   while (element != nullptr)
	   {
			 tail = element;	
			 if (*(int*)element->data == value)
			 {
				    std::cout <<"Cannot enter duplicate elements." <<std::endl;
				    return;
			 } else if (*(int*)element->data > value)
			 {
				    element = element->left;
			 } else if (*(int*)element->data < value)
			 {
				    element = element->right;
			 }
	   }

	   if (*(int*)tail->data > value)
	   {
			 tail->left = new_element;
	   } else
	   {
			 tail->right = new_element;
	   }
	   return;
}

void Node:: create_r (Node** root, int value)
{
	   Node* element = *root;
	   if (element == nullptr)
	   {
			 Node* new_element = new Node(value);
			 *root = new_element;
			 return;
	   }

	   if (*(int*)element->data == value)
	   {
			 std::cout <<"Cannot enter duplicate elements" <<std::endl;
			 return;
	   } else if (*(int*)element->data > value)
	   {
			 create_r (&element->left, value);
	   } else if (*(int*)element->data < value)
	   {
			 create_r (&element->right, value);
	   }

	   return;
}
