#include <iostream>

class Node
{
	public:
		int data;
		Node* next;
};

Node* append (Node* head_ref, int value )
{
	Node* new_element = new Node();

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

int subListSearch (Node* first, Node* second)
{
	Node* ptr1 = first, *ptr2 = second;

	if (first == nullptr && second == nullptr)
	{
		return 1;
	} else if (first == nullptr && second != nullptr)
	{
		return -1;
	} else if (first != nullptr && second == nullptr)
	{
		return -1;
	}

	while (first != nullptr)
	{
		ptr1 = first;

		while (ptr2 != nullptr)
		{
			if (ptr1 == nullptr)
			{
				return -1;
			} else if (ptr1 -> data == ptr2 -> data)
			{
				ptr1 = ptr1 -> next;
				ptr2 = ptr2 -> next;
			} else
				break;
		}

		if (ptr2 == nullptr)
			return 1;

		first = first -> next;
		ptr2 = second;
	}
}

void printList (Node* head_ref)
{
	int count = 0;
	std::cout <<"The number of elements in the Linked List are:" << std::endl;

	while (head_ref != nullptr)
	{
		count ++;
		std::cout << head_ref -> data << std::endl;
		head_ref = head_ref -> next;
	}

	std::cout <<"The number of elements in the Linked List are:" << count <<std::endl;
}



int main ()
{
	Node* first = nullptr;
	Node* second = nullptr;

	first = append (first, 10);
	first = append (first, 20);
	first = append (first, 30);
	first = append (first, 40);
	first = append (first, 50);
	first = append (first, 60);
	first = append (first, 70);
	first = append (first, 80);
	first = append (first, 90);
	first = append (first, 100);

	second = append (second, 10);
	second = append (second, 25);
	second = append (second, 30);
	second = append (second, 40);

	printList (first);
	std::cout <<"----------------------------------" <<std::endl;

	printList (second);

	int result = subListSearch(first, second);
	result == 1 ? std::cout <<"List Found" : std::cout <<"List Not found";
	std::cin.get();

	return 0;
}
