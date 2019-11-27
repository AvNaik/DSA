#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

void appendt (struct Node** head_ref, void* value)
{
	   struct Node* new_element = (struct Node*) malloc(sizeof(struct Node));

	   new_element->data = malloc(sizeof(value));
	   *(double*) new_element->data = *(double*) value;
	   new_element->next = NULL;

	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 return;
	   }
	   struct Node* elements = *head_ref;
	   while (elements->next != NULL)
			 elements = elements->next;

	   elements->next = new_element;
	   return;

}

void printList(struct Node* head)

{
	   int count = 0;
	   if (head == NULL)
			 printf("The linked list is empty \n");

	   while (head!= NULL)
	   {
			 count++;
			 printf("%lf \n", *(double*)head->data);
			 head = head -> next;
	   }
	   printf("The total number of elements in the Linked List are: %d \n", count);
}

/*
   2 pointer implementation to get the middle element of a linked list
 */
int getmiddle (struct Node* head)
{
	double middle = 0;
	if (head == NULL)
	{
		printf("The List is empty \n");
		return 0;
	} else if (head->next == NULL)
	{
		middle = *(double*)head->data;
		return middle;
	}
	struct Node* fast = head, *slow = head;

	while (fast!= NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	middle = *(double*)slow->data;
	return middle;
}

int main ()
{
	   struct Node* head = NULL;

	   int number;
	   printf("Input a number: \n");
	   scanf("%d", &number);

	   double array [number];
	   printf("Input array to be inserted into Linked List: \n");

	   for (int i = 0; i < number; i ++)
	   {
			 scanf("%lf", (array +i));
	   }

	   for (int i = 0; i < number; i ++)
	   {
			 appendt(&head, &array[i]);
	   }

	   printList(head);

	   int middle = getmiddle(head);

	   printf("The middle element is: %d \n", middle);

	   return 0;
}

