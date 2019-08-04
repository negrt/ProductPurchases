//***************************************************************************
//File: PurchaseStack.cpp
//
//Purpose: Functions for the class PurchaseStack. First in first out queue
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

#include "PurchaseQueue.h"

//***************************************************************************
//Function: PurchaseQueue()
//
//Purpose: Sets member variables to default values to create an empty list.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseQueue::PurchaseQueue()
{
	m_length = 0; // Number of nodes (length of the list)

	m_start = NULL;
	m_end = NULL;
}

//***************************************************************************
//Function: PurchaseQueue(const PurchaseQueue& rhs)
//
//Purpose: To create a new PurchaseQueue object that is a deep copy of the 
//	referenced PurchaseQueue object parameter.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseQueue::PurchaseQueue(const PurchaseQueue& rhs)
{
	m_start = NULL;
	*this = rhs;
}

//***************************************************************************
//Function: ~PurchaseQueue()
//
//Purpose: Releases dynamically allocated memory.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseQueue::~PurchaseQueue()
{
	Clear();
}

//***************************************************************************
//Function: Clear()
//
//Purpose: Releases dynamic memory and clears the list.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseQueue::Clear()
{
	PurchaseListNode *nodeCrusher; // Helps delete nodes

	// Loop till start is NULL
	while (m_start != NULL) // Check if start is NULL
	{
		nodeCrusher = m_start; // Points to where start is pointing to
		m_start = m_start->m_nextNode; // Make start move down the list
		delete nodeCrusher; // Delete the node
	}

	m_end = NULL; // Set end to NULL

	m_length = 0; // Set length to 0, list is empty now
}

//***************************************************************************
//Function: Size()
//
//Purpose: Returns the number of elements/nodes in the queue. The size of the 
//	list.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

int PurchaseQueue::Size()
{
	return m_length;
}

//***************************************************************************
//Function: Enqueue(Purchase p)
//
//Purpose: To add data to the a linked list. Adds new nodes to the end of the 
//	list. First in First out queue implementation.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseQueue::Enqueue(Purchase p)
{
	if (IsFull())
	{
		throw FullQueue(); // If memory unavailable send messages.
	}
	else // Dynamic memory available create a new node
	{
		PurchaseListNode *newNode = new PurchaseListNode;

		newNode->m_purchase = p; // Set values on the new node

		// Set nextNode to NULL because newNode will be placed on the back of the list
		newNode->m_nextNode = NULL;

		// Check if the end is NULL
		if (m_end == NULL)
		{
			// If the end is NULL then the list hasn't started yet
			m_start = newNode;
		}
		else
		{
			// The list has an end already so link the last node to the new node
			m_end->m_nextNode = newNode;
		}

		m_end = newNode; // Now make the end point to the new node

		m_length++; // Increment the length of the list
	}
}

//***************************************************************************
//Function: Dequeue(Purchase& returnedPurchase)
//
//Purpose: To remove purchase list data from queue list. Sets reference to
//	to data inside of starting node. Returns true if list is not empty
//	and false if the list is empty. If true then operation was successful.
//	If false then operation was not successful. First in First out queue
//	implementation.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseQueue::Dequeue(Purchase& returnedPurchase)
{
	if (!IsEmpty()) // IsEmpty returns true if the list is empty
	{
		PurchaseListNode *nodeCrusher; // Helps delete starting node

		nodeCrusher = m_start; // Set value to start to delete after data extracted

		returnedPurchase = m_start->m_purchase; // Get data from starting node

		m_start = m_start->m_nextNode; // Move the start of the line to the next node

		delete nodeCrusher; // Delete the previous starting node

		m_length--; // Decrement the length of the list

		return true;
	}
	else
	{
		return false;
	}

}

//***************************************************************************
//Function: operator=(const PurchaseQueue& rhs)
//
//Purpose: To set the values of the current PurchaseQueue object to the 
//	PurchaseQueue object that is parameterized.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

PurchaseQueue& PurchaseQueue::operator=(const PurchaseQueue& rhs)
{
	Clear();

	PurchaseListNode *scanNode;

	scanNode = rhs.m_start;

	while (scanNode != NULL)
	{
		Enqueue(scanNode->m_purchase);
		scanNode = scanNode->m_nextNode;
	}

	return *this;
}

//***************************************************************************
//Function: operator<<(ostream& os, const PurchaseQueue& rhs)
//
//Purpose: To print all purchase data in the queue list object.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

ostream& operator<<(ostream& os, const PurchaseQueue& rhs)
{
	if (rhs.m_start == NULL)
	{
		cout << "\nThe list is empty nothing to print.\n";
		//throw EmptyQueue();
	}
	else
	{
		PurchaseListNode *nodeHopper; // A temporary variable that will reference nodes on the list

		nodeHopper = rhs.m_start;

		while (nodeHopper != NULL)
		{
			os << nodeHopper->m_purchase;
			nodeHopper = nodeHopper->m_nextNode;
		}
	}

	return os;
}

//***************************************************************************
//Function: IsEmpty()
//
//Purpose: To check if the list is empty. Returns true if empty.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseQueue::IsEmpty()
{
	return (m_start == NULL);
}

//***************************************************************************
//Function: IsFull()
//
//Purpose: To check if the list is full. Returns true if full.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseQueue::IsFull()
{
	PurchaseListNode *newNode;

	// Attempt to allocate dynamic memory
	try
	{
		newNode = new PurchaseListNode;
		delete newNode;

		// If program is able to allocate dynamic memory ram is not full
		return false;
	}
	catch (bad_alloc exception)
	{
		// If program cannot allocate dynamic memory then ram is full
		return true;
	}
}

//***************************************************************************
//Function: FullQueue()
//
//Purpose: To return a message.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

string PurchaseQueue::FullQueue()
{
	return "\nUnable to allocate memory. Unable to queue.\n";
}

//***************************************************************************
//Function: EmptyQueue()
//
//Purpose: To return a message.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

string PurchaseQueue::EmptyQueue()
{
	return "\nThe list is empty. Unable to dequeue.\n";
}
