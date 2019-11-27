#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	   int size;
	   int front;
	   int rear;
	   int* q;
};

struct Queue* create (int capacity)
{
	   struct Queue* new_q = (struct Queue*) malloc (sizeof (struct Queue));
	   new_q->size = capacity;
	   new_q->front = -1;
	   new_q->rear = -1;
	   new_q->q = (int*)malloc (sizeof (int) * capacity);
	   printf("Queue Created Successfully \n");
	   return new_q;
}

void enqueue (struct Queue* new_q, int value)
{
	   if (new_q->rear == new_q->size-1)
	   {
			 printf("Queue is Full \n");
			 return;
	   }

	   new_q->rear++;
	   new_q->q[new_q->rear] = value;
}

int dequeue (struct Queue* new_q)
{
	   int x =0;
	   if (new_q->front == new_q->rear)
	   {
			 printf("Queue is already emtpy \n");
				    return 0;
	   }

	   new_q->front++;
	   x = new_q->q[new_q->front];
	   return x;
}

void printQueue (struct Queue* new_q)
{
	   for (int i =new_q->front+1; i <= new_q->rear; i ++)
	   {
			 printf("%d \n", new_q->q[i]);
	   }
}

int main ()
{
	   struct Queue* new_q = NULL;
	   int a = 0;
	   printf("Enter Size: \n");
	   scanf("%d", &a);
	   new_q = create (a);
	   int arr[10];
	   printf("Enter values: \n");
	   for (int i = 0; i < 10; i ++)
	   {
			 scanf("%d", &arr[i]);
			 enqueue (new_q, arr[i]);
	   }

	   printQueue(new_q);

	   int dqed = dequeue (new_q);
	   printf("The element removed is: %d \n", dqed);

	   printQueue (new_q);
	   return 0;

}	
