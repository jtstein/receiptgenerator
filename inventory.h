//Jordan Stein
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//inventory.h

#ifndef _inventory
#define _inventory

#include <string>

class inventory
{
private: 
	unsigned id;
	std::string name;
	float price;
	bool pound;

public:
	//constructors
	inventory();
	inventory(unsigned, std::string, float);

	//modifiers
	void setID(unsigned);
	unsigned getID();
	void setName(std::string);
	std::string getName();
	void setPrice(float);
	float getPrice();
	void setPound(bool);
	bool getPound();

	//Pre: if a purchase was made in lbs, a random number is generated from 1-3 and passed to this function
	//Post: updates the name of item in lbs for printing the receipt
	void updateName(int);

	//Pre: non-empty string of item name is passed
	//Post: Checks if an item is measured in pounds
	bool isPound(std::string); //FRIEND
};

#endif