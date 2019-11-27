#include "stdio.h"
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

void append_head (struct Node** head_ref, void* value)
{
	   struct Node* new_element = (struct Node*)malloc(sizeof(struct Node));
	   new_element->data = malloc(sizeof(value));
	   new_element->next = NULL;
	   *(int*)new_element->data = *(int*) value;
	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 return;
	   }

	   new_element->next = *head_ref;
	   *head_ref = new_element;
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

int getCount_recursive (struct Node* head)
{
	int count = 0;
	if (head != NULL)
	{
		return 1+getCount_recursive (head->next);
	}
	return 0;
}


int main ()
{
	   struct Node* head = (struct Node*) malloc (sizeof (struct Node));
	   head = NULL;

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
			 appendt(&head, (array+ i));
	   }

	   printList (head);

	   int count = getCount_recursive (head);
	   printf("%d \n", count);
	   //	   printf("------------------------------------- \n");
	   //	   append_head (&head, &array [3]);

	   //	   printList (head);

	   return 0;
}

