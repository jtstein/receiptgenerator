//Jordan Stein 101390302
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//project.cpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <cctype>

#include "inventory.h"
#include "projectfunctions.h" //includes project namespace
#include "purchase.h"
#include "darray.tem"

int main()
{
	project::greeting();

	char shopAgain = 'y';

	while (shopAgain == 'y')
	{
		std::vector<inventory> inv; //vector will hold inventory information

		bool readInv; //tests if inventory read from file correctly
		
		try
		{
			readInv = project::readInventory(inv); //reads inventory from file into inv vector
			if (readInv == false) //readInv will be false if inventory.txt failed to read
			{
				throw 1;
			}
		}
		catch (...)
		{
			std::cerr << "We will be closed for inventory.\n";
			return EXIT_FAILURE;
		}

		int *numofItems = new int(0); //dynamically allocates number of items user will buy
		
		std::cout << "\nHow many items would you like to purchase?  -> ";
		std::cin >> *numofItems;

		purchase buy(*numofItems, inv);
		buy.makePurchase();
		std::vector<inventory> purchases = buy.getPurchases();

		darray<inventory> itemsbought; //stores purchases into darray
		for (int i = 0; i < purchases.size(); i++)
		{
			itemsbought.addElement(purchases[i]);
		}

		project::printReceipt(purchases);

		std::cout << "\nWould you like to go shopping again? (y,n)\n";
		std::cin >> shopAgain;
		shopAgain = tolower(shopAgain);

		delete numofItems; //deletes dynamically allocated numofItems variable
	}

	return EXIT_SUCCESS;
}