#include <iostream>
using namespace std;
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int, int> tree; //the key and value both are of type int

	tree.insert(500, 500);
	tree.insert(1000, 1000);
	tree.insert(1, 1);
	tree.insert(600, 600);
	tree.insert(700, 700);
	tree.insert(10, 10);
	tree.insert(30, 30);
	tree.insert(900, 900);
	tree.insert(50000, 50000);
	tree.insert(20, 20);
	
	BinarySearchTree<int, int> tree1(tree);
	
	tree1.deleteKey(20);
	tree1.deleteKey(500);
	tree1.deleteKey(1000);

	tree1.inorderPrintKeys();
	cout << endl << endl;
	cout<<"Tree1 Length: "<<tree1.length()<<endl;
	
	int *val = tree1.search(1);
	
	if (val != nullptr)
	{
		cout << "1 found" << endl;
	}

	val = tree1.search(123);
	if (val == nullptr)
	{
		cout << "123 not found" << endl;
	}

	system("pause");
}