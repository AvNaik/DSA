#include <stdio.h>
#include<stdlib.h>

struct Queue
{
	   int front;
	   int rear;
	   int size;
	   int* q;
};

struct Queue* create (int capacity)
{
	   struct Queue* new_q = (struct Queue*) malloc (sizeof(struct Queue));
	   if (new_q == NULL)
			 return 0;
	   new_q->size = capacity;
	   new_q->front = 0;
	   new_q->rear = 0;
	   new_q->q = (int*) malloc(sizeof(int) * capacity);
	   return new_q;
}

void enqueue (struct Queue* new_q, int value)
{
	   if (new_q->front == (new_q->rear+1)%new_q->size)
	   {
			 printf("Queue is FULL. Need to Dequeue \n");
	   } else
	   {
			 new_q->rear = (new_q->rear+1)%new_q->size;
			 new_q->q[new_q->rear] = value;
	   }
}

int dequeue (struct Queue* new_q)
{
	   if (new_q->front == new_q->rear)
	   {
			 printf("Queue is empty. Need to Enqueue \n");
			 return 0;
	   }

	   new_q->front = (new_q->front+1)%new_q->size;
	   int x = new_q->q[new_q->front];
	   return x;
}

void printQueue (struct Queue* new_q)
{
	int i = new_q->front+1;
	do
	{
		printf("%d \n", new_q->q[i]);
		i = (i+1)%new_q->size;
	} while (i != (new_q->rear+1)%new_q->size);
}

int main ()
{
	   struct Queue* new_q = NULL;
	   int capacity = 0;
	   printf("Enter size: \n");
	   scanf("%d", &capacity);
	   new_q = create (capacity);
	   int arr [7];
	   printf("Enter values: \n");
	   for (int i = 0; i < 7; i ++)
	   {
			 scanf("%d", (arr+i));
			 enqueue (new_q, arr[i]);
	   }

	   printQueue (new_q);
	   int dqed = dequeue (new_q);
	   printf("The value removed is: %d \n", dqed);
	   printQueue (new_q);
	   enqueue (new_q, 110);
	   //	   enqueue (new_q, 120);
	   printQueue (new_q);
	   return 0;
}
