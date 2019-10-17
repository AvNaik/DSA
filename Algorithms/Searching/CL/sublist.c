#include <stdio.h>
#include <stdlib.h>

struct Node
{
	   int data;
	   struct Node* next;
};

struct Node* append (struct Node* head_ref, int value)
{
	   struct Node* new_element = (struct Node*) malloc(sizeof (struct Node));

	   new_element -> data = value;
	   new_element -> next = NULL;
	   if (head_ref == NULL)
	   {
			 head_ref = new_element;
			 return head_ref;
	   }

	   struct Node* elements = head_ref;

	   while (elements -> next != NULL)
			 elements = elements -> next;

	   elements -> next = new_element;

	   return head_ref;
}


int subList_Search (struct Node* first, struct Node* second)
{
	   struct Node* ptr1 = first, *ptr2 = second;

	   if(first == NULL && second == NULL)
			 return 1;

	   if (first == NULL && second != NULL)
			 return -1;

	   if (first != NULL && second == NULL)
			 return -1;

	   while (first != NULL)
	   {
			 ptr1 = first;

			 while (ptr2 != NULL)
			 {
				    if (first == NULL)
						  return -1;
				    else if (ptr1 -> data == ptr2 -> data)
				    {
						  ptr1 = ptr1 -> next;
						  ptr2 = ptr2 -> next;
				    } else
						  break;
			 }

			 if (ptr2 == NULL)
				    return 1;

			 ptr2 = second;

			 first = first-> next;
	   }

	   return -1;
}


void printList (struct Node* head_ref)
{
	   int count = 0;
	   printf("Elements of the Linked List are: \n");

	   while (head_ref != NULL)
	   {
			 count++;
			 printf("%d \n", head_ref -> data);
			 head_ref = head_ref -> next;
	   }

	   printf("The number of elements in the Linked List are: %d \n", count);
}


int main ()
{
	   int result = 0;
	   struct Node* first = NULL;
	   struct Node* second = NULL;

	   first = append (first, 10);
	   first = append (first, 20);
	   first = append (first, 30);
	   first = append (first, 40);
	   first = append (first, 50);
	   first = append (first, 60);
	   first = append (first, 70);
	   first = append (first, 80);
	   first = append (first, 90);
	   first = append (first, 100);

	   second = append (second, 10);
	   second = append (second, 20);
	   second = append (second, 30);
	   second = append (second, 40);

	   printList (first);
	   printf("\n");
	   printList (second);

	   result = subList_Search (first, second);
	   (result == 1) ? printf("Second Sublist exits in first Sublist \n") : printf("Second Sublist does not exist in first Sublist \n");

	   return 0;
}
