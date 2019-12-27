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
	   void construct (Node** root, int* arr, int len);
};


class Stack
{
	   Node* node;
	   Stack* next;

	   public:
	   Stack(Node* value):
			 node(value), next(nullptr)
	   {}
	   int isSempty (Stack* s);	
	   void push (Stack** s, Node* value);
	   Node* pop (Stack** s);
	   Node* peek (Stack* s);

};

#endif
