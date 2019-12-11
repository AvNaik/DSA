#include <iostream>
#include "../inc/inc.h"

void Node::delete_node (Node* root, int key)
{
	if (root == nullptr)
		return;
	
	 Node* parent = new Node ();
	 Node* child = new Node();
	 if (*(int*)root->data == key)
	 {
	 	Node* successor = new Node ();
		successor = in_succ(root->right);
		child = search(root, &parent, *(int*)successor->data);
		if (parent->left == child)
		{
			parent->left = child->right;
		} else
		{
			parent->right = child->right;
		}
		root->data = child->data;
		delete child;
		return;
	 }

	 child = search (root, &parent, key);

	 if (child->left == nullptr && child->right == nullptr)
	 {
	 	if (parent->left == child)
			parent->left = nullptr;
		else
			parent->right = nullptr;

		delete child;
		return;
	 }

	 if ((child->left != nullptr && child->right == nullptr) || (child->left == nullptr && child->right != nullptr))
	 {
	 	if (parent->left == child)
		{
			if (child->left != nullptr)
			{
				parent->left = child->left;
			} else
			{
				parent->left = child->right;
			}
		} else if (parent->right == child)
		{
			if (child->left != nullptr)
			{
				parent->right = child->left;
			} else
			{
				parent->right = child->right;
			}
		}
		delete child;
		return;
	 }

	 if (child->left != nullptr && child->right != nullptr)
	 {
	 	Node* successor = new Node();
		successor = in_succ(child->right);
		successor = search(root, &parent, *(int*)successor->data);
		child->data = successor->data;
		if (parent->left == successor)
		{
			parent->left = successor->right;
		}else
		{
			parent->right = successor->right;
		}

		delete successor;
		return;
	 }
}
