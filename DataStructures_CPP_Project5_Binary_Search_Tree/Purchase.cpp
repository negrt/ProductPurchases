//***************************************************************************
//File: Purchase.cpp
//
//Purpose: Function definitions for the class Purchase.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All member variables were changed to pointers. All functions
// below were updated to reflect those changes. Added a desturctor. Added a 
// non-member overload function for operator >> "greater than, greater than".
//
//Name: Timothy Negron
//Date: 11/8/2018
//Description: Added a non-member overload for the equality operator. Returns
// true if the values of the name member variables are equal and false
// otherwise.
//
//Name: Timothy Negron
//Date: 12/7/2018
//Description: Added a non-member overload for the > "greater than" and < 
// "less than" operators.
//
//***************************************************************************

#include "Purchase.h"

//***************************************************************************
//Function: Purchase::Purchase()
//
//Purpose: Purchase class constructor. To allocate heap memory for pointer
// data types and intialize stock values.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
// to a pointer type. This default constructor has been updated to
// refelct those changes.
//
//***************************************************************************

Purchase::Purchase()
{
	//*******************************************
	// Note: Must call new to allocate heap 
	// memory for pointer data types.
	//*******************************************
	m_itemName = new string;
	m_itemPrice = new double;
	m_quantity = new double;

	*m_itemName = "No item name.";
	*m_quantity = 0.0;
	*m_itemPrice = 0.0;
}

//***************************************************************************
//Function: Purchase::~Purchase()
//
//Purpose: Purchase class destructor. To release heap memory back to the
// system.
//		   
//Update Information
//------------------
//
//***************************************************************************

Purchase::~Purchase()
{
	//***************************************************
	// Note: Must delete pointer types in destructor to 
	// release memory from the heap - give it back to the 
	// system. Not doing so would cause a memory leak and 
	// may crash the program. New called in constructor.	
	//***************************************************
	delete m_itemPrice;
	delete m_quantity;
	delete m_itemName;
}

//***************************************************************************
//Function: Purchase::Purchase(string itemName, double quantity, 
//							double itemPrice)
//
//Purpose: Purchase class overload constructor. Accepts three parameters.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variable were changed to a pointer 
// type. This constructor has been updated to refelct those changes. All 
// member variables in this function were changed so that they can 
// dereference the variables and store the passed in values in the allocated 
// heap memory.
//
//***************************************************************************

Purchase::Purchase(string itemName, double quantity, double itemPrice)
{
	// Call new to allocate heap memory
	m_itemName = new string;
	m_quantity = new double;
	m_itemPrice = new double;

	*m_itemName = itemName; // Dereference to initialize properly
	*m_quantity = quantity;
	*m_itemPrice = itemPrice;
}

//***************************************************************************
//Function: Purchase::Purchase(const Purchase& rhs)
//
//Purpose: Purchase copy constructor.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/14/2018
//Description: All Purchase class member variables were changed
// to a pointer type. The Purchase copy constructor has been updated to
// reflect those changes. All member variables in this function
// were changed so that they can dereference the variables and store the
// passed in values in the allocated heap memory.
//
//***************************************************************************

Purchase::Purchase(const Purchase& rhs)
{
	// Call new to allocate heap memory
	m_itemName = new string;
	m_quantity = new double;
	m_itemPrice = new double;

	*m_itemName = *rhs.m_itemName;
	*m_quantity = *rhs.m_quantity;
	*m_itemPrice = *rhs.m_itemPrice;
}

//***************************************************************************
//Function: Purchase::getItemName()
//
//Purpose: Returns the data stored inside the member variable of m_itemName.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
// to a pointer type. The getItemName function has been updated to reflect 
// those changes. The m_itemName member variable is dereferenced to ensure 
// that the value inside the heap is returned.
//
//***************************************************************************

string Purchase::getItemName()
{
	return *m_itemName;
}

//***************************************************************************
//Function: Purchase::setItemName()
//
//Purpose: Assigns the data for the variable m_itemName to the value of the
//	parameter passed in the function.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
// to a pointer type. The setItemName function has been updated to reflect 
// those changes. The m_itemName member variable is now dereferenced to 
// ensure that the value passed in is stored in the allocated heap memory.
//
//***************************************************************************

void Purchase::setItemName(string itemName)
{
	*m_itemName = itemName;
}

//***************************************************************************
//Function: Purchase::getQuantity()
//
//Purpose: Returns the data stored inside the member variable of m_quantity.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
// to a pointer type. The getQuantity function has been updated to reflect 
// those changes. The m_quantity member variable is now dereferenced to 
// ensure that the value inside the heap is returned.
//
//***************************************************************************

double Purchase::getQuantity()
{
	return *m_quantity;
}

//***************************************************************************
//Function: Purchase::setQuantity()
//
//Purpose: Assigns the data for the variable m_quantity to the value of the
// parameter passed in the function.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
// to a pointer type. The setQuantity function has been updated to reflect 
// those changes. The m_quantity member variable is now dereferenced to 
// ensure that the value passed in is stored in the allocated heap memory.
//
//***************************************************************************

