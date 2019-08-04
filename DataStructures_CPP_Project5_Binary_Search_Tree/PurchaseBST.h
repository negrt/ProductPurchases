//***************************************************************************
//File: PurchaseBST.h
//
//Purpose: To define a Binary Search Tree Abstract Data Type that store
// Purchase Objects.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************


#ifndef PURCHASEBST_H
#define PURCHASEBST_H

#include <iostream>
#include "Purchase.h"

struct PurchaseBSTNode
{
	Purchase m_purchase; // Purchase data
	PurchaseBSTNode* m_leftNode; // Points to the left node
	PurchaseBSTNode* m_rightNode; // Points to the left node
};

class PurchaseBST
{
	private:
		PurchaseBSTNode* m_root;
		int m_length;

		// Helper Functions
		void Add(PurchaseBSTNode*& tree, Purchase p);
		void Clear(PurchaseBSTNode*& tree);
		void Preorder(PurchaseBSTNode* tree);
		void Inorder(PurchaseBSTNode* tree);
		void Postorder(PurchaseBSTNode* tree);
		void PrintTree(PurchaseBSTNode* tree, ostream& os);
		void CopyTree(PurchaseBSTNode*& copy, const PurchaseBSTNode* originalTree);
		void GetCostHelper(PurchaseBSTNode*& tree, string itemName, double& cost);

	public:
		PurchaseBST();
		PurchaseBST(const PurchaseBST& rhs);
		~PurchaseBST();

		void Clear();
		int Size();
		void Add(Purchase p);
		void Preorder();
		void Inorder();
		void Postorder();
		bool GetCost(string itemName, double& cost);

		PurchaseBST& operator=(const PurchaseBST& rhs);

		friend ostream& operator<<(ostream& os, PurchaseBST& rhs);
};

ostream& operator<<(ostream& os, const PurchaseBST& rhs);

#endif
