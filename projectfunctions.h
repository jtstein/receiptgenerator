//Jordan Stein 101390302
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//projectfunctions.h

#ifndef _projectfunctions
#define _projectfunctions

#include <string>
#include <vector>
#include "inventory.h"

namespace project
{
	//Pre: n/a
	//Post: Greets user / explains program / prompts for keypress to continue.
	void greeting();

	//Pre: Vector of inventory objects has been created and passed to function
	//Post: Reads data from file into inventory vector.
	//		returns false if file fails to read.
	bool readInventory(std::vector<inventory>& inv);


	//Pre: purchases object has been filled/passed
	//Post: prints a receipt to the screen from purchases vector
	void printReceipt(std::vector<inventory> purchases);
}
#endif