//***************************************************************************
//File: PurchaseList.cpp
//
//Purpose: Functions for the class PurhcaseList.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#include "PurchaseList.h"

//***************************************************************************
//Function: PurchaseList()
//
//Purpose: Sets member variables to default values.
//
//Big-O runtime cost: O(1)
//			   	   
//Update Information
//------------------
//
//***************************************************************************

PurchaseList::PurchaseList()
{
	m_listLength = 0; // Number of Nodes
	m_startOfList = NULL; // List is empty
}

//***************************************************************************
//Function: PurchaseList(const PurchaseList& otherList)
//
//Purpose: Creates a list that is a DEEP COPY of the list that is passed in.
//
//Big-O runtime cost: O(n)
//			   	   
//Update Information
//------------------
//
//***************************************************************************

PurchaseList::PurchaseList(const PurchaseList& otherList) // O(n)
{
	// Current objects Number of Nodes
	m_listLength = 0;

	// Current object list is empty
	m_startOfList = NULL;

	// Check if the other list is empty
	if (otherList.m_startOfList != NULL)
	{
		// Create a new node to scan through the other list
		PurchaseListNode * scanNode;

		// Point to the start of the other list
		scanNode = otherList.m_startOfList;

		// Make a deep copy until it reaches the end
		do
		{
			// Insert data in the current object's list
			Add(scanNode->m_purchase);

			// Go to the next node
			scanNode = scanNode->m_nextNode;

		} while (scanNode != NULL);// Check if at the end of the list
	}
	else if (otherList.m_startOfList == NULL)
	{
		cout << "\nNothing to copy the other list is empty. @ Copy Constructor" << endl;
	}
}

//***************************************************************************
//Function: ~PurchaseList()
//
//Purpose: Clears the list and releases dynamically allocated memory back to
// the system. 
//
//Big-O runtime cost: O(n)
//	
//Update Information
//------------------
//
//***************************************************************************

PurchaseList::~PurchaseList()
{
	cout << "\nAt destructor, going to clear function @ destructor ~PurchaseList() : \n";
	Clear();
}

//***************************************************************************
//Function: Operator=(PurchaseList& rhs)
//
//Purpose: To make two purchase list objects equal to eachother. Performs
//	a deep copy.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

const PurchaseList& PurchaseList::operator=(PurchaseList& rhs)
{
	cout << "\n\nClearing @ function operator= : \n\n";
	Clear();
	cout << "\nNow making deep copy of rhs @ function operator= : \n";
	Add(rhs);
	cout << "\n\nDeep copy attempt completed. @ function operator= \n\n";

	return *this;
}

//***************************************************************************
//Function: Clear()
//
//Purpose: Clears the current list and releases memory.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseList::Clear()
{
	// nodeCrusher will delete all nodes at the start till the start of the list is NULL
	PurchaseListNode * nodeCrusher;

	// Check if the list is empty
	if (m_startOfList != NULL)
	{
		// Not empty so start deleting
		do
		{
			// nodeCrusher points to the start of the list
			nodeCrusher = m_startOfList;

			// Start of the list points to the next node
			m_startOfList = m_startOfList->m_nextNode;

			// Delete the starting node
			delete nodeCrusher;

		} while (m_startOfList != NULL); // Check if at the end of the list

		// Set the length of the list to 0
		m_listLength = 0;
	}
	else
	{
		cout << "\nNothing to clear because the list is already empty. @ function Clear()\n\n";
	}
}

//***************************************************************************
//Function: Length() const
//
//Purpose: Returns the number of items in the current list.
//
//Big-O runtime cost: O(1)
//		   
//Update Information
//------------------
//
//***************************************************************************

int PurchaseList::Length() const
{
	return m_listLength;
}

