//Tim Garvin

#include "converter.h"

//Initializes constructor and variables
Stack::Stack()
{
	top = NULL;
	size = 0;
};

//Pushes values onto the stack
void Stack::push(char value)
{
	Node *temp = new Node();

	temp->data = value;

	temp->next = top;

	top = temp;

	size++;
};

//Pops values off of the stack
char Stack::pop()
{
	char top_operator = top->data;

	Node *temp = top->next;

	delete top;

	top = temp;

	size--;

	return top_operator;
};

//Checks if the stack is full
bool Stack::isFull()
{
	if(size == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
};

//Checks if the stack is empty
bool Stack::isEmpty()
{
	if(size != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
};

//Clears the stack
void Stack::clear()
{
	top = NULL;
	size = 0;
};

//Gets the top value from the stack
char Stack::get_top()
{
	return top->data;
};

//Destructor used to clear allocated memory
Stack::~Stack()
{
	while(top != NULL)
	{
		Node *temp = top->next;
		top->next = top;
		delete top;
		top = top->next;
	}
};