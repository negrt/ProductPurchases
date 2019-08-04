//***************************************************************************
//File: PurchaseCollection.cpp
//
//Purpose: Functions for the class PurhcaseCollection.
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
//Description: Purchase member variable was changed to pointers. All
//	functions have been updated to reflect those changes. A copy constructor was
//	added. A resize function was added. A overloaded assignment operator was
//	added. A overloaded outsream operator was added. A clone function was
//	added. This class was also moved to a static library.
//
//***************************************************************************

#include "PurchaseCollection.h"

//***************************************************************************
//Function: PurchaseCollection()
//
//Purpose: PurchaseCollection class constructor.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: m_SIZEOFARRAY is now initialized in this Constructor.
//	The keyword new is called in this constructor to allocate memory for
//	member variable m_purchase which is a Purchase object pointer type 
//	variable.
//
//***************************************************************************

PurchaseCollection::PurchaseCollection()
{
	m_SIZEOFARRAY = 5;
	m_purchase = new Purchase[m_SIZEOFARRAY]; // Could call initialize here
}

//***************************************************************************
//Function: PurchaseCollection(int elementSIZE)
//
//Purpose: PurchaseCollection class constructor with index option parameter.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: m_SIZEOFARRAY is now initialized in this Constructor.
//	The keyword new is called in this constructor to allocate memory for
//	member variable m_purchase which is a Purchase object pointer type 
//	variable.
//
//***************************************************************************

PurchaseCollection::PurchaseCollection(int elementSIZE)
{
	// Must assign element value to array size member variable
	m_SIZEOFARRAY = elementSIZE;
	m_purchase = new Purchase[m_SIZEOFARRAY]; // Could call initialize here
}

//***************************************************************************
//Function: PurchaseCollection(const PurchaseCollection& pc)
//
//Purpose: PurchaseCollection class copy constructor that performs a deep
//	copy of a PurchaseCollection object.
//		   
//Update Information
//------------------
//
//***************************************************************************

PurchaseCollection::PurchaseCollection(const PurchaseCollection& rhs)
{
	// Assign size of array int to pc rhs object size of array member variable
	m_SIZEOFARRAY = rhs.m_SIZEOFARRAY;

	// Allocate memory for Purchase* member variable and give it its own address
	m_purchase = new Purchase[m_SIZEOFARRAY]; // Could call initialize here

	// Perform deep copy of array of purchase objects
	for (int i = 0; i < m_SIZEOFARRAY; i++)
	{
		m_purchase[i].setItemName(rhs.m_purchase[i].getItemName());
		m_purchase[i].setItemPrice(rhs.m_purchase[i].getItemPrice());
		m_purchase[i].setQuantity(rhs.m_purchase[i].getQuantity());
	}
}

//***************************************************************************
//Function: ~PurchaseCollection()
//
//Purpose: PurchaseCollection class destructor.
//		   
//Update Information
//------------------
//
//***************************************************************************

PurchaseCollection::~PurchaseCollection()
{
	delete[] m_purchase;
}

//***************************************************************************
//Function: Set(int index, Purchase p)
//
//Purpose: This function sets the value of the purchase index to the
//	parameter integer index value.
//		   
//Update Information
//------------------
// 
//Name: Timothy Negron
//Date: 10/14/2018
//Description:
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: Updated to correspond with the changes made to the purchase
//	pointer member variable.
//
//***************************************************************************

void PurchaseCollection::Set(int index, Purchase p)
{
	Purchase temp = Purchase(p); // Needed for deep copy

	if (index >= 0 && index < m_SIZEOFARRAY) // Check to see if index is valid
	{
		//*******************************************************************
		// If the statement above is true, then the purchase object will be 
		// stored in the specified array indx of a Purchase object that is 
		// within a purchase collection object that is calling this function.
		//*******************************************************************
		m_purchase[index].setItemName(temp.getItemName());
		m_purchase[index].setItemPrice(temp.getItemPrice());
		m_purchase[index].setQuantity(temp.getQuantity());
	}
	else
	{
		cout << "\nInvalid Index Entered: " << index << endl;
	}
}

//***************************************************************************
//Function: Get(int index)
//
//Purpose: Returns the purchase from the purchase array with the specified
//	parameter, index, from the purchase collection object.
//		   
//Update Information
//------------------
//
//***************************************************************************

Purchase PurchaseCollection::Get(int index)
{
	return m_purchase[index];
}

//***************************************************************************
//Function: ItemPriceCount(double lowerBound, double upperBound)
//
//Purpose: This function checks if purchased item price falls within the
//	specified range. The range is passed into the function. 
//	The function iterates through each array of purchase, using 
//	a for loop, and checks if the member variable, itemPrice 
//	of the purchase object, is within the range. It returns 
//	a count of how many item prices that fall within the range.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: Changed static const int SIZEOFARRAY to int m_SIZEOFARRAY.
//
//***************************************************************************

