#include <iostream>
#include "../inc/inc.h"

void Node::construct (Node** root, int* arr, int len)
{
	Stack* s = nullptr;
	Node* temp = nullptr, *d_temp = nullptr, *test = nullptr;
	int i = 0;
	Node* new_element = new Node (arr[i++]);
	if (*root == nullptr)
		*root = new_element;
	
	s->push(&s, new_element);

	while (i < len)
	{
		d_temp = nullptr;
		test = s->peek(s);

		while (s->isSempty(s) == -1 && *(int*)test->data < arr[i])
		{
			d_temp = s->pop(&s);
			if (s != nullptr)
				test = s->peek (s);
		}

		temp = new Node (arr[i++]);

		if (d_temp != nullptr)
		{
			d_temp ->right = temp;
			s->push(&s, temp);
		}else
		{
			test->left = temp;
			s->push(&s, temp);
		}
	}
	return;
}
