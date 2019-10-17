#include "stdio.h"
#include "stdlib.h"
#include "ls.h"
#include "stdbool.h"
#include "assert.h"


void appendt(struct Node** head_ref, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   struct Node* elements = *head_ref;

	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
	   }
	   new_element -> data = value;
	   new_element -> next = NULL;
	   new_element -> tail = new_element;

	   elements = elements -> tail;
	   elements -> next  = new_element;
	   elements = *head_ref;
	   elements -> tail = new_element;
}

bool search (struct Node* head_ref, int key)
{
	   while (head_ref != NULL )
	   {
			 if (head_ref -> data == key)
			 {
				    return true;
			 }
			 head_ref = head_ref -> next;
	   }
	   return false;
}

int getNth (struct Node* head_ref, int index)
{
	   struct Node* element = head_ref;
	   int count = 0;
	   while (element != NULL)
	   {
			 if (index == count)
			 {
				    return element -> data;
			 }
			 count++;
			 element = element -> next;
	   }
	   printf("index is longer than the length of the Linked List \n");
	   return 0;
}

int searchelement (struct Node* head_ref, int key)
{
	   int counter = 0;
	   while (head_ref != NULL)
	   {
			 if (head_ref -> data == key)
			 {
				    counter++;
			 }
			 head_ref = head_ref -> next;
	   }
	   return counter;
}

int searchelementr (struct Node* head_ref, int key)
{
	   int counter = 0;
	   if (head_ref == NULL)
			 return 0;
	   if (head_ref -> data == key)
			 return 1 + searchelementr (head_ref-> next, key);

	   return searchelementr (head_ref -> next, key);
}


void printList (struct Node*  head_ref)
{
	   int count = 0;
	   printf("The number of elements in the Linked List are: \n");
	   while (head_ref != NULL)
	   {
			 count++;
			 printf("%d \n", head_ref -> data);
			 head_ref = head_ref -> next;
	   }

	   printf ("The Number of nodes in the linked list are: %d \n", count);
}

int main()
{
	   struct Node* head = (struct Node*) malloc (sizeof(struct Node));
	   struct Node* first = (struct Node*) malloc (sizeof(struct Node));
	   struct Node* second = (struct Node*) malloc (sizeof(struct Node));

	   head -> data = 10;
	   head -> next = first;
	   head -> tail = second;

	   first -> data = 20;
	   first -> next = second;

	   second -> data = 30;
	   second -> next = NULL;

	   appendt (&head, 40);
	   appendt (&head, 50);

	   appendt (&head, 10);
	   appendt(&head, 10);
	   appendt (&head, 10);
	   printList (head);

	   search (head, 40) ? printf ("True \n") : printf("False\n");
	   search (head, 50) ? printf ("True \n") : printf("False\n");

	   printf("The number of the occurances: %d \n", searchelementr (head, 10));

	   printf ("%d \n" , getNth (head, 1));
}
