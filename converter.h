//Tim Garvin

#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

class Converter
{
	private:
		string command;
		string *infix;
		string *postfix;
		Stack* s;
		bool valid_entry;
	public:
		Converter(); //constructor
		~Converter(); //destructor
		
		void set_infix(); //Declares function to get the infix from the user
		void convert_infix(string infix_entry); //Declares function to convert the infix to postfix

		string get_command(); //Declares function to get the command entered
		string get_infix(); //Declares function to get the infix entered

		bool check_command(); //Declares function to validate the command entered
		void check_infix(); //Declares function to validate the infix entered

		void reset_values(); //Declares function to reset values for next conversion
};