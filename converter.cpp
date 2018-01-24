//Tim Garvin

#include "converter.h"

//Initializes constructor and variables
Converter::Converter()
{
	infix = new string;
	*infix = "none";
	postfix = new string;
	*postfix = "none";
	s = new Stack();
	command = "none";
	valid_entry = true;
};

//Gets the infix from the user
void Converter::set_infix()
{
	cout<<"infix_to_postfix> ";
	cin>>command;

	//Checks if command is valid and if the next character is a space
	if(check_command() == true && cin.peek() == ' ')
	{
		cin>>*infix;

		check_infix();
	}
};

//Converts the infix to postfix
void Converter::convert_infix(string infix_entry)
{
	//Checks if the command is 'convert' and whether user entry is valid so far
	if(command == "convert" && valid_entry == true)
	{
		*postfix = "";

		string user_entry;
		user_entry = *infix;

		//Converts the infix to postfix using a string variable and a stack
		for(int i = 0; i < user_entry.length(); i++)
		{
			//Checks if current character in the infix is a number
			if(isdigit(user_entry[i]))
			{
					*postfix += user_entry[i];
			}
			else //Handles operators in a stack
			{
				//Pushes or Pops the '+' and '-' operators in the stack
				if(user_entry[i] == '+' || user_entry[i] == '-')
				{
					if(s->isEmpty() == true)
					{
						s->push(user_entry[i]);
					}
					else
					{
						while(s->isEmpty() == false)
						{
							*postfix += s->pop();
						}
						
					s->push(user_entry[i]);
					}
				}

				//Pushes or Pops the '*' and '/' operators in the stack
				else if(user_entry[i] == '*' || user_entry[i] == '/')
				{
					if(s->isEmpty() == true)
					{
						s->push(user_entry[i]);
					}
					else
					{
						while(s->isEmpty() == false && (s->get_top() == '*' || s->get_top() == '/'))
						{
							*postfix += s->pop();
						}
					
					s->push(user_entry[i]);
					}					
				}
			}
		}

		//Pops remaining values from the stack
		while(s->isEmpty() == false)
		{
			*postfix += s->pop();
		}

		//Displays postfix
		cout<<*postfix<<endl;

		//Clears stack for next conversion
		s->clear();
	}
};

//Gets the command value
string Converter::get_command()
{
	return command;
};

//Gets the infix entered
string Converter::get_infix()
{
	return *infix;
};

//Checks if user entered a valid command
bool Converter::check_command()
{
	if(command != "convert" && command != "quit")
	{
		cout<<"Error! Command not supported."<<endl;
		valid_entry = false;
		return false;
	}
	else
	{
		return true;
	}
};

//Checks that user entered a valid infix
void Converter::check_infix()
{
	string entry = *infix;

	//Checks that every character in the infix is either a number or operator
	for(int i=0; i < infix->length(); i++)
	{
		if(!isdigit(entry[i]))
		{
			switch(entry[i])
			{
				case '+':
					break;
				case '-':
					break;
				case '*':
					break;
				case '/':
					break;
				default:
					cout<<"Error! Input not valid!"<<endl;
					valid_entry = false;
			}
		}
		else
		{
			valid_entry = true;
		}
	}
};

//Resets values for next conversion
void Converter::reset_values()
{
	*infix = "none";
	*postfix = "none";
	valid_entry = true;
};

//Destructor used to clear allocated memory
Converter::~Converter()
{
	delete infix;
	delete postfix;
};