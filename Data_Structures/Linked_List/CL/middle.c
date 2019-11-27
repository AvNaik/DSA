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
/*
   Function to calculate the middle element of a linked list
 */
int printMiddle (struct Node* head_ref)
{

	   struct Node* slow_ptr = head_ref;
	   struct Node* fast_ptr = head_ref;

	   while (fast_ptr != NULL && fast_ptr -> next != NULL)
	   {
			 fast_ptr = fast_ptr -> next -> next;
			 slow_ptr = slow_ptr -> next;
	   }

	   return slow_ptr -> data;

}

void printMiddlea (struct Node* head_ref)
{
	   struct Node* element = head_ref;
	   int counter = 0;
	   while (head_ref != NULL)
	   {
			 if (counter % 2 == 1)
			 {
				    element = element -> next;
			 }
			 counter ++;
			 head_ref = head_ref -> next;
	   }

	   printf ("The middle: %d \n", element ->data);
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

	   appendt(&head , 60);

	   printList (head);

	   printf("The middle of the Linked List is: %d \n", printMiddle (head));

	   printMiddle(head);
	   return 0;
}
