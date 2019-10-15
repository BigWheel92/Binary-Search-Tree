#pragma once

#include <iostream>
using namespace std;


template <typename k, typename v>
struct TNode
{
	k key;
	v value;
	TNode<k, v> *leftChild;
	TNode<k, v> *rightChild;

	TNode()
	{
		leftChild = rightChild = nullptr;
	}

	bool isLeafNode()
	{
		return !(leftChild || rightChild);
	}

};

template <typename k, typename v>
class BinarySearchTree
{
private:
	TNode<k, v> *root;


	int length(TNode<k, v>* node) const
	{
		if (node == nullptr)
			return 0;

		else return 1 + length(node->leftChild) + length(node->rightChild);
	}

	void copy(TNode<k, v> *&n1, TNode<k, v> const * const&n2)
	{
		if (n2 == nullptr)
		{
			n1 = nullptr;
			return;
		}

		n1 = new TNode<k, v>;
		n1->key = n2->key;
		n1->value = n2->value;

		//recursively deep copying the left subtree and the right subtree.
		copy(n1->leftChild, n2->leftChild);
		copy(n1->rightChild, n2->rightChild);

	}

	void insert(TNode<k, v> * &node, k key, v value)
	{
		if (node == nullptr)
		{
			node = new TNode<k, v>();
			node->key = key;
			node->value = value;
			return;
		}

		if (key > node->key)
		{
			insert(node->rightChild, key, value);
		}

		else if (key < node->key)
		{
			insert(node->leftChild, key, value);
		}

		else  //duplicate key, so update the value
		{
			node->value = value;
			return;
		}

	}

	void inorderPrintKeys(TNode<k, v> const*node) const
	{
		if (node == nullptr)
			return;

		inorderPrintKeys(node->leftChild);

		cout << node->key << ",";



		inorderPrintKeys(node->rightChild);


	}

	v* search(TNode<k, v>*n, k key)
	{
		if (n == nullptr)
			return nullptr;

		if (n->key == key)
			return &n->value;

		else if (key < n->key)
			return search(n->leftChild, key);

		else return search(n->rightChild, key);

	}

	void deleteAll(TNode<k, v> *n)
	{
		if (n == nullptr)
			return;

		deleteAll(n->leftChild);
		deleteAll(n->rightChild);
		delete n;
	}

	//pred is the parent of current.
	void deleteKey( TNode<k, v>*& current, k const key)
	{
		//the key to delete does not exist in the tree.
		if (current == nullptr)
			return;

		else if (key > current->key)
		{	//move to the right subtree
			deleteKey(current->rightChild, key);
			return;
		}

		else if (key < current->key)
		{	//move to the left subtree
			deleteKey(current->leftChild, key);
			return;
		}
		else //current node has the key that we need to delete
		{

			//case 1: the node to delete is the leaf node.
			if (current->isLeafNode() == true)
			{
			
				delete current;
				current = nullptr;
				return;
			}//end of case 1

			//case 2: one of the subtrees of current is nullptr;
			else if (current->leftChild == nullptr || current->rightChild == nullptr)
			{
				if (current->leftChild == nullptr)
				{
					TNode<k, v> *nodeToDelete = current;
					current = current->rightChild;
					delete nodeToDelete;
					return;
				}

				else //right child is nullptr, but left child is not
				{
					TNode<k, v> *nodeToDelete = current;
					current = current->leftChild;
					delete nodeToDelete;
					return;
				}

			}//end of case 2

			else  //case 3: none of the subtrees of node to delete is nullptr.
			{
				TNode<k, v> *newNodeToDelete = current->rightChild;
				
				while (newNodeToDelete->leftChild != nullptr)
				{
					newNodeToDelete = newNodeToDelete->leftChild;
				}

				current->key = newNodeToDelete->key;
				current->value = newNodeToDelete->value;

				//in this new recursive call, case 0 and 3 will never exist. Only case 1 or case 2 will exist.
				deleteKey(current->rightChild, current->key);
			}
		}
	}

	
	
public:
	BinarySearchTree()
	{
		this->root = nullptr;
	}

	BinarySearchTree(BinarySearchTree<k, v> const& that)
	{
		if (that.root == nullptr)
		{
			this->root = nullptr;
			return;
		}

		//passed the node of this tree and the node of that tree by reference and recursively deep copies.
		copy(this->root, that.root);
	}


	void insert(k const  key, v const value)
	{
		//node is passed by reference.
		insert(this->root, key, value);

	}

	v* search(k const key)
	{
		return search(this->root, key);
	}

	void inorderPrintKeys() const
	{

		this->inorderPrintKeys(this->root);
	}

	void deleteAll()
	{
		deleteAll(this->root);
		this->root = nullptr;
	}

	void deleteKey(k key)
	{
		deleteKey(this->root, key);
	}

	int length() const
	{
		return length(this->root);
	}

	~BinarySearchTree()
	{
		deleteAll();
	}



};

