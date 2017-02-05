//Jordan Stein 101390302
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//purchase.cpp

#include "purchase.h"
#include <time.h>
#include <vector>

purchase::purchase()
{

}

purchase::purchase(int items, std::vector<inventory> in)
{
	numofItems = items;
	inv = in;
}

std::vector<inventory> purchase::getPurchases() const
{
	return purchases;
}

void purchase::makePurchase()
{
	srand(time(NULL)); //uses time for random number generator

	int code = 0; //holds code of item that will be bought

	while (purchases.size() != numofItems)
	{
		code = rand() % 100 + 2300; //2300 is added so the random generator is equal to potential item codes

		for (int j = 0; j < inv.size(); j++)
		{
			if (inv[j].getID() == code) //tests if code is in the inventory
			{
				purchases.push_back(inventory(inv[j].getID(), inv[j].getName(), inv[j].getPrice()));
				break;
			}
		}
	}
}