//***************************************************************************
//File: PurchaseList.h
//
//Purpose: To create a purchase list blueprint. This class uses a linked-list
// method to help create a list object.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#ifndef PURCHASELIST_H
#define PURCHASELIST_H  

#include <iostream>
#include <string>
#include "Purchase.h"
#include "PurchaseListNode.h"
using namespace std;

class PurchaseList
{
private:
	int m_listLength; // The length of the list
	PurchaseListNode *m_startOfList; // "Head" of the list

public:
	// Constructors & Destructor
	PurchaseList(); // Default Constructor
	PurchaseList(const PurchaseList& otherList); // Copy Constructor
	~PurchaseList(); // Destructor

	// Member Overload function assignment operator
	const PurchaseList & operator=(PurchaseList& rhs);

	// Other functions
	void Clear();
	int Length() const;
	void Add(const Purchase p);
	void Add(const PurchaseList& otherList);
	bool FindByItemName(string itemName, Purchase &result) const;
	void Delete(string itemName);

	// Non-Member Overload Function Insertion Operator (friend of the class)
	friend ostream& operator<<(ostream& os, const PurchaseList& rhs);

	// Non-Member Overload Function  >> Operator (friend of the class)
	friend istream& operator>>(istream& is, PurchaseList& rhs);
};

// Non-Member
ostream& operator<<(ostream& os, const PurchaseList& rhs);

// Non-Member
istream& operator>>(istream& is, PurchaseList& rhs);

#endif
