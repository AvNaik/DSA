#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

void appendt (struct Node** head_ref, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   struct Node* elements = *head_ref;

	   if (*head_ref == NULL)
			 *head_ref = new_element;

	   new_element -> data = value;
	   new_element -> next = NULL;

	   elements = elements -> tail;
	   elements -> next = new_element;
	   elements = *head_ref;
	   elements -> tail = new_element;
	   return;
}

/*
Two functions to rotate a given Linked List by the value specified as a function parameter.
*/
void rotate (struct Node** head_ref, int value)
{
	   int count = 1;
	   struct Node* elements = *head_ref;
	   struct Node* new_head;
	   if (value == 0)
			 return;
	   while (elements != NULL && count < value)
	   {
			 count++;
			 elements  = elements -> next;
	   }

	   new_head = elements;

	   while (elements -> next != NULL)
	   {
			 elements = elements -> next;
	   }

	   elements -> next = *head_ref;
	   *head_ref = elements;

	   *head_ref = new_head -> next;

	   new_head -> next = NULL;
	   return;
}


struct Node* rotate_alternative (struct Node* head_ref, int value)
{
struct Node* elements = head_ref;
int count = 1;
struct Node* tail = NULL;

if (head_ref == NULL)
return head_ref;

while(elements != NULL && count < value)
{
count ++;
elements = elements -> next;
}

tail = elements;

while (elements -> next != NULL)
elements = elements -> next;

elements -> next = head_ref;
head_ref = tail -> next;

tail -> next = NULL;

return head_ref;
}


void printList (struct Node* head)
{
	   int count = 0;
	   printf("The element of Linked list are: \n");
	   while (head != NULL)
	   {
			 count ++;
			 printf("%d \n", head -> data);
			 head = head -> next;
	   }

	   printf ("The Number of elements in the linked list are: %d \n", count);
}

int main ()
{
	   struct Node* head = (struct Node*) malloc (sizeof(struct Node));

	   head -> data = 10;
	   head -> next = NULL;
	   head -> tail = head;

	   appendt (&head, 20);
	   appendt(&head, 30);
	   appendt(&head, 40);
	   appendt(&head, 50);
	   appendt(&head, 60);
	   appendt (&head, 70);
	   appendt(&head, 80);
	   printList (head);

	   head = rotate_alternative (head, 3);
	   printList (head);
}
