//Tim Garvin

#include "student.h"

//Constructor implementation (Initialization of variables)
Student::Student()
{
	table = new Hash_Table(); //Initializes a new class Hash_Table object
	
	firstName = "none";
	lastName = "none";
	studentID = "none";
	classification = "none";
	major = "none";
	
	command = "none";
	validEntry = true;
}

//Executes an Add/Remove/Print command based on user input
void Student::execute_command()
{
	cout<<"set> ";
	cin>>command;

	//Checks if the user wants to add a student and if the next character is a space
	if(command == "add" && cin.peek() == ' ')
	{
		cin>>firstName;
		cin>>lastName;
		cin>>studentID;
		cin>>classification;
		cin>>major;
		
		check_entry(); //Checks for valid user input
		
		if(validEntry) //If user input is valid, then adds a student.
		{
			table->add(firstName, lastName, studentID, classification, major); //Adds a student to the hash table
		}
		else //If user input is invalid, resets validEntry back to true for next input
		{
			validEntry = true;
		}
	}
	
	//Checks if the user wants to remove a student and if the next character is a space
	if(command == "remove" && cin.peek() == ' ')
	{
		cin>>studentID;
		
		table->remove(studentID); //Removes a student from the hash table by resetting values and leaving a deleted marker behind
	}
	
	//Checks if the user wants to print student records and if the next character is a space
	if(command == "print")
	{
		table->print();
	}
}

//Returns the current command value
string Student::get_command()
{
	return command;
}

//Validates user input
void Student::check_entry()
{
	//Checks that the entered Student ID # only contains numbers
	for(int i = 0; i < studentID.size(); i++)
	{
		//Displays error message if a non-numerical value is found
		if(!isdigit(studentID[i]))
		{
			cout<<"Error! Student ID must contain only numbers!"<<endl;
			validEntry = false;
			break;
		}
	}
}

//Destructor
Student::~Student()
{
	delete table;
}