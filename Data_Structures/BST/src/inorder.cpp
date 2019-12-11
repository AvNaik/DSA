#include <iostream>
#include "../inc/inc.h"

void Node::inorder (Node* root)
{
	   if (root != nullptr)
	   {
			 inorder(root->left);
			 std::cout<< *(int*)root->data <<"\t";
			 inorder (root->right);
	   }
	   return;
}

Node* Node::in_succ (Node* root)
{
	   while (root != nullptr && root->left != nullptr)
			 root= root->left;

	   return root;
}
