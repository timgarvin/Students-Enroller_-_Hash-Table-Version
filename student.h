//Tim Garvin

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

#include "hash_table.h"
class Hash_Table; //Forward declaration of class Hash_Table

//Declares class to store Student information
class Student
{
	friend class Hash_Table; //Declares the class Hash_Table a friend

	private:
		Hash_Table *table; //Declares a Hash_Table class object
		
		string firstName;
		string lastName;
		string studentID;
		string classification;
		string major;
		
		string command;
		bool validEntry;
	public:
		Student(); //Constructor
		~Student(); //Destructor
		
		void execute_command(); //Declares a function to execute an Add/Remove/Print command based on user input
		
		string get_command(); //Declares a function to get the command entered
		
		void check_entry(); //Declares a function to validate user input
};
#endif