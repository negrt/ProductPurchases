//***************************************************************************
//File: Purchase.h
//
//Purpose: To define a Purchase Object.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: All member variables were changed to pointers. Added a
//	desturctor. Added a non-member operator>> overload.
//
//Name: Timothy Negron
//Date: 11/8/2018
//Description: Added a non-member overload for the equality operator. Returns
//	true if the values of the "name" member variables are equal.
//
//Name: Timothy Negron
//Date: 12/7/2018
//Description: Added a non-member overload for the less than operator. Added
//	a non-member overload for the greater than operator.
//
//***************************************************************************

#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>
#include <string>
using namespace std;

class Purchase
{
	private:
		string *m_itemName;
		double *m_quantity;
		double *m_itemPrice;

	public:
		// Constructors & Destructor
		Purchase();
		Purchase(string itemName, double quantity, double itemPrice);
		Purchase(const Purchase& rhs);	// Copy Constructor
		~Purchase();

		// Getters & setters
		string getItemName();
		void setItemName(string itemName);

		double getQuantity();
		void setQuantity(double quantity);

		double getItemPrice();
		void setItemPrice(double itemPrice);

		// Cost function
		double Cost(); // Caculate's & Returns *m_itemPrice * *m_quantity

		// Member Overload Function Assignment Operator
		const Purchase& operator=(const Purchase& rhs);

		// Non-Member Overload Function Insertion Operator (friend of the class)
		friend ostream& operator<<(ostream& os, const Purchase& rhs);

		// Non-Member Overload Function Read Operator (friend of the class)
		friend istream& operator>>(istream& is, const Purchase& rhs);

		// Non-Member Overload Function Equality Operator (friend of the class)
		friend bool operator==(Purchase &lhs, Purchase& rhs);

		// Non-Member Overload Function Less Than Operator (friend of the class)
		friend bool operator<(Purchase &lhs, Purchase& rhs);

		// Non-Member Overload Function Greater Than Operator (friend of the class)
		friend bool operator>(Purchase &lhs, Purchase& rhs);
};

// Non-Member Overload Functions
ostream& operator<<(ostream& out, const Purchase& rhs);
istream& operator>>(istream& in, const Purchase& rhs);
bool operator==(Purchase &lhs, Purchase& rhs);
bool operator<(Purchase &lhs, Purchase& rhs);
bool operator>(Purchase &lhs, Purchase& rhs);


#endif
