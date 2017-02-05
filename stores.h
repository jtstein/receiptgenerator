//Jordan Stein
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//stores.h

#ifndef _stores
#define _stores

#include <vector>

struct stores{
	std::string cashier, storeStreet, storeCity, storePhone;
	int storeNum = rand() % 27 + 1;
};


//Pre:stores object has been created and passed. int i is a random integer between 1-10
//Post: Fills store info with key of int
void populateStore(stores& store, int i)
{
	std::string names[10] = { "Bill", "Austin", "Mary", "Jessica", "Caitlyn", "James", "Martin", "Kyle", "Jordan", "Devon" }; // cashier names
	
	switch (i)
	{
	case 1:
		store.storeStreet = "750 N Ridge Rd";
		store.storeCity = "Castle Rock, CO 80104";
		store.storePhone = "(303) 660-2500";
		store.cashier = names[rand() % 9];
		break;

	case 2:
		store.storeStreet = "100 Founders Pkwy";
		store.storeCity = "Castle Rock, CO 80104";
		store.storePhone = "(303) 663-0768";
		store.cashier = names[rand() % 9];
		break;

	case 3:
		store.storeStreet = "1331 Speer Blvd";
		store.storeCity = "Denver, CO 80204";
		store.storePhone = "(303) 571-5566";
		store.cashier = names[rand() % 9];
		break;

	case 4:
		store.storeStreet = "1725 Sheridan Blvd";
		store.storeCity = "Edgewater, CO 80214";
		store.storePhone = "(303) 237-4988";
		store.cashier = names[rand() % 9];
		break;

	case 5:
		store.storeStreet = "5301 West 38th Ave";
		store.storeCity = "Wheat Ridge, CO 80212";
		store.storePhone = "(303) 425-7356";
		store.cashier = names[rand() % 9];
		break;

	case 6:
		store.storeStreet = "1650 30th St";
		store.storeCity = "Boulder, CO 80301";
		store.storePhone = "(303) 443-9622";
		store.cashier = names[rand() % 9];
		break;

	case 7:
		store.storeStreet = "1927 Wadsworth Blvd";
		store.storeCity = "Lakewood, CO 80227";
		store.storePhone = "(303) 985-8795";
		store.cashier = names[rand() % 9];
		break;

	case 8:
		store.storeStreet = "5050 E Arapahoe Rd";
		store.storeCity = "Centennial, CO 80122";
		store.storePhone = "(303) 770-3400";
		store.cashier = names[rand() % 9];
		break;
		
	case 9:
		store.storeStreet = "7575 S University Blvd";
		store.storeCity = "Centennial, CO 80122";
		store.storePhone = "(303) 789-0530";
		store.cashier = names[rand() % 9];
		break;

	case 10:
		store.storeStreet = "8673 S Quebec St";
		store.storeCity = "Highlands Ranch, CO 80130";
		store.storePhone = "(303) 683-4994";
		store.cashier = names[rand() % 9];
		break;

	}
}
#endif