int PurchaseCollection::ItemPriceCount(double lowerBound, double upperBound)
{
	int counter = 0;

	//***********************************************************************
	// This for loop iterates through the purchase array and checks if the
	// itemPrice attribute, of the purchase object, is within the specified
	// lowerbound and upperbound range for indexs 0 - 9.
	//***********************************************************************
	for (int i = 0; i < m_SIZEOFARRAY; i++)
	{
		if (m_purchase[i].getItemPrice() >= lowerBound &&
			m_purchase[i].getItemPrice() <= upperBound)
		{
			counter++;
		}
	}

	return counter;
}

//***************************************************************************
//Function: MostExpensivePurchase()
//
//Purpose:  Returns the most expensive purchase by searching through the
//	all purchase objects in the collection and saving the index in a variable
//	to eventually return the object.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: Changed static const int SIZEOFARRAY to int m_SIZEOFARRAY.
//
//***************************************************************************

Purchase PurchaseCollection::MostExpensivePurchase()
{
	int i = 0; // i for iteration
	int MEPindex = 0; // Most Expensive Purchase Index

	//***********************************************************************
	// Check the cost of each purchase in the collection
	// and keep track of which purchase has the highest cost.
	//***********************************************************************
	while (i < m_SIZEOFARRAY)
	{
		//*******************************************************************
		// If the cost of the current purchase object is less than 
		// the next iteration, it will assign the int variable 
		// MEPindex to the new iteration number.
		//*******************************************************************
		if (m_purchase[MEPindex].Cost() < m_purchase[i].Cost())
		{
			MEPindex = i;
		}

		i++;
	}

	return m_purchase[MEPindex];
}

//***************************************************************************
//Function: FindByItemName(string itemName, Purchase &p)
//
//Purpose: Searches for the item name. Returns true (1) if the name is in the
//	array - and false (0) otherwise. If the item name is in the array,
//	the purchase object that is passed into the function gets assigned
//	the address of the purchase object in the purchase collection.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: Changed static const int SIZEOFARRAY to int m_SIZEOFARRAY.
//
//***************************************************************************

bool PurchaseCollection::FindByItemName(string itemName, Purchase &p)
{
	bool b = false;

	//***********************************************************************
	// Search for matching item name by looping through the purchase
	// collection array
	//***********************************************************************
	for (int i = 0; i < m_SIZEOFARRAY; i++)
	{
		if (m_purchase[i].getItemName() == itemName)
		{
			//***************************************************************
			// Assign purchase object with matching item name
			// to object that was passed into the function.
			//***************************************************************
			p = m_purchase[i];

			b = true;

			cout << "Found Item: " << m_purchase[i].getItemName() << endl;

			break;
		}
	}

	cout << "True (1) or False (0): ";

	return b;
}

//***************************************************************************
//Function: TotalCose()
//
//Purpose: Adds the total cost of each purchase in the collection and returns
//	the total amount.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: Changed static const int SIZEOFARRAY to int m_SIZEOFARRAY.
//
//***************************************************************************

double PurchaseCollection::TotalCost()
{
	double total = 0.0;

	// Add cost of every purchase to total
	for (int i = 0; i < m_SIZEOFARRAY; i++)
	{
		total += m_purchase[i].Cost();
	}

	return total;
}

//***************************************************************************
//Function: Size()
//
//Purpose: Returns the size of the array.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: Changed static const int SIZEOFARRAY to int m_SIZEOFARRAY.
//
//***************************************************************************

int PurchaseCollection::Size()
{
	return m_SIZEOFARRAY;
}

//***************************************************************************
//Function: Initialize()
//
//Purpose: Initializes the data of the purchase pointer type object to 
//	default values. The purchase collection object that is calling this
//	function will be affected.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: Changed static const int SIZEOFARRAY to int m_SIZEOFARRAY.
//
//***************************************************************************

void PurchaseCollection::Initialize()
{
	for (int i = 0; i < m_SIZEOFARRAY; i++)
	{
		m_purchase[i].setItemName("No Item Name.");
		m_purchase[i].setQuantity(0.0);
		m_purchase[i].setItemPrice(0.0);
	}
}

//***************************************************************************
//Function: GetAuthor()
//
//Purpose: Returns the Authurs name (Hard coded my own name).
//		   
//Update Information
//------------------
//
//***************************************************************************

string PurchaseCollection::GetAuthor()
{
	string Author = "\nSolution Author: Timothy Negron";
	return Author;
}

