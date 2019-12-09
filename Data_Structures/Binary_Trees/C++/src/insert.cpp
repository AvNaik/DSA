#include <iostream>

class Node
{
	   void* data;
	   Node* left;
	   Node* right;
	   public:
	   void create (Node** root);
	   void preorder (Node* root);
	   void inorder (Node* root);
	   void levelorder (Node* root);
	   void postorder (Node* root);
	   void delete_last (Node* root, Node* temp);
	   void delete_node (Node**root, int key);
	   void siblings (Node* root, int node1, int node2);
	   void node_level (Node* root, int node1);
	   void cousins (Node* root);
};

class Queue
{
	   Node* node;
	   Queue* next;
	   public:
	   Queue (Node* value):
			 node(value), next(NULL)
	   {
	   }

	   void enqueue (Queue**head_ref, Node* value);
	   Node* dequeue (Queue** head_ref);
};

Queue* tail = nullptr;

void Queue::enqueue (Queue** head_ref, Node* value)
{
	   Queue* new_element = new Queue (value);
	   if (*head_ref == nullptr)
	   {
			 *head_ref = new_element;
			 tail = new_element;
			 return;
	   }
	   struct Queue* element = tail;
	   element->next = new_element;
	   tail = new_element;
	   return;
}

Node* Queue:: dequeue (Queue** head_ref)
{
	   if (*head_ref == nullptr)
	   {
			 std::cout <<"Queue is empty. Need to enqueue" << std::endl;
			 return NULL;
	   }
	   Queue* q = *head_ref;
	   Node* temp = q->node;
	   *head_ref = q->next;
	   delete q;
	   return temp;
}

void Node::create (Node** root)
{
	   Node* temp = nullptr, *d_temp = nullptr;
	   Queue* q = nullptr;
	   Node* new_element = new Node();
	   new_element->data = new int;
	   int x  = 0;
	   std::cout << "Enter the vaue of root: \t";
	   std::cin >> x;
	   *(int*)new_element->data = x;
	   new_element->left = NULL;
	   new_element->right = NULL;
	   if (*root == nullptr)
	   {
			 *root = new_element;
	   }
	   q->enqueue (&q, new_element);
	   while (q != nullptr)
	   {
			 d_temp = q->dequeue (&q);
			 std::cout << "Enter the left child of " << *(int*)d_temp->data <<" Node: \t";
			 std::cin >>x;
			 if (x != -1)
			 {
				    temp = new Node ();
				    temp->data = new int;
				    *(int*)temp->data = x;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->left = temp;
				    q->enqueue (&q, temp);
			 }
			 std::cout << "Enter the right child of " << *(int*)d_temp->data <<" Node: \t";
			 std::cin >>x;
			 if (x != -1)
			 {
				    temp = new Node ();
				    temp->data = new int;
				    *(int*)temp->data = x;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->right = temp;
				    q->enqueue (&q, temp);
			 }
	   }
}
/*
   Iterative and recursive functions for preorder, inorder and postorder traversal of binary tree. The iterative versions use stack and as such stack has been defined below.
 */

class Stack
{
	   Node* node;
	   Stack* next;
	   public:
	   Stack (Node* value):
			 node (value), next(nullptr) {}
	   void push (Stack** head_ref, Node* value);
	   Node* pop (Stack** head_ref);
};

void Stack::push (Stack** head_ref, Node* value)
{
	   Stack* new_element = new Stack(value);
	   if (*head_ref == nullptr)
	   {
			 *head_ref = new_element;
			 return;
	   }
	   new_element->next = *head_ref;
	   *head_ref = new_element;
	   return;
}

Node* Stack::pop (Stack** head_ref)
{
	   if (*head_ref == nullptr)
	   {
			 std::cout <<"Stack is Empty. Need to push."<<std::endl;
			 return NULL;
	   }
	   Stack* s = *head_ref;
	   Node* temp = s->node;
	   *head_ref = s->next;
	   delete s;
	   return temp;
}

