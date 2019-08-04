//***************************************************************************
//File: PurchaseBST.cpp
//
//Purpose: Functions for the Purchase Binary Search Tree class.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#include "PurchaseBST.h"

//***************************************************************************
//Function: PurchaseBST()
//
//Purpose: To create an empty tree.
//
//Big-O runtime cost: O(1)
//
//***************************************************************************

PurchaseBST::PurchaseBST()
{
	m_root = NULL;
	m_length = 0;
}

//***************************************************************************
//Function: PurchaseBST(const PurchaseBST & rhs)
//
//Purpose: To create a copy of a tree.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

PurchaseBST::PurchaseBST(const PurchaseBST & rhs)
{
	m_root = NULL;
	m_length = 0;

	*this = rhs;
}

//***************************************************************************
//Function: ~PurchaseBST()
//
//Purpose: To empty the binary tree and release dynamically allocated memory.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

PurchaseBST::~PurchaseBST()
{
	Clear();
	cout << "Destructor called.";
} // Break point here to test destructor

//***************************************************************************
//Function: Size()
//
//Purpose: Returns the number of elements/nodes in the tree.
//
//Big-O runtime cost: O(1)
//
//***************************************************************************

int PurchaseBST::Size()
{
	return m_length;
}

//***************************************************************************
//Function: Clear()
//
//Purpose: To make the binary tree empty and release dynamically allocated
//	memory.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Clear()
{
	Clear(m_root);
	m_root = NULL;
	m_length = 0;
}

//***************************************************************************
//Function: Clear(PurchaseBSTNode*& m_tree, Purchase p)
//
//Purpose: To help make the binary tree empty and release dynamically allocated
//	memory.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Clear(PurchaseBSTNode*& tree)
{
	if (tree != NULL)
	{
		Clear(tree->m_leftNode);
		Clear(tree->m_rightNode);
		delete tree;
	}
}

//***************************************************************************
//Function: Add(Purchase p)
//
//Purpose: To add a purchase to the tree.
//
//Big-O runtime cost: O(log n)
//
//***************************************************************************

void PurchaseBST::Add(Purchase p)
{
	Add(m_root, p);
}

//***************************************************************************
//Function: Add(PurchaseBSTNode * m_root, Purchase p)
//
//Purpose: To add a purchase on the tree. Helper overload function that
//	takes root node as a parameter.
//
//Big-O runtime cost: O(log n)
//
//***************************************************************************

void PurchaseBST::Add(PurchaseBSTNode*& tree, Purchase p)
{
	//***************************************************************
	// m_root->m_leftNode == *&m_root->m_leftNode ( heap address )
	// m_root == *&m_root ( heap address )
	// except that & REFERENCES the pointer
	// Need to REFERENCE pointer (&) so that the change is seen by
	// the calling method.
	//***************************************************************

	if (tree == NULL) // Base Case
	{
		tree = new PurchaseBSTNode; // Create a new Node
		tree->m_rightNode = NULL; // Set the two children nodes to NULL 
		tree->m_leftNode = NULL;
		tree->m_purchase = p; // Store the data inside node ( inside parent node )
		m_length++;
	}
	else if (p < tree->m_purchase)
	{
		Add(tree->m_leftNode, p);
	}
	else if (p > tree->m_purchase)
	{
		Add(tree->m_rightNode, p);
	}
}

//***************************************************************************
//Function: Preorder()
//
//Purpose: To print the item names preorder.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Preorder()
{
	Preorder(m_root);
}

//***************************************************************************
//Function: Preorder()
//
//Purpose: To help print the item names preorder.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Preorder(PurchaseBSTNode* tree)
{
	if (tree != NULL)
	{
		cout << tree->m_purchase.getItemName() << endl;
		Preorder(tree->m_leftNode);
		Preorder(tree->m_rightNode);
	}
}

//***************************************************************************
//Function: Inorder()
//
//Purpose: To print the item names of the items stored in the tree in order.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Inorder()
{
	Inorder(m_root);
}

