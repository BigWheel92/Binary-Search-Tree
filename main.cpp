#include <iostream>
using namespace std;
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int, int> tree; //the key and value both are of type int. (both can be of any type. They 
									 //can also be of different type from each other)

	tree.insert(500, 500);
	tree.insert(1000, 1000);
	tree.insert(1, 1);
	tree.insertIterative(600, 600); //calling iterative insert
	tree.insert(700, 700);
	tree.insert(10, 10);
	tree.insert(30, 30);
	tree.insert(900, 900);
	tree.insertIterative(50000, 50000); //calling iterative insert
	tree.insert(20, 20);

	BinarySearchTree<int, int> tree1(tree);

	tree1.deleteKeyIterative(500); //calling iterative delete
	tree1.deleteKey(10); //calling recursive delete
	tree1.deleteKeyIterative(20); //calling iterative delete
	tree1.deleteKey(700); //calling recursive delete


	tree1.inorderPrintKeys();
	cout << endl << endl;
	cout << "Tree1 Length: " << tree1.length() << endl;

	int *val = tree1.search(1);

	if (val != nullptr)
	{
		cout << "Key= 1 found" << endl;
	}

	val = tree1.search(123);
	if (val == nullptr)
	{
		cout << "Key= 123 not found" << endl;
	}

	system("pause");
}
