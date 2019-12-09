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

int isEmpty(struct Queue* q)
{
	   if (q == NULL)
			 return 1;
	   return -1;
}

void enqueue (struct Queue** head_ref, struct Node* value)
{
	   struct Queue* new_element = (struct Queue*) malloc (sizeof(struct Queue));
	   new_element->node = value;
	   new_element->next = NULL;
	   if(*head_ref == NULL)
	   {
			 *head_ref = new_element;
			 tail = *head_ref;
			 return;
	   }
	   struct Queue* elements = tail;
	   elements->next = new_element;
	   tail = new_element;
	   return;
}

struct Node* dequeue (struct Queue** head_ref)
{
	   if (isEmpty(*head_ref) == 1)
	   {
			 printf("Queue is EMpty \n");
			 return NULL;
	   }
	   struct Node* temp = NULL;
	   struct Queue* element = *head_ref;
	   temp = element->node;
	   *head_ref = element->next;
	   free(element);
	   return temp;
}

void create (struct Node** root)
{
	   struct Node* temp = NULL, *d_temp= NULL;
	   struct Queue* q = NULL;
	   int x = 0;
	   printf("Enter a value for root: \n");
	   scanf ("%d", &x);
	   struct Node* new_element = (struct Node*) malloc(sizeof(struct Node));
	   new_element->data = x;
	   new_element->left = NULL;
	   new_element->right = NULL;
	   if (*root == NULL)
	   {
			 *root = new_element;
	   }

	   enqueue (&q, *root);

	   while (isEmpty(q) == -1)
	   {
			 d_temp = dequeue (&q);
			 printf("Enter the left child of %d Node: \t", d_temp->data);
			 scanf("%d", &x);
			 if (x != -1)
			 {
				    temp = (struct Node*) malloc(sizeof(struct Node));
				    temp->data = x;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->left = temp;
				    enqueue (&q, temp);
			 }
			 printf("Enter the right child of %d Node: \t", d_temp->data);
			 scanf("%d", &x);
			 if (x != -1)
			 {
				    temp = (struct Node*) malloc(sizeof(struct Node));
				    temp->data = x;
				    temp->left = NULL;
				    temp->right = NULL;
				    d_temp->right = temp;
				    enqueue (&q, temp);
			 }
	   }
}
/*
   Iterative and Recursive functions of Preorder traversal of binary tree. The order for the traversal is root -> left -> right. The iterative version of the traversal uses a stack and as such functions have been defined below.
 */
struct stack
{
	   struct Node* node;
	   struct stack* next;
};

int is_s_empty (struct stack* s)
{
	   if (s == NULL)
			 return 1;
	   return -1;
}

void push_node (struct stack** s, struct Node* value)
{
	   struct stack* new_element = (struct stack*) malloc(sizeof(struct stack));
	   new_element->node = value;
	   new_element->next = NULL;
	   if (*s == NULL)
	   {
			 *s = new_element;
			 return;
	   }
	   new_element->next = *s;
	   *s = new_element;
	   return;
}

struct Node* pop (struct stack** s)
{
	   if (is_s_empty(*s) == 1)
	   {
			 printf("The stack is empty \n");
			 return NULL;
	   }
	   struct stack* element = *s;
	   struct Node* temp = element->node;
	   *s = element->next;
	   free(element);
	   return temp;
}

void preorder (struct Node* root)
{
	   struct stack* s = NULL;
	   while (root != NULL || is_s_empty (s) == -1)
	   {
			 if (root != NULL)
			 {
				    printf("%d \n", root->data);
				    push_node (&s, root);
				    root = root->left;
			 } else
			 {
				    root = pop (&s);
				    root = root->right;
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
/*
   Iterative and Recursive functions for inorder traversal of the binary tree. The iterative version uses the stack and its assocaited functions like preorder.
 */

void inorder (struct Node* root)
{
	   struct stack* s = NULL;
	   while (root != NULL || is_s_empty(s) == -1)
	   {
			 if (root != NULL)
			 {
				    push_node (&s, root);
				    root = root->left;
			 } else
			 {
				    root = pop (&s);
				    printf ("%d \n", root->data);
				    root = root->right;
			 }
	   }
}

#if 0
void inorder (struct Node* root)
{
	   if (root != NULL)
	   {
			 inorder (root->left);
			 printf("%d \n", root->data);
			 inorder (root->right);
	   }
}
#endif

/*
   Iterative functions for postorder traversal of binary tree. The seqence of operations is left --> right --> root. The function to push an element into the stack will be slightly different in this case and as such has been defined.
 */


void postorder (struct Node* root)
{
	   if (root != NULL)
	   {
			 postorder (root->left);
			 postorder (root->right);
			 printf("%d \n", root->data);
	   }
}

/*
   Iterative function for level order traversal of a a binary tree in which elements are printed level by level from left to right. The appreach requries a Queue for elements of the binary tree to be queued and dequeued from. 
   As such, the Queue used for binary tree creation is utilized. The function below also counts the number of nodes within the binary tree using the variable count.
 */

void levelorder (struct Node* root)
{
	   struct Queue* q = NULL;
	   int count = 0;
	   if (root == NULL)
			 return;
	   count++;
	   printf("%d \t", root->data);
	   enqueue (&q, root);
	   while (isEmpty (q) == -1)
	   {
			 root = dequeue (&q);
			 if (root->left != NULL)
			 {
				    count++;
				    printf("%d \t", root->left->data);
				    enqueue (&q, root->left);
			 }
			 if (root->right != NULL)
			 {
				    count++;
				    printf("%d \t", root->right->data);
				    enqueue (&q, root->right);
			 }
	   }
	   printf("\n");
	   printf("The root value now is: %d \n", root->data);
	   printf("The number of nodes in the Binary Tree are: %d \n", count);
	   return;
}
/*
   Recursive function to display the number of nodes in the binary tree.
 */

int count (struct Node* root)
{
	   int x = 0, y = 0;
	   if (root != NULL)
	   {
			 x = count (root->left);
			 y = count(root->right);
			 return x+y+1;
	   }

	   return 0;
}

int main ()
{
	   struct Node* root = NULL;
	   create (&root);
	   preorder (root);
	   printf("POSTORDER \n");
	   postorder (root);
	   printf("LEVEL ORDER: \t");
	   levelorder(root);
	   int number = count (root);
	   printf("The number of Nodes in the binary Tree are: %d \n", number);
	   return 0;
}	
