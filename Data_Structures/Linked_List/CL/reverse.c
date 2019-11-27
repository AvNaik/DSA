#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

struct Node* element;

struct Node* appendt (struct Node* head_ref, int value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));

	   new_element -> data = value;
	   new_element -> next = NULL;

	   if (head_ref == NULL)
	   {
			 head_ref = new_element;
			 return head_ref;
	   }

	   struct Node* elements = head_ref;

	   while (elements -> next != NULL)
	   {
			 elements = elements -> next;
	   }

	   elements -> next = new_element;

	   return head_ref;
}
/*
Iterative version to completly reverse a given Linked List
*/
struct Node* reverse (struct Node* head_ref)
{
	   struct Node* previous = NULL, *follow = NULL;
	   if (head_ref == NULL)
	   {
			 printf("Linked List is empty \n");
			 return head_ref;
	   }
	   while (head_ref != NULL)
	   {
			 follow = head_ref -> next;
			 head_ref -> next = previous;
			 previous = head_ref;
			 head_ref = follow;
	   }

	   printf ("Linked List reversed. \n");
	   return previous;
}
/*
Recursive version to completly reverse a given linked list. With the method returning a pointer of the struct Node the function utlizes a global pointer of struct Node
*/
struct Node* reverse_recursive (struct Node* head_ref)
{
	   if (head_ref == NULL)
	   {
			 printf("The Linked List is empty. \n");
			 return head_ref;
	   }

	   if (head_ref -> next  == NULL)
	   {
			 element = head_ref;
			 return head_ref;
	   }
	  
	   struct Node* reverse_elements = reverse_recursive (head_ref -> next);
	   reverse_elements -> next = head_ref;
	   head_ref -> next = NULL;
	   return head_ref;
}
/*
An alternative version to reverse a linked list utilizing a pointer to the head of the linked list. The solutiion is recursive.
*/
void reverse_alternative (struct Node** head_ref)
{
struct Node* first = NULL, *rest = NULL;

if (head_ref == NULL)
{
return;
}

first = *head_ref;
rest = first -> next;

if (rest == NULL)
return;

reverse_alternative (&rest);

first -> next -> next = first;
first -> next = NULL;

*head_ref = rest;
}

/*
Iterative version to reverse a linked list in groups provided as function parameter
*/
struct Node* reverse_group_iterative (struct Node* head_ref, int group)
{
	   struct Node* elements = head_ref, *previous = NULL, *follow = NULL, *end = NULL, *group_head = NULL;
	   int count = 0, check = 0;

	   while (elements != NULL)
	   {
			 count = 0;
			 group_head = elements;
			 previous = NULL;

			 while (elements != NULL && count < group)
			 {
				    follow = elements -> next;
				    elements -> next = previous;
				    previous = elements;
				    elements = follow;
				    count++;
			 }

			 if (check ==0)
			 {
				    check ++;
				    head_ref = previous;
			 }

			 if (end != NULL)
				    end -> next = previous;

			 end = group_head;
	   }

	   printf ("Linked List reversed iteratively in group of %d. \n", group);
	   return head_ref;
}

/*
Recursive version to reverse a linked list in groups provided as function parameter.
*/
struct Node* reverse_group_recursive (struct Node* head_ref, int group)
{
	   struct Node* elements = head_ref, *previous = NULL, *follow = NULL;
	   int count = 0;

	   while (elements != NULL && count < group)
	   {
			 count ++;
			 follow = elements -> next;
			 elements -> next = previous;
			 previous = elements;
			 elements = follow;
	   }

	   if (elements != NULL)
	   {
			 head_ref -> next = reverse_group_recursive (elements, group);
	   }

	   printf ("Linked List reversed recursively in group of %d. \n", group);
	   return previous;
}


void printList (struct Node* head)
{
	   int count = 0;
	   printf("The elements of the Linked List are: \n");
	   if (head == NULL)
	   {
			 printf("The Linked List is empty \n");
			 return;
	   }
	   while (head != NULL)
	   {
			 count++;
			 printf("%d \n", head -> data);
			 head = head -> next;
	   }

	   printf("The number of elements in the Linked List are : %d \n", count);
	   return;
}


int main ()
{
	   struct Node* head = NULL;

	   printList (NULL);
	   head = appendt (head, 10);
	   head = appendt (head, 20);
	   head = appendt (head, 30);
	   head = appendt (head, 40);
	   head = appendt (head, 50);
	   head = appendt (head, 60);
	   head = appendt (head, 70);
	   head = appendt (head, 80);
	   head = appendt (head, 90);
	   head = appendt (head, 100);

	   printList (head);

	   reverse_group_iterative (head, 4);
	   printList (head);

	   return 0;

}
