#include <iostream>

class Node
{
	   public:
			 int data;
			 Node* next;
};


Node* append (Node* head_ref, int value)
{
	   Node* new_element = new Node ();

	   new_element -> data = value;
	   new_element -> next = nullptr;

	   if (head_ref == nullptr)
	   {
			 head_ref = new_element;
			 return head_ref;
	   }

	   Node* elements = head_ref;

	   while(elements -> next != nullptr)
			 elements = elements -> next;

	   elements -> next = new_element;

	   return head_ref;
}

/*
   void reorder (Node* head_ref)
   {
   Node* elements = head_ref;
   Node* reorder_element = head_ref;
   Node* next_element = reorder_element -> next;
   int count = 0;

   while (elements -> next != nullptr)
   {
   if (count > 0)
   {

   elements = next_element;
   reorder_element = next_element;
   next_element = next_element -> next;
   }			 

   while (elements -> next -> next != nullptr)
   elements = elements -> next;

   reorder_element -> next = elements -> next;
   reorder_element -> next -> next = next_element;

   elements -> next = nullptr;
   count++;
   }


   }
 */


Node* gettail_previous (Node* head_ref)
{
	   Node* temp = head_ref;
	   while (temp -> next -> next != nullptr)
	   {
			 temp = temp -> next;
	   }

	   return temp;
}


void reorder (Node* head_ref)
{
	   Node* elements = head_ref;
	   Node* next_element = nullptr, *end = nullptr, *previous = nullptr;
	   while (elements -> next != nullptr && elements -> next -> next != nullptr)
	   {
			 next_element = elements -> next;
			 previous = gettail_previous (elements);
			 end = previous -> next;
			 elements -> next = end;
			 previous -> next = nullptr;
			 end -> next = next_element;

			 elements = elements -> next -> next;

	   }
}
void printList(const Node *head_ref)
{
	   int count = 0;
	   const Node *elements = head_ref;
	   std::cout << "The elements of the Linked List are: " << std::endl;
	   while (elements != nullptr)	
	   {
			 count++;
			 std::cout << elements->data << std::endl;
			 elements = elements->next;
	   }
	   std::cout << "The Number of elements in the Linked list are: " << count << ::std::endl;
}


int main()
{
	   Node* head = nullptr;

	   head = append (head, 10);
	   head = append (head, 20);
	   head = append (head, 30);
	   head = append (head, 40);
	   head = append (head, 50);
	   head = append (head, 60);
	   head = append (head, 70);
	   head = append (head, 80);
	   printList(head);

	   reorder (head);
	   printList (head);
	   return 0;
}
