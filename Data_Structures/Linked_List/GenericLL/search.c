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

int search (struct Node* head, double key)
{
	   struct Node* elements = head;
	   if (head == NULL)
	   {
			 printf("LinkedList is empty \n");
			 return -1;
	   }

	   while (elements != NULL)
	   {
			 if (key == (*(double*)elements->data))
			 {
				    return 1;
			 }
			 elements = elements->next;
	   }

	   return -1;
}

int getNthelement (struct Node* head, int n)
{
	   double nth;
	   struct Node* elements = head;
	   int length = 0;
	   while (elements != NULL)
	   {
			 elements = elements->next;
			 length++;
	   }
	   if (n > length)
	   {
			 n = n % length;
	   }
	   elements = head;
	   int count = 1;

	   while (count < n)
	   {
			 count++;
			 elements = elements->next;
	   }
	   nth = *(double*)elements->data;
	   return nth;
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
			 appendt(&head, (array+ i));
	   }

	   printList (head);
	   printf("Enter element to be searched: \n");
	   double search_element;
	   scanf("%lf", &search_element);

	   int result = search (head, search_element);
	   (result == 1) ? printf("Element present \n") : printf("Element not present \n");

	   printf("Number of element to be retrieved: \n");
	   int element = 0;
	   scanf("%d", &element);
	   result = getNthelement (head, element);
	   printf("%d \n", result);

	   return 0;
}
