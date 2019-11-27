#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

void appendt (struct Node** head_ref, double* value)
{
	struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	new_element->data = malloc(sizeof(value));
	new_element->next = NULL;
	*(double*)new_element->data = *value;
	if (*head_ref == NULL)
	{	*head_ref = new_element;
		return;
	}
	struct Node* elements = *head_ref;
	while(elements->next != NULL)
	{
		elements = elements->next;
	}

	elements->next = new_element;
	return;
}

void reverse (struct Node** head_ref)
{
	   struct Node* elements = *head_ref;
	   if(*head_ref == NULL)
			 return;
	   if(elements->next == NULL)
			 return;
	   struct Node* previous = NULL, *follow = NULL;

	   while(elements != NULL)
	   {
			 follow = elements->next;
			 elements->next = previous;
			 previous = elements;
			 elements = follow;
	   }
	   *head_ref = previous;
	   return;
}

void reverse_recursive (struct Node** head_ref)
{
	   if (*head_ref == NULL)
			 return;

	   struct Node* elements = *head_ref;
	   struct Node* follow = elements->next;

	   if (follow == NULL)
	   {
			 *head_ref = elements;
			 return;
	   }
	   reverse_recursive (&follow);
	   elements-> next->next = elements;
	   elements-> next = NULL;
	   *head_ref = follow;
	   return;
}

struct Node* reverse_ll (struct Node* head_ref)
{
	   if (head_ref == NULL)
	   {
			 return 0;
	   } else if (head_ref->next == NULL)
	   {
			 return head_ref;
	   }
	   struct Node* previous = NULL, *follow = NULL;
	   while (head_ref != NULL)
	   {
			 follow = head_ref -> next;
			 head_ref->next = previous;
			 previous = head_ref;
			 head_ref = follow;
	   }
	   return previous;
}

struct Node* reverse_k (struct Node* head_ref, int k)
{
	if (head_ref == NULL)
		return 0;
	if (head_ref->next == NULL)
		return head_ref;
	
	int count = 0;
	struct Node* elements = head_ref;
	while(elements != NULL)
	{
		count++;
		elements = elements->next;
	}

	if (count < k)
	{
		k = k % count;
		if (k == 0)
			return head_ref;
	}

	int test = 0;
	elements = head_ref;
	struct Node* previous = NULL, *follow = NULL;
	struct Node* tail = elements;

	while(elements!= NULL && test < k)
	{
		follow = elements->next;
		elements->next = previous;
		previous = elements;
		elements = follow;
		test++;
	}

	tail->next = follow;
	return previous;
}

void reverse_groups (struct Node** head_ref, int k)
{
	struct Node* elements = *head_ref;
	if (*head_ref == NULL)
		return;
	if (elements->next == NULL)
		return;
	int count = 0;
	while (elements != NULL)
	{
		count++;
		elements = elements->next;
	}
	printf("%d \n", count);

	if (k > count)
	{
		k = k% count;
		if (k == 0)
			return;
	}

	struct Node* previous = NULL, *follow = NULL, *tail = NULL, *n_head = NULL;
	count = 0;
	int test = 0;
	elements = *head_ref;
	while(elements != NULL)
	{
		count = 0;
		n_head = elements;
		previous = NULL;
		while (elements != NULL && count < k)
		{
			follow = elements->next;
			elements->next = previous;
			previous = elements;
			elements = follow;
			count++;
		}
		if (test == 0)
		{
			++test;
			*head_ref = previous;
		}
		if(tail != NULL)
			tail->next = previous;

		tail = n_head;
	}
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
	   printf("-------------------------------\n");

	   reverse_groups(&head, 3);
	   printList (head);
	   return 0;
}
