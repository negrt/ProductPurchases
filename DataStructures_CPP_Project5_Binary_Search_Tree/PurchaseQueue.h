//***************************************************************************
//File: PurchaseQueue.h
//
//Purpose: Class Blueprint for PurchaseQueue. This class implements a queue
//	linked-list.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#ifndef PURCHASEQUEUE_H
#define PURCHASEQUEUE_H

#include "Purchase.h"
#include "PurchaseListNode.h"
#include <iostream>
#include <string>
using namespace std;

class PurchaseQueue
{
private:
	int m_length; // Keeps track of the length of the list
	PurchaseListNode *m_start; // "Head" of the list
	PurchaseListNode *m_end; // "Tail" of the list

public:
	// Constructors & Destructors
	PurchaseQueue();
	PurchaseQueue(const PurchaseQueue& rhs);
	~PurchaseQueue();

	// Transformers
	void Clear();
	void Enqueue(Purchase p);
	bool Dequeue(Purchase& returnedPurchase);

	// Observers
	bool IsEmpty();
	bool IsFull();
	int Size();

	string FullQueue();
	string EmptyQueue();

	// Member Overload Function Assignment Operator
	PurchaseQueue& operator=(const PurchaseQueue& rhs);

	// Non-Member Overload Function Insertion Operator (friend of the class)
	friend ostream& operator<<(ostream& os, const PurchaseQueue& rhs);

};

// Non-Member 
ostream& operator<<(ostream& os, const PurchaseQueue& rhs);

#endif
