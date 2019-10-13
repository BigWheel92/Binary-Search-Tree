# Binary-Search-Trees
Binary Search Trees 

The following operations are supported (the operations use recursion):

	BinarySearchTree()  : Default Constructor

	BinarySearchTree(BinarySearchTree<k, v> const& that)  : Overloaded constructor that deep copies another Binary Search Tree Object.

	void insert(k const  key, v const value)   :   insert a value with the specific key.

	v* search(k const key)     :  Find the value of the node which has the given key.

	void inorderPrintKeys() : print keys in inorder fashion.
  
	void deleteAll()   :  delete all nodes of binary search tree.
  
	void deleteKey(k key) : delete the node containing the given key.

	int length() :  returns total number of nodes of Binary Search tree (total number of nodes is equal to the total number of keys.)
  
	~BinarySearchTree()  : Destructor
