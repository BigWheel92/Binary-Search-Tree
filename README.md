# Binary-Search-Tree

The following public functions are supported:
	BinarySearchTree()  : Default Constructor
	
The following functions are iterative:
	
	void insertIterative(k const key, v const value) :  insert a value with the specific key by creating a new node. if the key already exists, it simply overwrites the value
	
	void deleteKeyIterative(k const key)  :   delete the node containing the specific key.
	
The following functions use recursion(they make use of other private recursive member functions):	
	
	BinarySearchTree(BinarySearchTree<k, v> const& that)  :  Overloaded constructor that deep copies another Binary Search Tree Object.

	void insert(k const  key, v const value)   :  	insert a value with the specific key by creating a new node. if the key already exists, it simply overwrites the value

	v* search(k const key)     :  Find the value of the node which has the given key.

	void inorderPrintKeys() :  print keys in inorder fashion.
  
	void deleteAll()   :  delete all nodes of binary search tree.
  
	void deleteKey(k key) :  delete the node containing the given key.

	int length() :  returns total number of nodes of Binary Search tree (total number of nodes is equal to the total number of keys.)
  
	~BinarySearchTree()  :  Destructor