void Node::preorder (Node* root)
{
	   if (root == nullptr)
			 return;
	   Stack* temp = nullptr;
	   while (root != nullptr || temp != nullptr)
	   {
			 if (root != nullptr)
			 {
				    std::cout << *(int*)root->data <<"\t";
				    temp->push (&temp, root);
				    root = root->left;
			 } else
			 {
				    root = temp->pop (&temp);
				    root = root->right;
			 }
	   }
	   std::cout<<std::endl;
}
#if 0
void Node::preorder (Node* root)
{
	   if (root != nullptr)
	   {
			 std::cout << *(int*)root->data <<std::endl;
			 Node::preorder (root->left);
			 Node::preorder (root->right);
	   }
}


void Node::inorder (Node* root)
{
	   if (root == nullptr)
			 return;
	   Stack* s = nullptr;
	   while (root != nullptr || s != nullptr)
	   {
			 if (root != nullptr)
			 {
				    s->push (&s, root);
				    root = root->left;
			 } else
			 {
				    root = s->pop(&s);
				    std::cout << *(int*)root->data <<"\t";
				    root = root->right;
			 }
	   }

	   std::cout<<std::endl;
}
#endif
void Node::inorder (Node* root)
{
	   if (root != nullptr)
	   {
			 inorder (root->left);
			 printf("%d \t", *(int*)root->data);
			 inorder (root->right);
	   }

}

void Node::postorder (Node* root)
{
	   if (root != nullptr)
	   {
			 postorder (root->left);
			 postorder (root->right);
			 std::cout << *(int*)root->data <<" \t ";
	   }
}

/*
   Funtion for level order traversal of binary tree. The function utiuilizes a Queue which is same as the one used for insertion in the  binary tree.
 */
void Node::levelorder (Node* root)
{
	   if (root == nullptr)
			 return;
	   Queue* q = nullptr;
	   std::cout << *(int*)root->data << " \t ";
	   int count = 1;
	   q->enqueue (&q, root);
	   while (q != nullptr)
	   {
			 root = q->dequeue (&q);
			 if (root->left)
			 {
				    count ++;
				    std::cout <<*(int*)root->left->data <<" \t";
				    q->enqueue (&q, root->left); 
			 }

			 if (root->right)
			 {
				    count++;
				    std::cout <<*(int*)root->right->data <<" \t";
				    q->enqueue (&q, root->right);
			 }
	   }
	   std::cout << std::endl;
	   std::cout <<"The number of elements in the Binary Tree are: "<< count <<std::endl;
}

void Node::delete_last (Node* root, Node* temp)
{
	   Queue* q = nullptr;
	   q->enqueue (&q, root);
	   while (q != nullptr)
	   {
			 root = q->dequeue(&q);
			 if (root == temp)
			 {
				    root = nullptr;
				    delete temp;
				    return;
			 }
			 if (root->left)
			 {
				    if (root->left == temp)
				    {	
						  root->left = nullptr;
						  delete temp;
						  return;
				    } else
						  q->enqueue (&q, root->left);
			 }
			 if (root->right)
			 {
				    if (root->right == temp)
				    {
						  root->right = nullptr;
						  delete temp;
						  return;
				    } else
						  q->enqueue (&q, root->right); 
			 }
	   }
}

void Node::delete_node (Node** root, int key)
{
	   Node* elements = *root;
	   if (elements == nullptr)
	   {
			 std::cout <<"Binary Tree is empty" <<std::endl;
			 return;
	   }
	   if (elements->left == nullptr && elements->right == nullptr)
	   {
			 if (*(int*)elements->data == key)
			 {
				    std::cout <<"Binary Tree deleted completely" <<std::endl;
				    delete elements;
				    return;
			 } else
			 {
				    return;
			 }
	   }
	   Node* del = nullptr;
	   Queue* q  = nullptr;
	   q->enqueue (&q, elements);
	   while (q != nullptr)
	   {
			 elements = q->dequeue (&q);
			 if (*(int*)elements->data == key)
			 {
				    del = elements;
			 }
			 if (elements->left)
				    q->enqueue (&q, elements->left);
			 if (elements->right)
				    q->enqueue (&q, elements->right);
	   }

	   if (del != nullptr)
	   {
			 int x  = *(int*)elements->data;
			 *(int*)del->data = x;
			 delete_last (*root, elements);
	   }

}

