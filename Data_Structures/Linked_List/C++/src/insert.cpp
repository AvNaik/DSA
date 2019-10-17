/*
Program to insert elements at the head and at the tail of the Linked Lists without the use of double pointers as function parameters.
*/
#include <iostream>

struct Node
{
	   int data;
	   struct Node* next;

	   Node (int x)
	   {
			 data = x ;
			 next = NULL;
	   }
};

Node* insert (Node* head_ref, int value)
{
	   Node* new_element = new Node(value);

	   if (head_ref == nullptr)
	   {
			 head_ref = new_element;
			 return head_ref;
	   }

	   new_element -> next = head_ref;
	   head_ref = new_element;
	   return head_ref;
}

Node* insert_end (Node* head_ref, int value)
{
	   Node* new_element = new Node (value);
	   Node* elements = head_ref;

	   if (head_ref == nullptr)
	   {
			 head_ref = new_element;
			 return head_ref;
	   }

	   while (elements -> next != nullptr)
	   {
			 elements = elements -> next;
	   }

	   elements -> next = new_element;

	   return head_ref;
}

void printList (Node* head)
{
	   Node* elements = head;
	   while (elements != nullptr)
	   {
			 std::cout << elements-> data << std::endl;
			 elements = elements -> next;
	   }
}
int main ()
{
	   Node* head = NULL;//new Node (5);

	   head = insert (head, 10);

	   head = insert (head, 20);

	   head = insert_end (head, 30);
	   head = insert_end (head, 40);
	   printList (head);

	   return 0;
}