//***************************************************************************
//Function: Add(const Purchase p)
//
//Purpose: Inserts new data into the list.
//
//Big-O runtime cost: O(1)
//			   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseList::Add(const Purchase p)
{
	// Create a new node and allocate memory for it - newNode variable is temporary
	PurchaseListNode * newNode = new PurchaseListNode;

	// Store the purchase data inside the node
	newNode->m_purchase = p;

	// Link the node
	if (m_startOfList != NULL) // If the list already started
	{
		// Connect the next node to the new node
		newNode->m_nextNode = m_startOfList;

		// And make the start of the list the new node
		m_startOfList = newNode;
	}
	// If the list hasn't started the make the node the last node
	else if (m_startOfList == NULL)
	{
		// Make the new node the start of the list
		m_startOfList = newNode;

		// Make next node the last node
		m_startOfList->m_nextNode = NULL;
	}

	// The length of the list will increase by one everytime a new purchase is added.
	m_listLength++;

	//***********************************************************************
	// The variable newNode goes out of scope. Don't delete newNode because 
	// that will delete the node holding the data in the heap memory. The
	// nodes allocated memory will be connected via linked list implementation
	// and can be deleted (released) in other methods by visiting that node. 
	// (Delete, ~Destructor, Clear)
	//***********************************************************************
}

//***************************************************************************
//Function: Add(const PurchaseList& otherList)
//
//Purpose: Appends data from a different purchase list object to list into 
// the current purchase list object.
//
//Big-O runtime cost: O(n)
//		   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseList::Add(const PurchaseList& otherList)
{
	// Check if the other list is empty
	if (otherList.m_startOfList != NULL)
	{
		// Create a new node to scan through the other list
		PurchaseListNode * scanNode;

		// Point to the start of the other list
		scanNode = otherList.m_startOfList;

		// Make a deep copy of the other list until it reaches the end
		do
		{
			Add(scanNode->m_purchase); // Insert data in the current object's list
			scanNode = scanNode->m_nextNode; // Go to the next node
		} while (scanNode != NULL);// Check if at the end of the list
	}
	// Check if the other list is empty
	else if (otherList.m_startOfList == NULL)
	{
		cout << "\nNothing to copy the other list is empty. @ function Add(otherlist)" << endl;
	}
}

//***************************************************************************
//Function: FindByItemName(string itemName, Purchase &result) const
//
//Purpose: Checks if the item name is in the list.
//
//Big-O runtime cost: O(n)
//		   
//Update Information
//------------------
//
//***************************************************************************

bool PurchaseList::FindByItemName(string itemName, Purchase &result) const
{
	if (m_startOfList != NULL)
	{
		PurchaseListNode * nodeFind; // Points at node to be checked

		nodeFind = m_startOfList;

		while (nodeFind != NULL)
		{
			if (nodeFind->m_purchase.getItemName() == itemName)
			{
				//***********************************************************
				// Assign purchase object with matching item name to object
				// that was passed into the function.
				//***********************************************************
				result = nodeFind->m_purchase;

				cout << "\nItem Found.";
				cout << "\nTrue(1) or False (0): ";
				return true; // Function will end
			}
			else if (nodeFind->m_nextNode == NULL)
			{
				// Let the user know that the item name was not found
				cout << "\nItem Name not found. No result.\n";
				cout << "\nTrue (1) or False (0): ";

				return false; // Function will end
			}

			// Go to the next node
			nodeFind = nodeFind->m_nextNode; // If nodeFind is set to NULL, loop will end
		}
	}
	else if (m_startOfList == NULL)
	{
		// Tell the user that the list is empty
		cout << "\nThe list is empty.";
		cout << "\nTrue (1) or False (0): ";
		return false; // Function will end
	}
}

//***************************************************************************
//Function: Delete(string itemName)
//
//Purpose: To delete the node that contains the purchase with the matching
//	item name.
//
//Big-O runtime cost: O(n)
//		   
//Update Information
//------------------
//
//***************************************************************************

