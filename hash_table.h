//Tim Garvin

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "element.h"

class Element; //Forward declaration of class Element

//Declares class for a Hash Table
class Hash_Table
{
	private:
		Element* table_data[10]; //Declares an Element class object
		
		int size;
	public:
		Hash_Table(); //Constructor
		~Hash_Table(); //Destructor
		
		void add(string fName, string lName, string id, string class_level, string mjr); //Declares a function to add a new entry to the hash table
		void remove(string id); //Declares a function to remove an entry from the hash table
		void print(); //Declares a function to print elements in the hash table
		
		bool check_key_exists(int id); //Declares a function to make sure the key doesn't already exist
		bool check_full(); //Declares a function to make sure the hash table isn't already full
};
#endif