#include "stdio.h"
#include <stdlib.h>
#include "ls.h"

void appendt (struct Node** head_ref, int value)
{
	struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));

	new_element -> data = value;
	new_element -> next = NULL;
	new_element -> tail = new_element;

	if (*head_ref == NULL)
	{
		*head_ref = new_element;
		return;
	}

	struct Node* elements = *head_ref;

	elements = elements -> tail;
	elements -> next = new_element;
	elements = *head_ref;
	elements -> tail = new_element;
	return;
}

void segregate (struct Node** head_ref)
{
	struct Node* elements = *head_ref, *current = NULL;
	struct Node* end = elements -> tail, *new_end = end;

	while ((elements -> data) % 2 == 1 && elements != end)
	{
		current = elements;
		new_end -> next = elements;
		new_end = new_end -> next;
		elements = elements -> next;
		new_end -> next = NULL;
	}

	if ((elements -> data) % 2 == 0)
	{
		*head_ref = elements;
		elements -> tail = new_end;
	}
	while (elements != end)
	{
		if ((elements -> data) % 2 == 0 && elements != end)
		{
			current = elements;
			elements = elements -> next;
			continue;
		}

		current -> next = elements -> next;
		new_end -> next = elements;
		new_end = new_end -> next;
		new_end -> next = NULL;
		elements = *head_ref;
		elements -> tail = new_end;
		elements = current -> next;
	}
	if ((elements -> data) % 2 ==1 && new_end != end)
	{
		current -> next = end -> next;
		end -> next = NULL;
		new_end -> next = end;
	}
}


struct Node* segregate_alternative (struct Node* head_ref)
{
	struct Node* elements = head_ref, *current = NULL;

	struct Node* end = head_ref, *new_end = NULL;

	while (end -> next != NULL)
		end = end -> next;

	new_end = end;

	while ((elements -> data) % 2 == 1 && elements != end)
	{
		current = elements;
		new_end -> next = elements;
		new_end = new_end -> next;
		elements = elements -> next;
		new_end -> next = NULL;
	}

	if ((elements -> data) % 2 == 0)
		current = elements;
	head_ref = elements;

	while (elements != end)
	{
		if ((elements -> data) % 2 == 0 && elements != end)
		{
			current = elements;
			elements = elements -> next;
			continue;
		}
		current -> next = elements -> next;
		new_end -> next = elements;
		new_end = new_end -> next;
		new_end -> next = NULL;
		elements = current -> next;

	}

	if ((elements -> data) %2 == 1 && new_end != end)
	{
		current -> next = end -> next;
		new_end -> next = end;
		new_end -> next -> next  = NULL;
	}

	return head_ref;
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
		printf("%d ", head_ref -> data);
		head_ref = head_ref -> next;
	}
	printf("\n");

}

int main ()
{
	int testcases = 0;
	int no_elements = 0;
	int elements = 0;

	scanf("%d", &testcases);

	while (testcases)
	{
		struct Node* head = NULL;
		scanf("%d", &no_elements);
		while (no_elements)
		{
			scanf("%d", &elements);
			appendt (&head, elements);
			no_elements --;
		}
		head = segregate_alternative (head);
		printList (head);

		testcases --;
	}
	return 0;
}	
