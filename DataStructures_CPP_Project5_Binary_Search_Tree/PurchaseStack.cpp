//***************************************************************************
//File: PurchaseStack.cpp
//
//Purpose: Functions for the class PurchaseStack. Last in First out stack
//	implementation.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#include "PurchaseStack.h"

//***************************************************************************
//Function: PurchaseStack()
//
//Purpose: To initialize objects member variables.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseStack::PurchaseStack()
{
	m_maxP = 10;
	m_top = -1;
	m_purchase = new Purchase[m_maxP]; // A static array that stores ptr purchases
}

//***************************************************************************
//Function: PurchaseStack(int max)
//
//Purpose: To initialize objects member variable with paramiterized with
//	desired max storage.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseStack::PurchaseStack(int max)
{
	m_maxP = max;
	m_top = -1;
	m_purchase = new Purchase[m_maxP];
}

//***************************************************************************
//Function: PurchaseStack(const PurchaseStack& rhs)
//
//Purpose: Constructs an object that makes a deep copy of other referenced 
// parameterized PurchaseStack type obj.
//	
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseStack::PurchaseStack(const PurchaseStack& rhs)
{
	m_purchase = NULL;

	*this = rhs;
}

//***************************************************************************
//Function: ~PurchaseStack()
//
//Purpose: Releases dynamic memory when node is no longer in use.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseStack::~PurchaseStack()
{
	delete[] m_purchase;
}

//***************************************************************************
//Function: Clear()
//
//Purpose: To remove all purchases from the list.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseStack::Clear()
{
	m_top = -1;
}

//***************************************************************************
//Function: Size()
//
//Purpose: To check the current size of the list.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

int PurchaseStack::Size()
{
	return m_top + 1;
}

//***************************************************************************
//Function: MaxStorage()
//
//Purpose: To check the max storage size.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

int PurchaseStack::MaxStorage()
{
	return m_maxP;
}
//***************************************************************************
//Function: Push(Purchase p)
//
//Purpose: Adds a purchase to the list.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseStack::Push(Purchase p)
{
	if (!IsFull())
	{
		m_top++;
		m_purchase[m_top] = p;
		return true;
	}

	return false;
}
//***************************************************************************
//Function: Pop()
//
//Purpose: Removes Purchase from the list.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseStack::Pop()
{
	if (!IsEmpty())
	{
		m_top--;
		return true;
	}
	return false;
}

//***************************************************************************
//Function: Top(Purchase &returnedPurchase)
//
//Purpose: To get the top element without removing the data from it. Returns
//	true if successful, false if not.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseStack::Top(Purchase &returnedPurchase)
{
	if (!IsEmpty())
	{
		returnedPurchase = m_purchase[m_top];
		return true;
	}
	return false;
}

//***************************************************************************
//Function: operator=(PurchaseStack& rhs)
//
//Purpose: Makes a deep copy of rhs.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseStack& PurchaseStack::operator=(const PurchaseStack& rhs)
{
	if (m_purchase != NULL)
	{
		delete[] m_purchase; // Must delete for resizing

	}

	Clear();
	m_maxP = rhs.m_maxP;
	m_purchase = new Purchase[m_maxP];

	for (int i = 0; i <= rhs.m_top; i++) // Copy everything
	{
		Push(rhs.m_purchase[i]); // Perform deep copy
	}

	return *this;
}

//***************************************************************************
//Function: operator<<(ostream& os, const PurchaseStack& rhs)
//
//Purpose: To print all purchase data in the stack list object.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

ostream& operator<<(ostream& os, const PurchaseStack& rhs)
{
	if (rhs.m_top == -1)
	{
		cout << "\nThe list is empty nothing to print.\n";
		//throw
	}
	else
	{
		for (int i = 0; i <= rhs.m_top; i++)
		{
			os << rhs.m_purchase[i];
		}
	}

	return os;
}

//***************************************************************************
//Function: IsEmpty()
//
//Purpose: To verify if the stack list is empty or not. Helps prevent stack
//	underflow.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************


bool PurchaseStack::IsEmpty()
{
	return (m_top == -1); // If m_top is empty index will be -1
}

//***************************************************************************
//Function: IsFull()
//
//Purpose: To verify if the stack list is full or not. Helps prevent stack 
//	overflow.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseStack::IsFull()
{
	return (m_top == (m_maxP - 1)); // subtract 1 because starting index is 0 and if empty index will be -1
}
