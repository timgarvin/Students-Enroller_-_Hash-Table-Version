//Tim Garvin

#include "element.h"

//Constructor implementation (Initialization of variables)
Element::Element()
{
	key = -1;
	
	empty = true;
	deleted = false;
}

//Returns the key value
int Element::get_key()
{
	return key;
}

//Returns the data value
Student* Element::get_data()
{
	return data;
}

//Returns the current empty status
bool Element::check_empty()
{
	return empty;
}

//Returns the current deleted status
bool Element::check_deleted()
{
	return deleted;
}

//Destructor
Element::~Element()
{
	delete data;
}