//***************************************************************************
//Function: operator=(const PurchaseCollection& rhs)
//
//Purpose: Performs a deep copy of a Purchase Collection object. Make's it
//	easier for the user to make two Purchase Collection objects to be equal
//	to eachother. Defines what it means for two Purchase Collection objects
//	to be equal to eachother.
//		   
//Update Information
//------------------
//
//***************************************************************************


const PurchaseCollection& PurchaseCollection::operator=(const PurchaseCollection& rhs)
{
	//**********************************************************************
	// Must delete m_purchase because it is essential in order to resize the 
	// m_SIZEOFARRAY to ensure that the m_SIZEOFARRAY of the object being 
	// passed in matches with the m_SIZEOFARRAY of the current object. 
	// Therefore, it is essential to release the memory that was storing the
	// previous data back to the system and create a new instance of Purchase 
	// with the new m_SIZEOFARRAY. Not doing so would waste memory and cause
	// a memory  leak.
	//**********************************************************************
	delete[] m_purchase;
	m_SIZEOFARRAY = rhs.m_SIZEOFARRAY;
	m_purchase = new Purchase[m_SIZEOFARRAY]; // Could call initialize here

	// Now make a deep copy
	for (int i = 0; i < m_SIZEOFARRAY; i++)
	{
		m_purchase[i].setItemName(rhs.m_purchase[i].getItemName());
		m_purchase[i].setItemPrice(rhs.m_purchase[i].getItemPrice());
		m_purchase[i].setQuantity(rhs.m_purchase[i].getQuantity());
	}

	return *this;
}


//***************************************************************************
//Function: operator<<(ostream& os, const PurchaseCollection& rhs)
//
//Purpose: Prints all of tha values inside the array of Purchases.
//		   
//Update Information
//------------------
//
//***************************************************************************

ostream& operator<<(ostream& os, const PurchaseCollection& rhs)
{
	for (int i = 0; i < rhs.m_SIZEOFARRAY; i++)
	{
		os << "\nItem Name for Purchase " << i << ": " << rhs.m_purchase[i].getItemName() << endl;
		os << "Item Price for Purchase " << i << ": " << rhs.m_purchase[i].getItemPrice() << endl;
		os << "Quantity for Purchase " << i << ": " << rhs.m_purchase[i].getQuantity() << endl;
	}
	return os;
}

//***************************************************************************
//Function: Resize(int newSize)
//
//Purpose: To resize the array of an existing PurchaseCollection member 
// variable Purchase pointer type object.
//		   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseCollection::Resize(int newSize)
{
	// Create a temporary Purchase array object
	Purchase * temp = new Purchase[m_SIZEOFARRAY];

	// Store the current member purchase obj values inside the temporary purchase obj
	for (int i = 0; i < m_SIZEOFARRAY; i++)
	{
		temp[i].setItemName(m_purchase[i].getItemName());
		temp[i].setItemPrice(m_purchase[i].getItemPrice());
		temp[i].setQuantity(m_purchase[i].getQuantity());
	}

	// Keep a copy of the old size for later use
	int oldSize = m_SIZEOFARRAY;

	// Assign the current objects size member variable to the new size
	m_SIZEOFARRAY = newSize;

	// Delete the old m_purchase pointer type object to release memory
	delete[] m_purchase;

	// Allocate heap memory for current object with new array size
	m_purchase = new Purchase[m_SIZEOFARRAY]; // Resizing // Could call initialize here

	// Copy old data the now RESIZED current member variable
	if (newSize > oldSize)
	{
		for (int i = 0; i < oldSize; i++)
		{
			m_purchase[i].setItemName(temp[i].getItemName());
			m_purchase[i].setItemPrice(temp[i].getItemPrice());
			m_purchase[i].setQuantity(temp[i].getQuantity());
		}
	}
	else if (newSize <= oldSize)
	{
		for (int i = 0; i < m_SIZEOFARRAY; i++)
		{
			m_purchase[i].setItemName(temp[i].getItemName());
			m_purchase[i].setItemPrice(temp[i].getItemPrice());
			m_purchase[i].setQuantity(temp[i].getQuantity());
		}
	}

	// Release the memory used for temp back to the system
	delete[] temp;
}

//***************************************************************************
//Function: Clone()
//
//Purpose: To make a deep copy of the current purchase collection to a new
//	purchase collection pointer. This function will return a purchase
//	collection pointer.
//		   
//Update Information
//------------------
//
//***************************************************************************

PurchaseCollection* PurchaseCollection::Clone()
{
	// *this is the address of the current object (The object calling the function)
	PurchaseCollection *pcClone = new PurchaseCollection(*this);

	return pcClone;
}