void Purchase::setQuantity(double quantity)
{
	*m_quantity = quantity;
}

//***************************************************************************
//Function: Purchase::getItemPrice()
//
//Purpose: Returns the data stored inside the member variable of m_itemPrice.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
//	to a pointer type. The getItemPrice function has been updated to reflect 
//	those changes. The m_itemPrice member variable is now dereferenced to 
//	ensure that the value in the heap is returned.
//
//***************************************************************************

double Purchase::getItemPrice()
{
	return *m_itemPrice;
}

//***************************************************************************
//Function: Purchase::setItemPrice();
//
//Purpose: Assigns the data for the variable m_itemPrice to the value of the
//	parameter passed in the function.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
//	to a pointer type. The setItemPrice function has been updated to reflect 
//	those changes. The m_itemPrice member variable is now dereferenced to 
//	ensure that the value passed in is stored in the allocated memory.
//
//***************************************************************************

void Purchase::setItemPrice(double itemPrice)
{
	*m_itemPrice = itemPrice;
}

//***************************************************************************
//Function: Purchase::Cost()
//
//Purpose: Multiplies the item price and the quantity and returns the value.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
//	to a pointer type. The Cost function has been updated to reflect those 
//	changes. All member variables are now dereferenced to ensure that the 
//	value inside the heap is multiplied.
//
//***************************************************************************

double Purchase::Cost()
{
	// ((Get value in heap for itemprice) multiply (Get value in heap for m_quantity))
	return ((*m_itemPrice) * (*m_quantity));
}

//***************************************************************************
//Function: Purchase::Purchase& operator=(const Purchase& rhs)
//
//Purpose: This allows the user the ability to use the assignment operator
// to make two purchase objects equal to eachother. In this function all
// member variables will be assigned the passed in values from the object.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
// to a pointer type. The overloaded operator assignment function has been 
// updated to reflect those changes. All member variables are now
// dereferenced to help ensure that the proper value is stored inside the
// heap memory. All member variables from the object being passed in are 
// also dereferencing to ensure that the value inside the heap is the value
// that is initialized.
//
//***************************************************************************

const Purchase& Purchase::operator=(const Purchase& rhs)
{
	*m_itemName = *rhs.m_itemName;
	*m_quantity = *rhs.m_quantity;
	*m_itemPrice = *rhs.m_itemPrice;

	return *this;
}

//***************************************************************************
//Function: friend ostream& operator<<(ostream& out, const Purchase& rhs)
//
//Purpose: Allows the user the ability to see the values of each attribute by
// simply using the outstream operator alone with a dereferenced class 
// variable name.
//		   
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 10/3/2018
//Description: All Purchase class member variables data types were changed
// to a pointer type. The overloaded operator insertion function has been 
// updated to reflect those changes. All member variables in this function
// were changed so that they can dereference the member variable to show 
// the value stored in heap memory (where it's pointing).
//
//***************************************************************************

ostream& operator<<(ostream& os, const Purchase& rhs)
{
	os << "Purchase" << endl;
	os << "--------" << endl;
	os << "Item Name: " << *rhs.m_itemName << endl;
	os << "Item Price: " << *rhs.m_itemPrice << endl;
	os << "Quantity: " << *rhs.m_quantity << endl << endl;

	return os;
}

//***************************************************************************
//Function: friend ostream& operator<<(ostream& out, const Purchase& rhs)
//
//Purpose: To insert data from a file to a purchase object.
//		   
//Update Information
//------------------
//
//***************************************************************************

istream& operator>>(istream& is, const Purchase& rhs)
{
	is >> *rhs.m_itemName;
	is >> *rhs.m_itemPrice;
	is >> *rhs.m_quantity;

	return is;
}

//***************************************************************************
//Function: friend bool& operator==(Purchase &lhs, Purchase& rhs)
//
//Purpose: Checks if the name of each purchase is equal to each other.
//		   
//Update Information
//------------------
//
//***************************************************************************

bool operator==(Purchase &lhs, Purchase& rhs)
{
	return (lhs.getItemName() == rhs.getItemName());
}

//***************************************************************************
//Function: operator<(Purchase & lhs, Purchase & rhs)
//
//Purpose: Checks if the name of the purchase on the left hand side is less 
// than the purchase on the right hand side.
//		   
//Update Information
//------------------
//
//***************************************************************************

bool operator<(Purchase & lhs, Purchase & rhs)
{
	return (lhs.getItemName() < rhs.getItemName());
}

//***************************************************************************
//Function: operator>(Purchase & lhs, Purchase & rhs)
//
//Purpose: Checks if the name of the purchase on the left hand side is greater 
// than the purchase on the right hand side.
//		   
//Update Information
//------------------
//
//***************************************************************************

bool operator>(Purchase & lhs, Purchase & rhs)
{
	return (lhs.getItemName() > rhs.getItemName());
}
