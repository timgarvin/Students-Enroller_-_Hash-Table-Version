//Tim Garvin

#include "hash_table.h"

//Constructor implementation (Initialization of variables)
Hash_Table::Hash_Table()
{
	size = 10;
	
	Element* initial_element = new Element(); //Initializes a new class Element object to initialize the hash table elements
	
	initial_element->empty = true;
	
	//Initializes the hash table elements with initial_element
	for(int i = 0; i < size; i++)
	{
		table_data[i] = initial_element;
	}
}

//Adds a new element to the hash table
void Hash_Table::add(string fName, string lName, string id, string class_level, string mjr)
{
	//Checks that the hash table isn't full nor that the key already exists before adding a new element
	if(!check_key_exists(atoi(id.c_str())) && !check_full())
	{
		//Creates a new Element class object
		Element* new_element = new Element();
		
		//Creates a new Student class object
		Student *new_student;
		new_student = new Student();
		
		//Sets values in the Student class object to add to the Hash Table
		new_student->firstName = fName;
		new_student->lastName = lName;
		new_student->studentID = id;
		new_student->classification = class_level;
		new_student->major = mjr;
		
		//Sets values in the Element class object to add to the Hash Table
		new_element->key = atoi(id.c_str());
		new_element->data = new_student;
		new_element->empty = false;
		
		int current_key = new_element->get_key();
		
		int index = 0;
		
		//Calculates the value from the hash table function to determine the index for where to place the new element in the hash table
		index = current_key % size;

		//Checks if the calculated index is empty, uses a rehashing function to find a new index if it isn't
		if(table_data[index]->check_empty() == true)
		{
			table_data[index] = new_element; //Adds the new element to the hash table
		}
		else
		{
			int rehash_result = 0;

			//Loops to find a new element index
			for(int i = 1; i < size; i++)
			{
				rehash_result = (index + i*i)%size; //Rehash function to find a new index in the hash table
				
				//Checks if the newly calculated index is empty
				if(table_data[rehash_result]->check_empty() == true)
				{
					table_data[rehash_result] = new_element; //Adds the new element to the hash table
					break;
				}
			}
		}
	}
}

//Removes an element from the hash table by clearing values and marking as deleted
void Hash_Table::remove(string id)
{
	//Loops to find the key and remove it if the element exists
	for(int i = 0; i < size; i++)
	{
		//Removes the element if it exists
		if(table_data[i]->get_key() == atoi(id.c_str()))
		{
			table_data[i]->key = -1;
			table_data[i]->data->firstName = "Deleted";
			table_data[i]->data->lastName = "Deleted";
			table_data[i]->data->studentID = "Deleted";
			table_data[i]->data->classification = "Deleted";
			table_data[i]->data->major = "Deleted";
			table_data[i]->empty = true;
			table_data[i]->deleted = true;
			cout<<"true"<<endl;
			break;
		}
		else if(i == size-1)
		{
			cout<<"false"<<endl; //Indicates to the user that the key does not exist
		}
	}
}

//Prints all elements to the user
void Hash_Table::print()
{
	//Loops through the hash table to print all elements
	for(int i = 0; i < size; i++)
	{
		//Prints the element when the current index is not empty in the hash table
		if(table_data[i]->check_empty() == false)
		{
			cout<<"("<<table_data[i]->data->firstName<<",";
			cout<<table_data[i]->data->lastName<<",";
			cout<<table_data[i]->data->studentID<<",";
			cout<<table_data[i]->data->classification<<",";
			cout<<table_data[i]->data->major<<")";
		}
		else if(table_data[i]->check_deleted() == true)
		{
			cout<<"(DEL)"; //Prints (DEL) when the current index was deleted from the hash table
		}
		else
		{
			cout<<"(NULL)"; //Prints (NULL) when the current index was never assigned an element in the hash table
		}
		
		//Ends the line for the display when the end of the hash table is reached
		if(i == size-1)
		{
			cout<<endl;
		}
	}
}

//Checks to make sure the key doesn't already exist
bool Hash_Table::check_key_exists(int id)
{
	bool keyExists = false;
	
	//Loops to see if the key already exists in the hash table
	for(int i = 0; i < size; i++)
	{
		if(table_data[i]->get_key() == id)
		{
			keyExists = true;
		}
	}
	
	//Returns true if key exists, false if it doesn't
	if(keyExists)
	{
		cout<<"Error! Student ID already exists!"<<endl;
		return true;
	}
	else
	{
		return false;
	}
}

//Checks to make sure the hash table isn't already full
bool Hash_Table::check_full()
{
	bool full = true;
	
	//Loops through the hash table to see if it is full
	for(int i = 0; i < size; i++)
	{
		if(table_data[i]->check_empty() == true)
		{
			full = false;
		}
	}
	
	//Returns true if full, false if not full
	if(full)
	{
		cout<<"Error! Hash table is full!"<<endl;
		return true;
	}
	else
	{
		return false;
	}
}

//Destructor
Hash_Table::~Hash_Table()
{
	delete [] table_data;
}