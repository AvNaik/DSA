#include <iostream>
#include "../includes/ls.h"

void post(Node **head_ref, int value)
{
	   Node *new_element = new Node();
	   Node *elements = *head_ref;

	   if (*head_ref == nullptr)
			 *head_ref = new_element;

	   new_element->data = value;
	   new_element->next = *head_ref;
	   new_element->tail = elements->tail;
	   *head_ref = new_element;
}

void insert(Node *head_ref, int value)
{
	   Node *new_element = new Node();

	   if (head_ref == nullptr)
			 std::cout << "Invalid Opeartion \n";

	   new_element->data = value;
	   new_element->next = head_ref->next;
	   head_ref->next = new_element;
}

void append(Node **head_ref, int value)
{
	   Node *new_element = new Node();
	   Node *elements = *head_ref;
	   if (*head_ref == nullptr)
			 *head_ref = new_element;

	   new_element->data = value;
	   new_element->next = nullptr;

	   while (elements->next != nullptr)
	   {
			 elements = elements->next;
	   }
	   elements->next = new_element;
}

void appendt(Node **head_ref, int value)
{
	   Node *new_element = new Node();
	   Node *elements = *head_ref;

	   new_element -> data = value;
	   new_element -> next = nullptr;
	   new_element -> tail = new_element;

	   if (*head_ref == nullptr)
	   {
			 *head_ref = new_element;
			 return;
	   }
	   elements = elements->tail;
	   elements->next = new_element;

	   elements = *head_ref;
	   elements->tail = new_element;
}

void deletenode_value (Node** head_ref, int key)
{
	   Node* elements = *head_ref;
	   Node* previous;

	   if (elements != nullptr && elements -> data == key )
	   {
			 *head_ref = elements -> next;
			 delete elements;
			 return;
	   }

	   while (elements != nullptr && elements -> data != key)
	   {
			 previous = elements;
			 elements = elements -> next;
	   }

	   previous -> next = elements -> next;
	   delete elements;
}

void deletenode_index (Node** head_ref, int index)
{
	   Node* elements = *head_ref;
	   Node* previous;
	   int count = 1;
	   if (elements != nullptr && count == index)
	   {
			 *head_ref = elements ->next;
			 delete elements;
			 return;
	   }

	   while (elements != nullptr)
	   {
			 previous = elements;
			 elements = elements -> next;
			 count++;
			 if (count == index)
			 {
				    previous -> next = elements -> next;
				    delete elements;
				    return;
			 }
	   }
}

Node* deleteall (Node* head, int key)
{
	   Node* elements = head;
	   Node* previous = nullptr;

	   while (elements == head && (elements -> data) == key)
	   {
			 head = elements -> next;
			 delete elements;
			 elements = head;
	   }

	   while (elements -> next != nullptr)
	   {
			 previous = elements;
			 elements = elements -> next;
			 if ((elements -> data) == key)
			 {
				    previous -> next = elements -> next;
				    delete elements;
				    elements = previous;
			 }
	   }

	   return head;
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

	   Node *head = new Node ();
	   head = nullptr;
/*	   Node *first = new Node();
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

	   post(&head, 40);
	   insert(first, 15);
	   append(&head, 50);
	   appendt(&head, 60);
	   appendt(&head, 70);
	   appendt(&head, 80);
	   appendt(&head, 90);
	   printList (head);
	   deletenode_value (&head, 40);
	   deletenode_index (&head, 1);
	   deletenode_index (&head, 2);
	   */	   
			 appendt(&head, 1);
	   appendt(&head, 1);
	   appendt(&head, 1);

	   appendt (&head, 2);
	   appendt (&head, 3);
	   appendt(&head, 1);
	   head = deleteall (head, 1);
	   printList(head);

	   return 0;
}
