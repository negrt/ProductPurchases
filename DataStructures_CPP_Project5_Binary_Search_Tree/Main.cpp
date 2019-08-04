#include <iostream>
#include "Purchase.h"
#include "PurchaseBST.h"
#include <iomanip>
using namespace std;

int main()
{
	// Manual Test

	cout << setprecision(2);

	// Purchases

	Purchase p1 = Purchase("Orange", 5.0, 1.10);
	Purchase p2 = Purchase("Apple", 7.0, 1.05);
	Purchase p3 = Purchase("Peach", 3.0, 1.25);
	Purchase p4 = Purchase("Radio", 1.0, 10.95);
	Purchase p5 = Purchase("Oscilloscope", 4.0, 99.98);
	Purchase p6 = Purchase("Multimeter", 10, 58.87);
	Purchase p7 = Purchase("Bicycle", 2, 299.90);
	Purchase p8 = Purchase("Arduino", 5, 67.98);
	Purchase p9 = Purchase("Keychain", 9, 8.99);
	Purchase p10 = Purchase("Candle", 5, 6.01);


	// First Binary Search Tree Default Constructor

	cout << "Testing Default Constructor, Add, << operator, Size:\n";
	cout << "-------------------------------------------\n\n";

	PurchaseBST BST1 = PurchaseBST();

	BST1.Add(p1);
	BST1.Add(p2);
	BST1.Add(p3);
	BST1.Add(p4);
	BST1.Add(p5);
	BST1.Add(p6);
	BST1.Add(p7);
	BST1.Add(p8);
	BST1.Add(p9);
	BST1.Add(p10);

	cout << "BST1.Size() = " << BST1.Size() << endl << endl;
	cout << "BST1 = \n\n" << BST1;


	// Second Binary Search Tree Copy Constructor

	cout << "\nTesting Copy Constructor:\n";
	cout << "-------------------------------------------\n\n";

	PurchaseBST BST2 = PurchaseBST(BST1);

	cout << "BST2.Size() = " << BST2.Size() << endl << endl;
	cout << "BST2 = \n\n" << BST2;


	// Testing Deep Copy

	cout << "\nTesting Clear and Deep Copy after a copy constructor:\n";
	cout << "-------------------------------------------\n\n";

	BST2.Clear();

	cout << "BST2.Size() = " << BST2.Size() << endl << endl;
	cout << "BST2 = \n\n" << BST2 << endl;
	cout << "BST1.Size() = " << BST1.Size() << endl << endl;
	cout << "BST1 = \n\n" << BST1 << endl;


	// Testing Traversal on BST1

	cout << "\nTraversal Preorder:\n";
	cout << "-------------------------------------------\n\n";

	BST1.Preorder();

	cout << "\nTraversal Inorder:\n";
	cout << "-------------------------------------------\n\n";

	BST1.Inorder();

	cout << "\nTraversal Postorder:\n";
	cout << "-------------------------------------------\n\n";

	BST1.Postorder();


	// Testing = operator

	cout << "\nTesting = operator:\n";
	cout << "-------------------------------------------\n\n";

	BST2 = BST1;

	cout << "BST2.Size() = " << BST2.Size() << endl << endl;
	cout << "BST2 = \n\n" << BST2 << endl;
	cout << "BST1.Size() = " << BST1.Size() << endl << endl;
	cout << "BST1 = \n\n" << BST1 << endl;

	cout << "\nTesting deep copy after = operator:\n";
	cout << "-------------------------------------------\n\n";

	BST2.Clear();

	cout << "BST2.Size() = " << BST2.Size() << endl << endl;
	cout << "BST2 = \n\n" << BST2 << endl;
	cout << "BST1.Size() = " << BST1.Size() << endl << endl;
	cout << "BST1 = \n\n" << BST1 << endl;


	// Testing GetCost Method

	cout << "\nTesting GetCost Method:\n";
	cout << "-------------------------------------------\n\n";

	double costOfItem;

	cout << "1 if True (found): " << BST1.GetCost("Oscilloscope", costOfItem) << endl;

	cout << fixed << "Cost of Oscilloscope: " << costOfItem << endl;


	cout << "\nTesting ~Destructor:\n";
	cout << "-------------------------------------------\n\n";
}
