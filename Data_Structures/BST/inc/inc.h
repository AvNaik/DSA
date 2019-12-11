#ifndef CLASSES
#define CLASSES

class Node
{
	void* data;
	Node* left;
	Node* right;
	public:
	Node (int value):
		left(nullptr), right (nullptr)
	{
		data = new int;
		*(int*)data = value;
	}

	Node ():
		left(nullptr), right (nullptr)
	{
		data = new int;
		*(int*)data = 0;
	}

	void create_i (Node** root, int value);
	void create_r (Node** root, int value);
	Node* search (Node* root, Node** parent, int key);
	Node* in_succ (Node* root);
	void delete_node (Node* root, int key);
	void inorder (Node* root);
};

#endif
