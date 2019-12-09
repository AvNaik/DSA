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

int isEmpty (struct Queue* q)
{
	   if (q == NULL)
			 return 1;
	   return -1;
}
void enqueue (struct Queue** head_ref, struct Node* value)
{
	   struct Queue* new_element = (struct Queue*) malloc(sizeof(struct Queue));
	   new_element->node = value;
	   new_element->next = NULL;
	   if (*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 tail = new_element;
			 return;
	   }
	   struct Queue* element = tail;
	   element->next = new_element;
	   tail = new_element;
	   return;
}

struct Node* dequeue (struct Queue** head_ref)
{
	   if (isEmpty (*head_ref) == 1)
	   {
			 printf("Queue is Empty. Need to Enqueue. \n");
			 return NULL;
	   }
	   struct Queue* element = *head_ref;
	   struct Node* temp = element->node;
	   *head_ref = element->next;
	   free (element);
	   return temp;
}

void create (struct Node** root)
{
	   struct Node* temp = NULL, *d_temp = NULL;
	   int x = 0;
	   struct Queue* q = NULL;
	   printf("Enter value of root: \t");
	   scanf("%d", &x);
	   struct Node* new_element = (struct Node*) malloc(sizeof (struct Node));
	   new_element->data = x;
	   new_element->left = NULL;
	   new_element->right = NULL;
	   if (*root == NULL)
	   {
			 *root = new_element;
	   }
	   enqueue (&q, new_element);
	   while (isEmpty(q) == -1)
	   {
			 d_temp = dequeue (&q);
			 printf("Enter the left child for the %d node: \t", d_temp->data);
			 scanf("%d", &x);
			 if (x!= -1)
			 {
				    temp = (struct Node*) malloc (sizeof (struct Node));
				    temp->data = x;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->left = temp;
				    enqueue (&q, temp);
			 }

			 printf("Enter the right child for the %d node: \t", d_temp->data);
			 scanf("%d", &x);
			 if (x!= -1)
			 {
				    temp = (struct Node*) malloc (sizeof (struct Node));
				    temp->data = x;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->right = temp;
				    enqueue (&q, temp);
			 }
	   }
}
/*
	Functions to delete a Node from Binary Tree.
	1. Starting at root, find the deepest and rightmost node in binary tree and node which we want to delete.
	2. Replace the deepest rightmost node’s data with node to be deleted.
	3. Then delete the deepest rightmost node.
*/

void delete_last (struct Node* root, struct Node* temp)
{
	if (root == NULL)
		return;
	struct Node* elements = root;
	struct Node* del = NULL;
	struct Queue* q = NULL;
	enqueue (&q, elements);
	while (isEmpty(q) == -1)
	{
		del = dequeue (&q);
		if (del == temp)
		{
			del = NULL;
			free(temp);
			return;
		}
		if (del->left)
		{
			if (del->left == temp)
			{
				del->left = NULL;
				free (temp);
				return;
			} else
				enqueue(&q, del->left);
		}
		if (del->right)
		{
			if (del->right == temp)
			{
				del->right = NULL;
				free (temp);
				return;
			} else
				enqueue(&q, del->right);
		}
	}
}

void delete_node (struct Node** root, int key)
{
	struct Node* elements = *root, *temp = NULL, *d_temp = NULL;
	if (elements == NULL)
		return;
	if (elements->left == NULL && elements->right == NULL)
	{
		if (elements->data == key)
		{
			printf("Binary Tree Deleted COmpletly \n");
			free (elements);
			return;
		} else
		{
			return;
		}
	}
	struct Queue* q = NULL;
	enqueue (&q, elements);
	while (isEmpty (q) == -1)
	{
		temp = dequeue (&q);
		if (temp ->data == key)
		{
			d_temp = temp;
		}
		if (temp->left)
			enqueue (&q, temp->left);
		if (temp->right)
			enqueue(&q, temp->right);
	}

	if (d_temp != NULL)
	{
		int x = temp->data;
		d_temp->data = x;
		delete_last (*root, temp);
		
	}
	return;
}

void levelorder (struct Node* root)
{
	   struct Queue* q = NULL;
	   if (root == NULL)
	   {
			 printf("The binary tree does not have any element as of now. \n");
			 return;
	   }
	   int count = 1;
	   printf("%d \t", root->data);
	   enqueue (&q, root);
	   while (isEmpty(q) == -1)
	   {
			 root = dequeue (&q);
			 if (root->left)
			 {
			 		count ++;
				    printf("%d \t", root->left->data);
				    enqueue (&q, root->left);
			 }
			 if (root->right)
			 {
			 		count++;
				    printf("%d \t", root->right->data);
				    enqueue (&q, root->right);
			 }
	   }
	   printf("\n");
	   printf("The number of elements in the Binary Tree are: %d \n", count);
}


int main ()
{
	   struct Node* root = NULL;
	   create (&root);
	   printf("LEVEL ORDER: \t");
	   levelorder (root);
	   delete_node (&root, 3);
	   printf("LEVEL ORDER: \t");
	   levelorder (root);
	   return 0;
}
