#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	   void* data;
	   struct Node* next;
};

int isEmpty(struct Node* head_ref)
{
	   if (head_ref == NULL)
			 return 1;
	   return -1;
}
void push (struct Node** head_ref, void* value)
{
	   struct Node* new_element = (struct Node*) malloc(sizeof(struct Node));
	   if (new_element == NULL)
	   {
			 printf("Stack Overflow. \n");
			 return;
	   }
	   new_element->next = NULL;
	   new_element->data = (char*) malloc (sizeof(value));
	   *(char*) new_element->data = *(char*) value;
	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 return;
	   }
	   new_element->next = *head_ref;
	   *head_ref = new_element;
	   return;
}

void pop(struct Node** head_ref)
{
	   if (isEmpty(*head_ref) == 1)
	   {
			 printf("Stack is empty. \n");
			 return;
	   }
	   struct Node* element = *head_ref;
	   *head_ref = element->next;
	   free(element);
	   return;
}

int p_check (char* s)
{
	   struct Node* stack = NULL;
	   for (int i = 0; s[i] != '\0'; i++)
	   {
			 if (s[i] == '(')
			 {
				    push (&stack, &s[i]);
			 } else if (s[i] == ')')
			 {
				    if (isEmpty (stack) == 1)
				    {
						  return -1;
				    }
				    pop (&stack);
			 }
	   }

	   if (isEmpty (stack) == 1)
	   {
			 return 1;
	   } else 
	   {
			 return -1;
	   }

}

int main ()
{
	   int len = 0;
	   printf("Enter Length: \t");
	   scanf("%d", &len);
	   char s[2];
	   fgets (s, 2, stdin);

	   char str [len];
	   printf("Enter expression: \n");
	   fgets(str, len, stdin);
	   printf("The entered string is: %s", str);

	   int checked = p_check (str);
	   checked == 1 ? printf("Experession is perfect. \n"): printf("Expression is not prefect \n");

	   return 0;

}
