//***************************************************************************
//File: PurchaseStack.h
//
//Purpose: Class Blueprint for PurchaseStack. This class implements a stack 
//	array-based list.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#ifndef PURCHASESTACK_H
#define PURCHASESTACK_H

#include "Purchase.h"
#include <iostream>
#include <string>
using namespace std;

class PurchaseStack
{
private:
	int m_maxP; // Array size (maximum purchases that can be stored
	int m_top; // The index in which the first purchaes resides
	Purchase *m_purchase;

public:
	// Constructors & Destructors
	PurchaseStack();
	PurchaseStack(int max);
	PurchaseStack(const PurchaseStack& rhs); // Copy Constructor
	~PurchaseStack();

	// Observers
	int Size();
	int MaxStorage();
	bool Top(Purchase &returnedPurchase);
	bool IsEmpty();
	bool IsFull();

	// Transformers
	bool Push(Purchase p);
	bool Pop();
	void Clear();

	// Overload Function Assignment Operator
	PurchaseStack& operator=(const PurchaseStack& rhs);

	// Non-Member Overload Function Insertion Operator (friend of the class)
	friend ostream& operator<<(ostream& os, const PurchaseStack& rhs);
};

// Non-Member Overload Function Insertion Operator (friend of the class)
ostream& operator<<(ostream& os, const PurchaseStack& rhs);

#endif
