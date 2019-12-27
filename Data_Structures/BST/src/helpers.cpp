#include <iostream>
#include "../inc/inc.h"

int Stack::isSempty (Stack* s)
{
	if (s == nullptr)
		return 1;
	return -1;
}

void Stack::push (Stack** s, Node* value)
{
	Stack* new_element = new Stack(value);
	if (*s == nullptr)
	{
		*s = new_element;
		return;
	}

	Stack* elements = *s;
	new_element->next = elements;
	*s = new_element;
	return;
}

Node* Stack::pop (Stack** s)
{
	Stack* element = *s;
	if (element->isSempty(*s) == 1)
	{
		std::cout << "The Stack is empty as of now" <<std::endl;
		return NULL;
	}

	Node* temp = element->node;
	*s = element->next;
	delete element;
	return temp;
}

Node* Stack::peek (Stack* s)
{
	return s->node;
}


