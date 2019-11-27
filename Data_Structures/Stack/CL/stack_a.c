#include <stdio.h>
#include <stdlib.h>

/*
   Stack implemented using array which is created dynamically.
   Functions to be implemented:
Create: Create the stack.
Push - add an element
Pop - remove an element
Peek - return element at given index
isFull - see if stacck is full
isEmpty - see if stack is empty
stackTop - return element at top of stack
Display: display the contents of the stack
 */

struct stack
{
	   int top;
	   int size;
	   int* arr;
};

struct stack* create (int capacity)
{
	   struct stack* new_stack = (struct stack*) malloc (sizeof(struct stack));
	   new_stack->top = -1;
	   new_stack->size = capacity;
	   new_stack->arr = (int*) malloc (sizeof(int) * capacity);
	   printf("Stack Created successfully \n");
	   return new_stack;
}

int isFull (struct stack* new_stack)
{
	   if (new_stack->size-1 == new_stack->top)
	   {
			 return 1;
	   } else
	   {
			 return -1;
	   }
}

int isEmpty (struct stack* new_stack)
{
	   if (new_stack->top == -1)
	   {
			 return 1;
	   }
	   else
	   {
			 return -1;
	   }
}


void display (struct stack* new_stack)
{
	   if (isEmpty(new_stack) == 1)
	   {
			 printf("Stack is empty \n");
			 return;
	   } else
	   {
			 for (int i = new_stack->top; i >=0; i --)
			 {
				    printf("%d \n", new_stack->arr[i]);
			 }
	   }
}

void push (struct stack** s, int value)
{
	   if (isFull(*s) == 1)
	   {
			 printf("Stack Overflow. \n");
			 return;
	   } else
	   {
			 struct stack* new_element = *s;
			 new_element->top++;
			 new_element->arr[new_element->top] = value;
	   }
}

int pop (struct stack** s)
{
	   if (isEmpty(*s) == 1)
	   {
			 printf("The stack is empty");
			 return -1;
	   } else
	   {
			 int x = 0;
			 struct stack* element = *s;
			 x = element->arr[element->top--];
			 return x;
	   }
}

int peek (struct stack* s, int index)
{
	   if (isEmpty(s) == 1)
	   {
			 printf("The stack is empty");
			 return 0;
	   } else
	   {
			 int x  = 0;
			 x = s->arr[s->top-index+1];
			 return x;
	   }
}

int stackTop (struct stack* s)
{
	   if (isEmpty(s) == 1)
	   {
			 printf("The stack is empty");
			 return 0;
	   } else
	   {
			 int x = 0;
			 x = s->arr[s->top];
			 return x;
	   }
}

int main ()
{
	   struct stack* new_stack = NULL;
	   int a = 0;
	   printf("size of stack: \n");
	   scanf("%d", &a);
	   new_stack = create (a);

	   push (&new_stack, 10);
	   push (&new_stack, 20);
	   push (&new_stack, 30);
	   push (&new_stack, 40);
	   push (&new_stack, 50);
	   push (&new_stack, 60);
	   push (&new_stack, 70);

	   display (new_stack);
	   int top = stackTop(new_stack);
	   printf("The top of the stack is: %d \n", top);

	   int removed = pop(&new_stack);
	   printf("The value removed from stack is: %d \n", removed);

	   int peeked = peek (new_stack, 4);
	   printf("The value peeked is: %d \n", peeked);

	   top = stackTop(new_stack);
	   printf("The top of the stack is: %d \n", top);


	   return 0;
}