void PurchaseList::Delete(string itemName)
{
	// nodeFind points at node to be checked and, if found, delete the node
	PurchaseListNode * nodeFind;

	// nodeFollower points at node behind nodeFind and, if a node is deleted, re-links nodes
	PurchaseListNode * nodeFollower;

	// Check if there is a list
	if (m_startOfList != NULL)
	{
		// Check if the item is at the start of the list
		if (m_startOfList->m_purchase.getItemName() == itemName)
		{
			// Point to where the start of the list is pointing to
			nodeFind = m_startOfList;

			// Change the start of the list to the next node
			m_startOfList = m_startOfList->m_nextNode; // Start of the list moved to next node

			// Delete the "old" front of the list
			delete nodeFind;
			nodeFind = NULL;

			// Decrement the length
			m_listLength--;
		}
		// If not at the start than search for an item with the same name in the list
		else if (m_startOfList->m_purchase.getItemName() != itemName)
		{
			// Since m_startOfList was checked already start checking at the nextNode
			nodeFind = m_startOfList->m_nextNode;

			// Start following behind nodeFind in case a node needs to be deleted
			nodeFollower = m_startOfList;

			// Start checking and searching through the list
			while (nodeFind != NULL)
			{
				// Check if the itemname is at the node that nodeFind is pointing to
				if (nodeFind->m_purchase.getItemName() == itemName)
				{
					// Check if current node is the last node on the list
					if (nodeFind->m_nextNode == NULL)
					{
						//**********************************************************
						// Set the nextNode pointer behind the last node to NULL.
						// In other words, make it the last node - because the last
						// node had the matching itemName and has to be deleted.
						//**********************************************************
						nodeFollower->m_nextNode = NULL;

						// Delete the node with the matching itemName
						delete nodeFind;

						// Set nodeFind to NULL so that the loop can end
						nodeFind = NULL;
					}
					// If not the last node then link surrounding nodes
					else if (nodeFind->m_nextNode != NULL)
					{
						//**********************************************************
						// Link the node that is behind the node that is going to be 
						// deleted to the node in front of the node that is going to
						// be deleted.
						//**********************************************************

						// Linking
						nodeFollower->m_nextNode = nodeFind->m_nextNode;

						// Delete the node with matching item name
						delete nodeFind;

						// Set nodeFind to NULL so that the loop can end
						nodeFind = NULL;
					}

					// Decrement the length
					m_listLength--;
				}
				// Check if nodeFind is the last node
				else if (nodeFind->m_nextNode == NULL)
				{
					// Let the user know that the item name was not found
					cout << "\nItem Name not found. Did not delete anything. @ function Delete()\n";
				}

				if (nodeFind != NULL)
				{
					// Follow nodeFind before it hops to the next node
					nodeFollower = nodeFind;

					// Go to the next node
					nodeFind = nodeFind->m_nextNode; // If nodeFind is set to NULL, loop will end
				}
			}

		}
	}
	else if (m_startOfList == NULL)
	{
		cout << "\nThe list is empty. There is nothing that can be deleted. @ function Delete\n";
	}
}

//***************************************************************************
//Function: operator<<(ostream& os, const PurchaseList& rhs)
//
//Purpose: Prints all of tha values of the linked-list in the Purchase List 
//	Object.
//
//Big-O runtime cost: O(n)
//			   
//Update Information
//------------------
//
//***************************************************************************

ostream& operator<<(ostream& os, const PurchaseList& rhs)
{
	PurchaseListNode * nodeHopper; // Go through each node to help retrieve data

	// Title to be above list of purchases
	os << "List of all Purchases" << endl;
	os << "---------------------" << endl;
	os << "---------------------" << endl << endl;;

	// Check if there is a list
	if (rhs.m_startOfList != NULL)
	{
		// If there is a list then start printing data
		nodeHopper = rhs.m_startOfList;
		while (nodeHopper != NULL)
		{
			os << nodeHopper->m_purchase;
			nodeHopper = nodeHopper->m_nextNode;
		}
	}
	// If the list is empty let the user know
	else if (rhs.m_startOfList == NULL)
	{
		// Tell the user that the list was empty
		os << "\nThe list was empty. @ function operator<< ";
	}

	return os;
}

//***************************************************************************
//Function: operator>>(istream& is, PurchaseList& rhs)
//
//Purpose: To insert data from a file to a Purchase List object.
//
//Big-O runtime cost: O(n).
//			   
//Update Information
//------------------
//
//***************************************************************************

istream& operator>>(istream& is, PurchaseList& rhs)
{
	// Clear the current instance because a different collection of data will be stored in current instance "different book"
	rhs.Clear();

	// Create a temporary purchase object
	Purchase tempPurchaseObject = Purchase(); // Helps store purchase data from file

	// Store data from file to the purchase object
	while (is >> tempPurchaseObject)
	{


		// Add purchase data from purchase object (that was from the file) to the purchase list
		rhs.Add(tempPurchaseObject);
	}

	return is;
}
