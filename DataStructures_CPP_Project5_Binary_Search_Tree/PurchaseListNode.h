//***************************************************************************
//File: PurchaseListNode.h
//
//Purpose: Blue print for a struct that will be Purchase List Node.
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//***************************************************************************

#ifndef PURCHASELISTNODE_H
#define PURCHASELISTNODE_H

#include "Purchase.h"

struct PurchaseListNode
{
	Purchase m_purchase; // Purchase data
	PurchaseListNode * m_nextNode; // Points to the next node
};

#endif
