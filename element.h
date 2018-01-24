//Tim Garvin

#ifndef ELEMENT_H
#define ELEMENT_H

#include "student.h"

class Student; //Forward declaration of class Student

//Declares class to store information
class Element
{
	friend class Hash_Table; //Declares the class Hash_Table a friend
	
	private:
		Student* data; //Declares a class object to hold data
		
		int key; //Declares key to retain distinct elements
		
		bool empty;
		bool deleted;
	public:
		Element(); //Constructor
		~Element(); //Destructor
		
		int get_key(); //Declares a function to get the key value
		
		Student* get_data(); //Declares a function to get the student data
		
		bool check_empty(); //Declares a function to check if the current element is empty
		bool check_deleted(); //Declares a function to check if the current element was deleted
};

#endif