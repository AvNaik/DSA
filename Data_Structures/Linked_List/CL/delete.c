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
   Delete an element in a Linked List by a given value.
 */
void delete (struct Node** head_ref, int key)
{
	struct Node* elements = *head_ref;
	struct Node* previous;

	if (elements != NULL && elements -> data == key)
	{
		*head_ref = elements -> next;
		free (elements);
		return;
	}

	while (elements != NULL && elements -> data != key)
	{
		previous = elements;
		elements = elements -> next;
	}

	if (elements == NULL)
		return;

	previous -> next = elements -> next;
	free (elements);
	return;
}

/*
   Delete an element at a particular position from the Linked List.
 */

void deletep (struct Node** head_ref, int position)
{
	struct Node* elements = *head_ref;
	struct Node* previous;

	if (position ==0)
	{
		*head_ref = elements -> next;
		free (elements);
		return;
	}

	for (int i = 1; i < position; i ++)
	{
		previous = elements;
		elements = elements -> next;

		if (elements == NULL)
			return;
	}
	previous -> next = elements -> next;

	free (elements);

	return;
}

/*
   Delete an entire Linked List.
 */

void deletels (struct Node** head_ref)
{
	struct Node* elements = *head_ref;
	struct Node* current;

	while (elements != NULL)
	{
		current = elements;
		elements = elements -> next;
		free (current);
	}

	*head_ref = NULL;

	return;
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

	printf ("---------------------------- \n");
	delete (&head, 50);
	// deletep (&head, 2);
//	deletep (&head, 5);

//	deletels (&head);
	printList (head);

	return 0;
}
