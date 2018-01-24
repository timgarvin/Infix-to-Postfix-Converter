//Tim Garvin

class Node
{
	friend class Stack; //Declares the class Stack a friend

	private:
		char data;
		Node* next;
	public:
		Node(); //constructor
		~Node(); //destructor
};