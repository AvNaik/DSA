#include <stdio.h>
#include <stdlib.h>

struct Node
{
	   void* data;
	   struct Node* next;
	   struct Node* tail;
};

void enqueue (struct Node** max_p, struct Node** mid_p, struct Node** low_p, void* value, int p)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   if (new_element == NULL)
			 return;
	   new_element->next = NULL;
	   new_element->data = malloc (sizeof(value));
	   *(int*)new_element->data = *(int*)value;
	   new_element->tail = new_element;

	   if (p == 1)
	   {
			 if (*max_p == NULL)
			 {
				    *max_p = new_element;
				    return;
			 }
			 struct Node* elements = *max_p;
			 elements = elements->tail;
			 elements->next = new_element;
			 elements->tail = new_element;
			 elements = *max_p;
			 elements->tail = new_element;
	   } else if (p == 2)
	   {
			 if (*mid_p == NULL)
			 {
				    *mid_p = new_element;
				    return;
			 }
			 struct Node* elements = *mid_p;
			 elements = elements->tail;
			 elements->next = new_element;
			 elements->tail = new_element;
			 elements = *mid_p;
			 elements->tail = new_element;

	   } else if (p == 3)
	   {
			 if (*low_p == NULL)
			 {
				    *low_p = new_element;
				    return;
			 }
			 struct Node* elements = *low_p;
			 elements = elements->tail;
			 elements->next = new_element;
			 elements->tail = new_element;
			 elements = *low_p;
			 elements->tail = new_element;
	   }

}

int dequeue (struct Node** max_p, struct Node** mid_p, struct Node** low_p)
{
	   struct Node* element = NULL;
	   int x = 0;
	   if (*max_p != NULL)
	   {
			 element = *max_p;
			 *max_p = element->next;
			 x = *(int*) element->data;
			 free(element);
			 return x;
	   } else if (mid_p != NULL)
	   {
			 element = *mid_p;
			 *mid_p = element->next;
			 x = *(int*) element->data;
			 free(element);
			 return x;
	   } else if (low_p != NULL)
	   {
			 element = *low_p;
			 *low_p = element->next;
			 x = *(int*) element->data;
			 free(element);
			 return x;

	   }

}

void printQueue (struct Node* max_p, struct Node* mid_p, struct Node* low_p)
{
	   while (max_p != NULL)
	   {
			 printf("%d \t", *(int*)max_p->data);
			 max_p = max_p->next;
	   }
	   printf("\n-------------------------\n");
	   while (mid_p != NULL)
	   {
			 printf("%d \t", *(int*)mid_p->data);
			 mid_p = mid_p->next;
	   }
	   printf("\n-------------------------\n");
	   while (low_p != NULL)
	   {
			 printf("%d \t", *(int*)low_p->data);
			 low_p = low_p->next;
	   }

}

int main ()
{
	   struct Node* max_p = NULL;
	   struct Node* mid_p = NULL;
	   struct Node* low_p = NULL;

	   int a;
	   printf("Enter length of queue: \n");
	   scanf("%d", &a);
	   int arr[a];
	   int p[a];
	   printf("Enter elements of Queue followed by priority \n");
	   for (int i = 0; i < a; i ++)
	   {
			 scanf("%d", &arr[i]);
	   }

	   for (int i = 0; i < a; i ++)
	   {
			 scanf("%d", &p[i]);
	   }

	   for (int i = 0; i < a; i ++)
	   {
			 enqueue (&max_p, &mid_p, &low_p, &arr[i], p[i]);
	   }


	   //	   enqueue (&max_p, &mid_p, &low_p, &arr[i], p[i]);

	   printQueue(max_p, mid_p, low_p);
	   dequeue (&max_p, &mid_p, &low_p);
	   printQueue (max_p, mid_p, low_p);
}
