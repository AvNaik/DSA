#include <iostream>
#include "../inc/inc.h"

Node* Node::search (Node* root, Node** parent, int key)
{
	   if (root == nullptr)
			 return NULL;

	   while (root != nullptr)
	   {
			 *parent = root;
			 if (*(int*)root->data >key)
			 {
				    root = root->left;
			 } else
			 {
				    root = root->right;
			 }

			 if (*(int*)root->data == key)
			 {
				    return root;
			 }
	   }
	   return NULL;
}
