#include "stdio.h"
#include <stdlib.h>
#include "ls.h"

/*
   Functiton to push an element into a linked list in position of the head of the Linnked list. The existing head will be replaced by the element which is being pushed in as a parameter through the funnction.
   The DOuble pointer to the head of the linked list is to enable changing the head of the linked list without having to return any value from the function.
 */

void push (struct Node** head_ref, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof (struct Node));

	   new_element -> data = value;
	   new_element -> next = *head_ref;
	   *head_ref = new_element;

}

/*
   Function to insert an element into the linked list after the node which has been passed in a parameter.
 */

void insert (struct Node* obj, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   if (obj == NULL)
	   {
			 printf("Invalid Opeartion \n");
			 return;
	   }
	   new_element -> data = value;
	   new_element -> next = obj -> next;
	   obj -> next = new_element;
}

/*
   Function to append an elemnt at the atil of the linked list through a double pointer i.e.e reference to head of the linked list being used only. The complexity of the function if O(n)
 */
void appendh (struct Node** head_ref, int value)
{
	   struct Node* new_element = (struct Node*)malloc (sizeof(struct Node));
	   struct Node* elements = *head_ref;

	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
	   }

	   new_element -> data = value;
	   new_element -> next = NULL;

	   while (elements -> next != NULL)
	   {
			 elements = elements -> next;
	   }

	   elements -> next = new_element;
	   return;
}

/*
   Functions to get count of elements in the linked list in reccursive and iterative fashion
 */
int count (struct Node* head_ref)
{
	   struct Node* elements = head_ref;
	   int count = 0;

	   while (elements != NULL)
	   {
			 count++;
			 elements = elements -> next;
	   }
	   return count;
}

int getCountr (struct Node* head_ref)
{
	   int count = 0;

	   if (head_ref == NULL)
			 return 0;

	   return 1+getCountr (head_ref -> next);
}

/*
   Print the entire linked list.
 */
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

	   first -> data = 20;
	   first -> next = second;

	   second -> data = 30;
	   second -> next = NULL;

	   insert (head, 15);

	   push (&head, 5);

	   insert (first, 25);
	   appendh (&head, 35);

	   appendh (&head, 40);

	   push (&head, 5);
	   printList (head);

	   printf("The number of elements in the Linked List are: %d \n", count (head));

	   appendh (&head, 45);

	   printf ("%d \n", count (head));

	   appendh (&head, 50);
	   appendh (&head, 55);

	   printf ("The number of elements in the Linked List are: %d \n", getCountr(head));

	   return 0;
}
