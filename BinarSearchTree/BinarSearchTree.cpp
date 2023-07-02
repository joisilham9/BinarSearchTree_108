#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Contructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public : 
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; // initializing ROOT to null
	}

	void Insert(string element) // insert a node in binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL); // allocate memory for the new node
		newNode->info = element; //assign value to the data field of the new node
		newNode->leftchild = NULL; //make the left child of the new node point to null
		newNode->rightchild = NULL; //make the right child of the new node point to null 

		Node* parent = NULL;
		Node* currentnode = NULL;
		search(element, parent, currentNode); // locate the node which will be the parent of the node to be inserted
	
		if (parent == NULL)
		{

		}
	}
};