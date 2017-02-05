//Jordan Stein
//CSCI 2312 Fall 2014
//Grocery Store Shopping Project
//kingsoopers.cpp

#include "kingsoopers.h"

kingsoopers::kingsoopers()
{
	std::string names[10] = { "Bill", "Austin", "Mary", "Jessica", "Caitlyn", "James", "Martin", "Kyle", "Jordan", "Devon" }; // cashier names

	store[0].storeStreet = "750 N Ridge Rd";
	store[0].storeCity = "Castle Rock, CO 80104";
	store[0].storePhone = "(303) 660-2500";
	store[0].cashier = names[rand() % 9];
	store[1].storeStreet = "100 Founders Pkwy";
	store[1].storeCity = "Castle Rock, CO 80104";
	store[1].storePhone = "(303) 663-0768";
	store[1].cashier = names[rand() % 9];
	store[2].storeStreet = "1331 Speer Blvd";
	store[2].storeCity = "Denver, CO 80204";
	store[2].storePhone = "(303) 571-5566";
	store[2].cashier = names[rand() % 9];
	store[3].storeStreet = "1725 Sheridan Blvd";
	store[3].storeCity = "Edgewater, CO 80214";
	store[3].storePhone = "(303) 237-4988";
	store[3].cashier = names[rand() % 9];
	store[4].storeStreet = "5301 West 38th Ave";
	store[4].storeCity = "Wheat Ridge, CO 80212";
	store[4].storePhone = "(303) 425-7356";
	store[4].cashier = names[rand() % 9];
	store[5].storeStreet = "1650 30th St";
	store[5].storeCity = "Boulder, CO 80301";
	store[5].storePhone = "(303) 443-9622";
	store[5].cashier = names[rand() % 9];
	store[6].storeStreet = "1927 Wadsworth Blvd";
	store[6].storeCity = "Lakewood, CO 80227";
	store[6].storePhone = "(303) 985-8795";
	store[6].cashier = names[rand() % 9];
}