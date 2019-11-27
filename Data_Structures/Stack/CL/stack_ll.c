#include <stdio.h>
#include <stdlib.h>

struct Node
{
	void* data;
	struct Node* next;
};

int isEmpty (struct Node* head_ref)
{
	if (head_ref == NULL)
	{
		return 1;
	} else
	{
		return -1;
	}
}

void post (struct Node** head_ref, void* value)
{
	struct Node* new_element = (struct Node*) malloc (sizeof (struct Node));
	if (new_element == NULL)
	{
		printf("Stack Overflow \n");
		return;
	}
	new_element->data = (int*) malloc (sizeof (value));

	new_element->next = NULL;
	*(int*)new_element->data = *(int*) value;

	if (*head_ref == NULL)
	{
		*head_ref = new_element;
		return;
	}
	struct Node* elemnts =

	new_element->next = *head_ref;
	*head_ref = new_element;
	return;
}

int pop (struct Node** head_ref)
{
	if (isEmpty (*head_ref) == 1)
	{
		printf("Stack is empty. \n");
		return 0;
	}

	struct Node* elements = *head_ref;
	int x = 0;
	x = *(int*) elements->data;
	*head_ref = elements->next;
	free (elements);
	return x;
}

int peek (struct Node* head_ref, int index)
{
	int count = 0;
	if (isEmpty(head_ref) == 1)
	 {
	           printf("Stack is empty. \n");
			           return 0;
					      }
	while (head_ref != NULL && count < index)
	{
		count ++;
		head_ref = head_ref->next;
	}

	int x = *(int*)head_ref->data;
	return x;
}

void printList (struct Node* head_ref)
{
	int count = 0;
	while (head_ref != NULL)
	{
		printf("%d \n", *(int*)head_ref->data);
		head_ref = head_ref->next;
		count++;
	}

	printf("The length of the linked list is: %d \n", count);
}

int main ()
{
	struct Node* head = NULL;
	int a = 10;
	post(&head, &a);
	a = 20;
	post (&head, &a);
	a = 30;
	post (&head, &a);
	a = 40;
	post (&head, &a);
	a = 50;
	     post (&head, &a);
		a = 60;
		     post (&head, &a);
			a = 70;
			     post (&head, &a);
				a = 80;
				     post (&head, &a);

					int popped = pop (&head);
	printList (head);

	printf("The element popped from the stack is: %d \n", popped);

	int peeked = peek(head, 3);
	printf("The element at the index is: %d \n", peeked);

	return 0;

}

