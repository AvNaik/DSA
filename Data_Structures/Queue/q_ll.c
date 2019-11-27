#include <stdio.h>
#include <stdlib.h>

struct Node
{
	   void* data;
	   struct Node* next;
	   struct Node* tail;
};

void enqueue (struct Node** head_ref, void* value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   if (new_element == NULL)
			 return;

	   new_element->data = malloc (sizeof (value));
	   *(int*)new_element->data = *(int*) value;

	   new_element->next = NULL;
	   new_element->tail = new_element;
	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 return;
	   }
	   struct Node* elements = *head_ref;
	   elements = elements->tail;
	   elements->next = new_element;
	   elements->tail = new_element;
	   elements = *head_ref;
	   elements->tail = new_element;
	   return;
}

int dequeue (struct Node** head_ref)
{
	   if (*head_ref == NULL)
	   {
			 printf("Queue is Empty \n");
			 return 0;
	   }

	   struct Node* elements = *head_ref;
	   *head_ref = elements->next;
	   int x = *(int*)elements->data;
	   free (elements);
	   return x;
}

void printQueue (struct Node* head_ref)
{
	   while (head_ref != NULL)
	   {
			 printf("%d \n", *(int*)head_ref->data);
			 head_ref = head_ref->next;
	   }
}


int main ()
{
	   struct Node* head = NULL;
	   printf("Enter size of array: \n");
	   int number = 0;
	   scanf("%d", &number);
	   int arr[number];
	   printf("Enter input for queue: \n");
	   for (int i = 0; i < number; i ++)
	   {
			 scanf("%d", &arr[i]);
			 enqueue (&head, &arr[i]);
	   }

	   printQueue(head);
	   int dqed1 = dequeue(&head);
	   int dqed2 = dequeue(&head);
	   int dqed3 = dequeue (&head);
	   printf("The value deleted are: %d, %d %d\n", dqed1, dqed2, dqed3);
	   printf("---------------\n");
	   printQueue(head);

}
