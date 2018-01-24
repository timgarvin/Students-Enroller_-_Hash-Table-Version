//Tim Garvin

#include "student.h"

int main()
{
	//Instantiates a class Student object
	Student* s;
	s = new Student();

	//Loops class Student until the user types 'quit'
	while(s->get_command() != "quit")
	{
		s->execute_command(); //Calls the execute_command function in the Student class to Add/Remove/Print a student
	}
	
	return 0;
}