#include <iostream>
#include "../includes/ls.h"

void appendt(Node **head_ref, int value)
{
	   Node *new_element = new Node();
	   Node *elements = *head_ref;

	   if (*head_ref == nullptr)
			 *head_ref = new_element;

	   new_element->data = value;
	   new_element->next = nullptr;

	   elements = elements->tail;
	   elements->next = new_element;

	   elements = *head_ref;
	   elements->tail = new_element;
}

void rotate (Node** head_ref, int value)
{
	   int count = 1;
	   Node* elements = *head_ref, *previous;

	   if (value == 0)
			 return;

	   while (elements != nullptr && count < value)
	   {
			 count++;
			 elements = elements -> next;
	   }

/*	   if (count == value)
			 return;
*/
	   previous = elements;

	   while (elements -> next != nullptr)
	   {
			 elements = elements -> next;
	   }

	   elements -> next = *head_ref;
	   *head_ref = elements;

	   *head_ref = previous -> next;
	   previous -> next = nullptr;
	   return;

}
void printList(const Node *head_ref)
{
	   int count = 0;
	   const Node *elements = head_ref;
	   std::cout << "The Element od the linked list are: " << std::endl;
	   while (elements != nullptr)	
	   {
			 count++;
			 std::cout << elements->data << std::endl;
			 elements = elements->next;
	   }
	   std::cout << "The Number of elements in the Linked list are: " << count << ::std::endl;
}
int main()
{

	   Node *head = new Node();
	   Node *first = new Node();
	   Node *second = new Node();

	   head->data = 10;
	   head->next = first;
	   head->tail = second;

	   first->data = 20;
	   first->next = second;
	   first->tail = second;

	   second->data = 30;
	   second->next = nullptr;
	   second->tail = second;

	   appendt(&head, 40);
	   appendt(&head, 50);
	   appendt(&head, 60);
	   appendt(&head, 70);
	   appendt(&head, 80);
	   appendt(&head, 90);
	   printList (head);
	   rotate (&head, 6);
	   printList(head);

	   return 0;
}
