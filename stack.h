//Tim Garvin

#include "node.h"

class Stack
{
	private:
		Node* top;
		int size;
	public:
		Stack(); //constructor
		~Stack(); //destructor
		void push(char value); //Declares function to push values onto the stack
		char pop(); //Declares function to pop values off of the stack
		bool isFull(); //Declares function to check if stack is full
		bool isEmpty(); //Declares function to check if stack is empty
		void clear(); //Declares function to clear the stack
		char get_top(); //Declares function to return the value of the top node
};