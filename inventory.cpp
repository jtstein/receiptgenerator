//Jordan Stein 101390302
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//inventory.cpp

#include "inventory.h"
#include <string>


bool inventory::isPound(std::string p)//friend function
{
	char x[4] = { p[0], p[2], p[3] };
	if (x[0] == '1' && x[1] == 'l' && x[2] == 'b') //checks if '1 lb' is in string
	{
		return true;
	}
	return false;
}

//constructors
inventory::inventory()
{
}

inventory::inventory(unsigned i, std::string n, float p)
{
	id = i;
	name = n;
	price = p;

	pound = isPound(n);
}

//modifiers
void inventory::setID(unsigned i) 
{
	id = i; 
}
unsigned inventory::getID() 
{ 
	return id;
}

void inventory::setName(std::string n)
{
	name = n; 
}
std::string inventory::getName()
{ 
	return name; 
}

void inventory::setPrice(float p) 
{ 
	price = p;
}
float inventory::getPrice() 
{ 
	return price; 
}

void inventory::setPound(bool p)
{
	pound = p;
}
bool inventory::getPound()
{
	return pound;
}

void inventory::updateName(int lbs)
{
	if (lbs == 1) name[0] = '1';
	if (lbs == 2) name[0] = '2';
	if (lbs == 3) name[0] = '3';
}