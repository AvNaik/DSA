#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	   void* data;
	   struct Node* next;
};

int isEmpty(struct Node* s)
{
	   if (s == NULL)
	   {
			 return 1;
	   }
	   return -1;
}

int precedence (char s)
{
	   switch (s)
	   {
			 case '+':
			 case '-':
				    return 1;
			 case '*':
			 case '/':
				    return 2;
			 case '(':
			 case ')':
				    return 3;
	   }
	   return 0;
}

int isOperand (char s)
{
	   if ((s >= '0' && s<= '9') || (s >= 'A' && s <= 'Z'))
			 return 1;
	   return -1;
}

void push (struct Node** head_ref, char* value)
{
	   struct Node* new_element = (struct Node*) malloc (sizeof(struct Node));
	   if (new_element == NULL)
	   {
			 printf ("Stack Overflow. \n");
			 return;
	   }
	   new_element->next = NULL;
	   new_element->data = malloc(sizeof(value));
	   *(char*)new_element->data = *(char*) value;
	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 return;
	   }
	   new_element->next = *head_ref;
	   *head_ref = new_element;
	   return;
}

char pop (struct Node** head_ref)
{
	   if (isEmpty(*head_ref) == 1)
			 return 0;
	   struct Node* element = *head_ref;
	   char x = *(char*)element->data;
	   *head_ref = element->next;
	   free (element);	
	   return x;
}

char stackTop (struct Node* head_ref)
{
	   return *(char*) head_ref->data;
}

void convert (char* str, char* postfix)
{
	   struct Node* stack = NULL;
	   int j = 0;
	   int i = 0;
	   char x;
	   while (str[i] != '\0')
	   {
			 if (isOperand(str[i]) == 1)
			 {
				    postfix[j++] = str[i++];
			 } else
			 {
				    if (isEmpty(stack) == 1)
				    {
						  push(&stack, &str[i++]);
				    } else
				    {
						  if (precedence (stackTop(stack)) < precedence(str[i]))
						  {
								push (&stack, &str[i++]);
						  } else
						  {
								postfix[j++] = pop (&stack);
						  }
				    }
			 }
	   }
	   while (isEmpty(stack) == -1)
	   {
			 postfix[j++] = pop(&stack);
	   }
	   return;
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
	   int len = 0;
	   printf("Enter Length: \t");
	   scanf("%d", &len);
	   char s[2];
	   fgets (s, 2, stdin);

	   char str [len];
	   printf("Enter expression: \n");
	   fgets(str, len, stdin);
	   //	   printf("The entered expression is: %s \n", str);
	   char postfix[len];
	   convert (str, postfix);
	   printf("%s", postfix);

	   return 0;

}