//***************************************************************************
//Function: Inorder(PurchaseBSTNode*& tree)
//
//Purpose: To help print the item names of the items stored in the tree in
//	order.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Inorder(PurchaseBSTNode* tree)
{
	if (tree != NULL)
	{
		Inorder(tree->m_leftNode);
		cout << tree->m_purchase.getItemName() << endl;
		Inorder(tree->m_rightNode);
	}
}

//***************************************************************************
//Function: Postorder()
//
//Purpose: To print the item names of the items stored in the tree.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Postorder()
{
	Postorder(m_root);
}

//***************************************************************************
//Function: Postorder(PurchaseBSTNode*& tree)
//
//Purpose: To help print the item names of the items stored in the tree post 
//	order.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::Postorder(PurchaseBSTNode* tree)
{
	if (tree != NULL)
	{
		Postorder(tree->m_leftNode);
		Postorder(tree->m_rightNode);
		cout << tree->m_purchase.getItemName() << endl;
	}
}


//***************************************************************************
//Function: operator<<(ostream& os, PurchaseBST& rhs)
//
//Purpose: Defines the << operator for a PurchaseBST object.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

ostream& operator<<(ostream& os, PurchaseBST& rhs)
{
	rhs.PrintTree(rhs.m_root, os);
	return os;
}

//***************************************************************************
//Function: PrintTree(PurchaseBSTNode* tree, ostream& os)
//
//Purpose: To help the << operator print the tree.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::PrintTree(PurchaseBSTNode* tree, ostream& os)
{
	if (tree != NULL)
	{
		PrintTree(tree->m_leftNode, os);
		os << tree->m_purchase.getItemName() << endl;
		os << tree->m_purchase.getItemPrice() << endl;
		os << tree->m_purchase.getQuantity() << endl;
		PrintTree(tree->m_rightNode, os);
	}
}

//***************************************************************************
//Function: PurchaseBST::operator=(PurchaseBST & rhs)
//
//Purpose: Defines the operator definition for PurchaseBST class. To make a 
//	deep copy of a different tree.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

PurchaseBST& PurchaseBST::operator=(const PurchaseBST& rhs)
{
	Clear();
	CopyTree(m_root, rhs.m_root);

	return *this;
}

//***************************************************************************
//Function: CopyTree(PurchaseBSTNode*& copy, const PurchaseBSTNode* originalTree)
//
//Purpose: To help make a deep copy of a different tree.
//
//Big-O runtime cost: O(n)
//
//***************************************************************************

void PurchaseBST::CopyTree(PurchaseBSTNode*& copy, const PurchaseBSTNode* originalTree)
{
	if (originalTree == NULL)
	{
		copy = NULL;
	}
	else
	{
		Add(copy, originalTree->m_purchase);
		CopyTree(copy->m_leftNode, originalTree->m_leftNode);
		CopyTree(copy->m_rightNode, originalTree->m_rightNode);
	}

}

//***************************************************************************
//Function: GetCost(string itemName, double & cost)
//
//Purpose: To get the cost of an item in the tree.
//
//Big-O runtime cost: O(log n)
//
//***************************************************************************

bool PurchaseBST::GetCost(string itemName, double& cost)
{
	cost = NULL;
	GetCostHelper(m_root, itemName, cost);

	if (cost != NULL)
	{
		return true;
	}
	
	return false;
}

//***************************************************************************
//Function: GetCostHelper(PurchaseBSTNode*& tree, string itemName, double& cost)
//
//Purpose: To help get the cost of an item in the tree.
//
//Big-O runtime cost: O(log n)
//
//***************************************************************************

void PurchaseBST::GetCostHelper(PurchaseBSTNode*& tree, string itemName, double& cost)
{
	if (tree != NULL)
	{
		if (tree->m_purchase.getItemName() == itemName)
		{
			cost = tree->m_purchase.getItemPrice();
		}
		else if (itemName < tree->m_purchase.getItemName())
		{
			GetCostHelper(tree->m_leftNode, itemName, cost);
		}
		else
		{
			GetCostHelper(tree->m_rightNode, itemName, cost);
		}
	}	
}
