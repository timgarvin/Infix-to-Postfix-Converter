//Tim Garvin

#include "converter.h"

int main()
{
	//Instantiates a class Converter object
	Converter* convert;
	convert = new Converter();

	//Loops class Converter until the user types 'quit'
	while(convert->get_command() != "quit")
	{
		convert->set_infix(); //Gets the infix from the user
		convert->convert_infix(convert->get_infix()); //Converts infix to postfix
		convert->reset_values(); //Resets values for next conversion
	}

	return 0;
}