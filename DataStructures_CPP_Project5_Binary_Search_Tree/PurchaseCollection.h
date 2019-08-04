//***************************************************************************
//File: PurchaseCollection.h
//
//Purpose: Class Blueprint for PurchaseCollection. This class 
//	stores an array of purchase. This class inherits from
//	the Purchase class.
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
//Description: Changed static const int SIZEOFARRAY to int m_SIZEOF ARRAY.
// The class has been changed to work with pointers. A copy constructor was
// added. A resize function was added. A overloaded assignment operator was
// added. A overloaded outsream operator was added. A clone function was
// added. Member variable m_purchase was changed to a pointer. This class
// was also moved to a static library.
//
//***************************************************************************

#ifndef PURCHASECOLLECTION_H
#define PURCHASECOLLECTION_H


#include "Purchase.h"
#include <string>
using namespace std;

class PurchaseCollection : public Purchase
{
private:
	//*******************************************************************
	// Each m_purchase array index will have an address that is pointing
	// to an array of purchase objects.
	//*******************************************************************
	Purchase * m_purchase;

	// The number of purchases in the collection (the array size)
	int m_SIZEOFARRAY;

public:
	// Constructors & Destructor
	PurchaseCollection(); // Default constructor
	PurchaseCollection(int elementSIZE); // User chooses size of m_purchase
	PurchaseCollection(const PurchaseCollection& rhs); // Copy Constructor
	~PurchaseCollection(); // Destructor for m_purchase Purchase pointer type variable

	// Get & Set
	void Set(int index, Purchase p); // Assign
	Purchase Get(int index); // Returns data in Purchase object

	// Functions
	int ItemPriceCount(double lowerBound, double upperBound);
	Purchase MostExpensivePurchase();
	bool FindByItemName(string itemName, Purchase &p);
	double TotalCost();
	int Size();
	void Initialize();
	string GetAuthor(); // Display author name
	void Resize(int newSize); // Resize the Array
	PurchaseCollection *Clone(); // Copy a purchase collection object that is calling this function

	// Member Overload Function Assignment Operator
	const PurchaseCollection& operator=(const PurchaseCollection& rhs);

	// Non-Member Overload Function Insertion Operator (friend of the class)
	friend ostream& operator<<(ostream& os, const PurchaseCollection& rhs);
};

// Non-Member
ostream& operator<<(ostream& os, const PurchaseCollection& rhs);

#endif
