#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ls.h"

void appendt (struct Node** head_ref, void* value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   new_element->data = malloc(sizeof(value));

	   *(double*)new_element->data = *(double*)value;
	   new_element->next = NULL;
	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 return;
	   }

	   struct Node* elements = *head_ref;
	   while(elements->next != NULL)
			 elements = elements->next;

	   elements->next = new_element;
	   return;
}

double int_representation (struct Node* head_ref)
{
	   struct Node* elements = head_ref;
	   if(head_ref == NULL)
			 return 0;
	   int i = 0;
	   double number = 0;
	   while(elements != NULL)
	   {
			 number += (*(double*)elements->data) * (pow(10,i));
			 i++;
			 elements = elements->next;
	   }
	   return number;
}

void printList (struct Node* head_ref)
{
	   int count = 0;
	   while (head_ref !=NULL)
	   {
			 count++;
			 printf("%lf \n", *(double*)(head_ref->data));
			 head_ref = head_ref->next;
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
	   double value = int_representation (head);
	   printf("%lf \n", value);
	   return 0;
}
