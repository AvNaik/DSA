#include "stdio.h"
#include <stdlib.h>
#include "ls.h"

void push (struct Node** head_ref, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof (struct Node));
	   struct Node* elements = *head_ref;
	   new_element -> data = value;
	   new_element -> next = *head_ref;
	   new_element -> tail = elements -> tail;
	   *head_ref = new_element;
}

void insert (struct Node* obj, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   if (obj == NULL)
	   {
			 printf("INivalid Opeartion \n");
			 return;
	   }
	   new_element -> data = value;
	   new_element -> next = obj -> next;
	   new_element -> tail = obj ->tail;
	   obj -> next = new_element;
}

/*
   An alternative appproach to reduce the time complexity to O(1) for inserting element into a linked list at its tail .The method employs a pointer to the tail of the linked list which will be appropriately updated when element insertion is undertaken.
 */
void appendt(struct Node** head_ref, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));

	   struct Node* element = *head_ref;

	   if (*head_ref ==NULL)
	   {
			 *head_ref = new_element;
	   }

	   new_element -> data = value;
	   new_element -> next = NULL;
	   new_element -> tail = new_element;

	   element = element -> tail;
	   element -> next = new_element;
	   element = *head_ref;
	   element -> tail = new_element;
}

/*
Iterative and recursive Functions to get count of the number of elements in a linked list.
*/
void getCount (struct Node* head_ref)
{
	   int count = 0;

	   while (head_ref != NULL)
	   {
			 count ++;
			 head_ref = head_ref -> next;
	   }

	   printf ("The number of elements in Linked List are: %d \n", count);
}

int getCountr (struct Node* head_ref)
{
	   int count = 0;
	   if (head_ref == NULL)
			 return 0;

	   return 1 + getCountr (head_ref -> next);
}

void printList (struct Node* head_ref)
{
	   if (head_ref == NULL)
	   {
			 printf("The linked List is empty \n");
	   }
	   while (head_ref != NULL)
	   {
			 printf("%d \n", head_ref -> data);
			 head_ref = head_ref -> next;
	   }
}

int main ()
{
	   struct Node* head = (struct Node*) malloc (sizeof (struct Node));
	   struct Node* first = (struct Node*) malloc (sizeof (struct Node));
	   struct Node* second = (struct Node*) malloc (sizeof (struct Node));

	   head -> data = 10;
	   head -> next = first;
	   head -> tail = second;

	   first -> data = 20;
	   first -> next = second;
	   first -> tail = second;

	   second -> data = 30;
	   second -> next = NULL;
	   second->tail = second;

	   insert (head, 15);

	   push (&head, 5);

	   insert (first, 25);

	   appendt (&head, 40);
	   push (&head, 1);
	   appendt(&head, 45);
	   appendt (&head, 50);

	   printList (head);
	   getCount (head);

	   appendt (&head, 55);
	   printf("%d \n", getCountr (head));

	   appendt (&head, 60);
	   printf("%d \n", getCountr(head));
	   return 0;
}
