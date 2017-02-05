//Jordan Stein
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//purchase.h

#ifndef _purchases
#define _purchases

#include "inventory.h"
#include <vector>

class purchase
{
private:
	int numofItems;
	int amount; //holds the amount of each item purchased.
	std::vector<inventory> inv;
	std::vector<inventory> purchases;

public:
	//constructors
	purchase();
	purchase(int, std::vector<inventory>);

	//Pre: n/a
	//Post: returns purchases vector
	std::vector<inventory> getPurchases() const; //const class function

	//Pre: inv vector is filled with data
	//Post: fills the purchases vector with random items from the inv vector.
	void makePurchase();
};

#endif