void Node::siblings (Node* root, int node1, int node2)
{
	   if (root == nullptr)
			 return;
	   Queue* q = nullptr;
	   if (root->left != nullptr && root->right != nullptr)
	   {
			 if ((*(int*)root->left->data == node1 && *(int*)root->right->data == node2) || (*(int*)root->right->data == node1 && *(int*)root->left->data == node2))
			 {
				    std::cout <<"The given Nodes are siblings as they have same parent." <<std::endl;
				    return;
			 }
	   }
	   q->enqueue (&q, root);
	   while (q != nullptr)
	   {
			 root = q->dequeue (&q);
			 std::cout << "Dequed Node:" <<*(int*)root->data <<std::endl;
			 if (root->left != nullptr && root->right != nullptr)
			 {
				    if ((*(int*)root->left->data == node1 && *(int*)root->right->data == node2) || (*(int*)root->right->data == node1 && *(int*)root->left->data == node2))
				    {
						  std::cout <<"The given Nodes are siblings as they have same parent." <<std::endl;
						  return;

				    }
			 }
			 if (root->left)
				    q->enqueue (&q, root->left);
			 if (root->right)
				    q->enqueue(&q, root->right);
	   }

	   std::cout << "The given nodes are not siblings as they have different parents" <<std::endl;
}

void Node::node_level (Node* root, int node1)
{
	   if (root == nullptr)
			 return;
	   if (*(int*)root->data == node1)
	   {
			 std::cout <<"Level of node is 1" <<std::endl;
	   }

	   Stack* s = nullptr;
	   int level = 1;
	   while (root != nullptr || s != nullptr)
	   {
	   		if (root->left || root->right)
			{
				level ++;
			}
			 if (root != nullptr)
			 {
				    s->push (&s, root);
				    if (*(int*)root->data == node1)
				    {
						  std::cout <<"The level of the Node is" << level <<std::endl;
						  return;
				    }
				    root = root->left;
			 } else
			 {
				    root = s->pop (&s);
				    if ((*(int*)root->data == node1) && level > 0)
				    {
						  std::cout <<"The level of the node is: " <<level << std::endl;
						  return;
				    }
				    root = root->right;

			 }
	   }


}

void Node::cousins (struct Node* root)//, int node1, int node2)
{
	   if (root == nullptr)
			 return;
	   struct Queue* q = nullptr;
	   int level = 0;
	   q->enqueue(&q, root);
	   while (q != nullptr)
	   {
			 root = q->dequeue(&q);
			 if (root->left != nullptr || root->right != nullptr)
				    level++;

			 if (root->left)
			 {
				    q->enqueue (&q, root->left);
			 }
			 if (root->right)
			 {
				    q->enqueue (&q, root->right);
			 }
	   }

	   std::cout << "Levels in a tree are: "<< level<<std::endl;

}
int main ()
{
	   Node* root = nullptr;
	   root->create (&root);
	   std::cout << "PREORDER: \t";
	   root->preorder (root);
	   std::cout << std::endl;
	   std::cout << "INORDER \t";
	   root->inorder (root);
	   std::cout << std::endl;
	   std::cout << "PREORDER: \t";
	   root->postorder (root);
	   std::cout << std::endl;

	   std::cout << "LEVEL ORDER: \t";
	   root->levelorder (root);

	   //	   root->delete_node (&root, 8);
	   //	   std::cout << "LEVEL ORDER: \t";
	   //	   root->levelorder (root);

	   root->siblings (root, 14, 65);
	   root->node_level (root, 3);

	   std::cin.get();
	   return 0;
}
