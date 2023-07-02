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
public:
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
		search(element, parent, currentnode);// locate the node which will be the parent of the node to be inserted

		if (parent == NULL)
		{
			ROOT = newNode; // mark the newnode as root
			return; // exit
		}
		if (element < parent->info) // if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = newNode; // make the left child of the parent point to the new node
		}
		else if (element < parent->info) // if the value in the data field of the new node is greater than of the parent
		{
			parent->rightchild = newNode; // make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// this function searches the currentNode pd the specified node as well as the current node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) &&(currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		cout << ptr->info << " ";
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
}

	void postroder(Node* ptr)
	{
		//performs the postorder travelsal of the tree
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postroder(ptr->leftchild);
			postroder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	BinaryTree obj; 
	while (true) 
	{
		cout << "\nmenu" << endl;
		cout << "1.implement insert operation" << endl;
		cout << "2.perform inorder traversal" << endl;
		cout << "3.perform preorder traversal" << endl;
		cout << "4.perfrom postorder traversal" << endl;
		cout << "5.exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "enter a word:";
			string word;
			cin >> word;
			obj.Insert(word);
			break;
		}
		case '2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case '3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
		case '4':
		{
			obj.postroder(obj.ROOT);
			break;
		}
		case '5':
			return 0;
		default: 
		{
			cout << " invalid option" << endl;
			break;
		}

		}
	}

}