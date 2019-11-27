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

void rotate (struct Node** head_ref, int n)
{
	   struct Node* elements = *head_ref;
	   if (*head_ref == NULL)
	   {
			 return;
	   } else if (elements->next == NULL)
	   {
			 return;
	   }
	   int count = 0;
	   while (count < n && elements != NULL)
	   {
			 count = count +1;
			 elements= elements->next;
	   }
	   printf("count: %d \n", count);
	   if (count < n)
	   {
			 n = n % count;
			 elements = *head_ref;
			 printf("n: %d\n", n);
			 count = 1;
			 while (count < n && elements != NULL)
			 {
				    count++;
				    elements = elements->next;
			 }
	   }

	   struct Node* new_head = elements->next;
	   struct Node* new_tail = elements;
	   while (elements->next != NULL)
			 elements = elements->next;
	   elements->next = *head_ref;
	   *head_ref = new_head;
	   new_tail->next = NULL;

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

	   rotate (&head, 13);

	   printList (head);

	   return 0;
}


