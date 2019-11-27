#include <stdio.h>
#include <stdlib.h>

struct Node
{
	void* data;
	struct Node* next;
};

void appendt (struct Node** head_ref, int value)
{
	struct Node* new_element = (struct Node*)malloc (sizeof(struct Node));
	if (new_element == NULL)
		return;
	new_element->next = NULL;
	new_element->data = malloc (sizeof (value));
	*(int*)new_element->data = value;
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

int search (struct Node* head1, struct Node* head2)
{
	struct Node* ptr1 = head1, *ptr2 = head2;
	if (head1 == NULL || head2 == NULL)
	{
		return 0;
	} else if (head1 != NULL && head2 == NULL)
	{
		return 0;
	} else if (head1 == NULL && head2 != NULL)
	{
		return 0;
	}
	while (head1 != NULL)
	{
		ptr1 = head1;
		while (ptr2 != NULL)
		{
			if(ptr1 == NULL)
			{
				return 0;
			} else if (*(int*)ptr1->data == *(int*)ptr2->data)
			{
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			} else
			{
				break;
			}
		}

		if (ptr2 == NULL)
			return 1;

		ptr2 = head2;

		head1 = head1->next;
	}
return 0;	
}

void printList (struct Node* head)
{
	while (head != NULL)
	{
		printf("%d \n", *(int*) head->data);
		head = head->next;
	}
}

int main ()
{
	struct Node* head_1 = NULL;
	appendt (&head_1, 10);
	appendt (&head_1, 20);
	appendt (&head_1, 30);
	appendt (&head_1, 40);
	appendt (&head_1, 50);
	appendt (&head_1, 60);
	appendt (&head_1, 70);
	appendt (&head_1, 80);
	appendt (&head_1, 90);
	appendt (&head_1, 100);
	printList (head_1);

	struct Node* head_2 = NULL;
	appendt (&head_2, 30);
	appendt (&head_2, 40);
	appendt (&head_2, 15);
	appendt (&head_2, 60);
	printList (head_2);

	search (head_1, head_2) ? printf("List is found \n") : printf("List not found \n");
	return 0;
}
