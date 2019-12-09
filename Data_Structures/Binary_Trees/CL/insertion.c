#include <stdio.h>
#include <stdlib.h>

struct Node
{
	   int data;
	   struct Node* left;
	   struct Node* right;
};

struct Queue
{
	   struct Node* node;
	   struct Queue* next;
};
struct Queue* tail = NULL;

struct stack 
{
	   struct Node* data;
	   struct stack* next;
};

int isEmpty (struct Queue* q)
{
	   if (q == NULL)
			 return 1;
	   return -1;
}

int is_s_empty (struct stack* s)
{
	   if (s == NULL)
			 return 1;
	   return -1;
}

void push (struct stack** head_ref, struct Node* value)
{
	   struct stack* new_element = (struct stack*) malloc (sizeof (struct stack));
	   new_element->next = NULL;
	   new_element->data = malloc (sizeof (value));
	   new_element->data =  value;
	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 return;
	   }
	   new_element->next = *head_ref;
	   *head_ref = new_element;
	   return;
}

struct Node* pop (struct stack** head_ref)
{
	   if (is_s_empty (*head_ref) == 1)
	   {
			 printf("stack is empty. \n");
			 return NULL;
	   }
	   struct stack* element = *head_ref;
	   struct Node* temp = element->data;
	   *head_ref = element ->next;
	   free (element);
	   return temp;
}

void enqueue (struct Queue** q, struct Node* value)
{
	   struct Queue* new_element = (struct Queue*) malloc (sizeof(struct Queue));
	   new_element->next = NULL;
	   new_element->node = value;
	   if (*q == NULL)
	   {
			 *q = new_element;
			 tail = *q;
			 return;
	   }
	   struct Queue* element = tail;
	   element->next = new_element;
	   tail = new_element;
	   return;
}

struct Node*  dequeue (struct Queue** q)
{
	   if (isEmpty(*q) == 1)
	   {
			 printf("Queue is Empty \n");
			 return NULL;
	   }
	   struct Queue* element = *q;
	   struct Node* temp = element->node;
	   *q = element->next;
	   free (element);
	   return temp;
}

void create (struct Node** root)
{
	   struct Node* temp = NULL, *d_temp = NULL;
	   struct Queue* q = NULL;
	   int x = 0;
	   int y = 0;
	   printf("Enter value of root. \n");
	   scanf("%d", &x);
	   struct Node* new_element = (struct Node*) malloc (sizeof (struct Node));
	   new_element->data = x;
	   new_element->left = NULL;
	   new_element->right = NULL;
	   if (*root == NULL)
	   {
			 *root = new_element;
	   }
	   enqueue (&q, *root);
	   while (isEmpty (q) == -1)
	   {
			 d_temp = dequeue (&q);
			 printf("Value of left child of node %d \n", d_temp->data);
			 scanf("%d", &x);
			 if (x != -1)
			 {
				    temp = (struct Node*)malloc (sizeof (struct Node));
				    temp->data = x;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->left = temp;
				    enqueue (&q, temp);
			 }
			 printf("Value of right child of node %d \n", d_temp->data);
			 scanf("%d", &y);
			 if (x != -1)
			 {
				    temp = (struct Node*)malloc (sizeof (struct Node));
				    temp->data = y;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->right = temp;
				    enqueue (&q, temp);
			 }
	   }
}
#if 0
void preorder (struct Node* root)
{
	   if (root != NULL)
	   {
			 printf("%d \n", root->data);
			 preorder (root->left);
			 preorder (root->right);
	   }
}
#endif

void preorder (struct Node* root)
{
	   struct stack* s =NULL;
	   while (root != NULL || is_s_empty(s) == -1)
	   {
			 if (root != NULL)

			 {
				    printf("%d \n", root->data);
				    push (&s, root);
				    root = root->left;
			 } else
			 {
				    root = pop (&s);
				    root = root->right;
			 }
	   }
}
/*
   void inorder (struct Node* root)
   {
   if (root != NULL)
   {
   inorder (root->left);
   printf("%d \n", root->data);
   inorder (root->right);
   }
   }
 */

void inorder (struct Node* root)
{
	   struct stack* s = NULL;
	   while (root != NULL || is_s_empty (s) == -1)
	   {
			 if (root != NULL)
			 {
				    push (&s, root);
				    root = root->left;
			 } else
			 {
				    root = pop (&s);
				    printf("%d \n", root->data);
				    root = root->right;
			 }
	   }
}
/*
   Level Order Traversa of a Binary Tree
 */
void levelorder (struct Node* root)
{
	   struct Queue* q = NULL;
	   printf("%d \n", root->data);
	   enqueue (&q, root);
	   while (isEmpty (q) == -1)
	   {
			 root = dequeue (&q);
			 if (root->left != NULL)
			 {
				    printf("%d \n", root->left->data);
				    enqueue (&q, root->left);
			 }

			 if (root->right != NULL)
			 {
				    printf("%d \n", root->right->data);
				    enqueue (&q, root->right);
			 }
	   }
}

int main ()
{
	   struct Node* root = NULL;
	   create (&root);
	   levelorder (root);
	   printf("INORDER\n");
	   inorder (root);
	   return 0;
}
