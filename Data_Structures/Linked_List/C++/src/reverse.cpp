#include <iostream>
#include "../includes/ls.h"

Node* element = NULL;

Node* appendt (Node* head_ref, int value)
{
	   Node* new_element = new Node ();
	   Node* elements = head_ref;

	   new_element -> data = value;
	   new_element -> next = nullptr;

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

/*
   Iterative version to completly reverse a given Linked List
*/

Node* reverse_iterative (Node* head_ref)
{
	   Node* elements = head_ref, *previous = nullptr, *follow = nullptr;

	   while (elements != nullptr)
	   {
			 follow = elements -> next;
			 elements -> next = previous;
			 previous = elements;
			 elements = follow;
	   }

	   std::cout << "Linked List Reversed." <<std::endl;
	   return previous;
}

/*
An alternative version to reverse a linked list utilizing a pointer to the head of the linked list. The solutiion is recursive.
*/

void reverse_recursive (Node** head_ref)
{
	   Node* first = nullptr, *rest = nullptr;

	   if (head_ref == nullptr)
	   {
			 return;
	   }

	   first = *head_ref;
	   rest = first -> next;

	   if (rest == nullptr)
			 return;

	   reverse_recursive (&rest);

	   first -> next -> next = first;
	   first -> next = nullptr;

	   *head_ref = rest;
}


/*
Recursive version to completly reverse a given linked list. With the method returning a pointer of the struct Node the function utlizes a global pointer of struct Node
*/

Node* reverse_recursive_alternative (Node* head_ref)
{
	   if (head_ref == nullptr)
	   {
			 return head_ref;
	   }

	   if (head_ref -> next == nullptr)
	   {
			 element = head_ref;
			 return head_ref;
	   }

	   Node* elements = reverse_recursive_alternative (head_ref -> next);
	   elements -> next = head_ref;
	   head_ref -> next = nullptr;
	   return head_ref;
}

/*
Iterative version to reverse a linked list in groups provided as function parameter
*/

Node* reverse_group_iterative (Node* head_ref, int group)
{
	   struct Node* elements = head_ref, * previous = nullptr, *follow = nullptr, *end = nullptr, *group_head = nullptr;
	   int count = 0, check = 0;

	   while (elements != nullptr)
	   {
			 count = 0;
			 previous = nullptr;
			 group_head = elements;
			 while (elements != nullptr && count < group)
			 {
				    count++;
				    follow = elements -> next;
				    elements -> next = previous;
				    previous = elements;
				    elements = follow;
			 }

			 if (check == 0)
			 {
				    check ++;
				    head_ref = previous;
			 }

			 if (end != nullptr)
				    end -> next = previous;

			 end = group_head;
	   }
	   std::cout << "Linked List reversed with group size of " << group << std::endl;
	   return head_ref;
}

/*
Recursive version to reverse a linked list in groups provided as function parameter.
*/

Node* reverse_group_recursive (Node* head_ref, int group)
{
	   Node* elements = head_ref, *previous = nullptr, *follow = nullptr;
	   int count = 0;
	   while (elements != nullptr && count < group)
	   {
			 count ++;
			 follow = elements -> next;
			 elements -> next = previous;
			 previous = elements;
			 elements = follow;
	   }

	   if (elements != nullptr)
			 head_ref -> next = reverse_group_recursive (elements, group);

	   return previous;
}


void printList (Node* head)
{
	   int count = 0;
	   std::cout <<"The elements of the Linked List are:" << std::endl;

	   while (head != nullptr)
	   {
			 count++;
			 std::cout << head -> data << std::endl;
			 head = head -> next;
	   }

	   std::cout <<"The number of elements in the Linked List are: " << count << std::endl;
	   return;
}

int main ()
{
	   Node* head = nullptr;

	   head = appendt (head, 10);
	   head = appendt (head, 20);
	   head = appendt (head, 30);
	   head = appendt (head, 40);
	   head = appendt (head, 50);
	   head = appendt (head, 60);
	   head = appendt (head, 70);
	   head = appendt (head, 80);
	   head = appendt (head, 90);
	   head = appendt (head, 100);

	   printList (head);

	   head = reverse_recursive_alternative(head);
	   // reverse_recursive(&head);
	   printList (element);
	   return 0;
}
