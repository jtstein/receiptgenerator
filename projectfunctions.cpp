//Jordan Stein 101390302
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//projectfunctions.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "inventory.h"
#include "purchase.h"
#include "stores.h"
#include "projectfunctions.h"


void project::greeting()
{
	std::cout << "Welcome! This program will print a randomly generated receipt from our inventory.\n\nPress any key and ENTER to continue.\n";
	
	char x;
	std::cin >> x; //prompts user for keypress
}

bool project::readInventory(std::vector<inventory>& inv)
{
	std::ifstream in("inventory.txt");
		if (!in) return false;
	
	std::string text;
	std::vector<std::string> items;

	while (!in.eof())
	{
		std::getline(in, text);
		items.push_back(text); //reads each line from inventory.txt into a element in the items vector
	}

	in.close();

	std::string id;
	std::string name;
	std::string price;


	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[i].size(); j++)
		{
			if (j < 4) //first four elements of each "items" will be the items id
			{
				id += items[i][j];
			}

			else if (j < items[i].size() - 5 && items[i][j] != '|') //the next elements will be the items name until "|" is encountered
			{														//5 is decremented from loop test because the last 5 elements will be the price.
				name += items[i][j];
			}

			else if (items[i][j] != '|') //last elements will be the price
			{
				price += items[i][j];
			}

		}
		
		inventory item(stoi(id), name, stof(price)); //converts id to int and price to float when calling constructor
		inv.push_back(item);

			id.clear();	//clears each variable to read new data for the next items element.
			name.clear();
			price.clear();
	}
	return true;
}


template<typename T> //TEMPLATE function to calculate tax
T calculateTax(T tax)
{
	return .0396*tax; //3.96% tax rate
}


void project::printReceipt(std::vector<inventory> purchases)
{
	stores store;
	int storeNumber = rand() % 9 + 1;
	populateStore(store,storeNumber); //fills store struct with random store information
									  //name, street, phone, cashier, number
	std::cout << std::endl << std::endl <<
		"  	       ______________" << std::endl <<
		"	       ______________" << std::endl <<
		"	       _KING_SOOPERS_" << std::endl <<
		"	       ______________" << std::endl << std::endl << std::endl;

	std::cout << "	     " << store.storeStreet << std::endl;
	std::cout << "	     " << store.storePhone << " Store # " << store.storeNum << std::endl;
	std::cout << "	     Your Cashier Was " << store.cashier << std::endl << std::endl;

	std::cout << std::setw(20) << "  Valued Customer	         *******" << rand() % 8999 + 1000 << std::endl << std::endl; //rand() gives last four digits of credit card

	float cash = 50; // each customer carries $50 cash on hand
	int amount = 0; // amount of lbs for each purchased measured in pounds
	float total = 0; // total price of all items purchased
	float tax = 0; // tax after all sales are complete
	float change = 0; // change after sale is complete
	float oldprice = 0; // stores unmodified price for items sold in lbs

	for (int i = 0; i < purchases.size(); i++)
	{
		if (purchases[i].getPound() == 1)
		{
			amount = rand() % 3 + 1; //if item is in pounds, randomly buys 1-3 lbs of that item and updates price.
			
			if (amount != 1)
			{
				oldprice = purchases[i].getPrice();
			}

			purchases[i].setPrice(amount*purchases[i].getPrice()); //updates price to match amount of lbs purchased
			purchases[i].updateName(amount); //updates name of item based on how many lbs was purchased

			total += purchases[i].getPrice();

			if (amount != 1)
			{
				std::cout << "   " << std::setw(21) << std::left << purchases[i].getName() << "   " << amount << " @ "; if (oldprice > 1) std::cout << std::setprecision(3); else std::cout << std::setprecision(2); std::cout << oldprice << "    ";
				oldprice = 0;
			}
			else std::cout << "   " << std::setw(36) << std::left << purchases[i].getName();
		}
		else
		{
			total += purchases[i].getPrice();
			std::cout << "   " << std::setw(36) << std::left << purchases[i].getName();
		}
		
		std::cout << std::setw(4) << std::right; if (purchases[i].getPrice() > 1) std::cout << std::setprecision(3); else std::cout << std::setprecision(2); std::cout << purchases[i].getPrice() << std::endl;
	}

	tax = calculateTax(total); //template function that returns tax
	total += tax; //updates tax into total
	change = cash - total; //computes total change

	std::cout << "\n " << std::setw(38) << std::left << "3.96% Tax" << std::showpoint; 
	if (tax <= 1) std::cout << std::setprecision(2); 
	else std::cout << std::setprecision(3); 
	std::cout << tax;
	std::cout << "\n " << std::setw(37) << std::left << "*** BALANCE" << std::setprecision(4) << total;
	std::cout << "\n " << std::setw(37) << std::left << "    Cash" << std::setprecision(4) << std::showpoint << cash;
	std::cout << "\n " << std::setw(37) << std::left << "    Change";
	if (change >= 10 || change <= 0) std::cout << std::setprecision(4);
	else std::cout << std::setprecision(3);
	std::cout << change;
	std::cout << "\n "; 
	if (purchases.size() < 10) std::cout << std::setw(41); 
	else { std::cout << std::setw(40); }
	std::cout << std::left << "TOTAL NUMBER OF ITEMS SOLD =" << purchases.size() << std::endl;
}