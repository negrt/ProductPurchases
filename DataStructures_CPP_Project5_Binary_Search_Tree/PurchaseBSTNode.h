//***************************************************************************
//File: PurchaseBSTNode.h
//
//Purpose: Blue print for a struct that will be a Purchase BST Node.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#ifndef PURCHASEBSTNODE_H
#define PURCHASEBSTNODE_H

#include "Purchase.h"

struct PurchaseBSTNode
{
	Purchase m_purchase; // Purchase data
	PurchaseBSTNode * m_leftNode; // Points to the left node
	PurchaseBSTNode * m_rightNode; // Points to the left node
};

#endif