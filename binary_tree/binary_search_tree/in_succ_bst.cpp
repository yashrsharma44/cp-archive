#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;
	Node(int val)
	{
		this->data = val;
		left = right = NULL;
	}
};

Node* leftmostNode(Node *root)
{
	while(root!=NULL && root->left!=NULL)
		root = root->left;

	return root;
}


Node* rightmostNode(Node *root)
{
	while(root!=NULL && root->right!=NULL)
		root = root->right;

	return root;
}


// Recursive function to find the Inorder Successor 
// when the right child of node x is NULL
Node* findinorderRecursive(Node *root, Node* x)
{
	// Here first we find the x from root using recursion
	// Once we find x, we can then backtrack and store the value of 
	// x in temp and then compare the condition root->left == temp
	// If yes then print the inorder successor else bubble up the x
	// through recursion along the path which the code has followed,
	// which indirectly contains the solution

	if(!root)
		return NULL;

	Node *temp;

	if(root==x ||(temp = findinorderRecursive(root->left, x))||(temp = findinorderRecursive(root->right, x)))
	{
		if(temp)
		{
			if(root->left == temp)
			{
				cout << "Inorder successor of Node is "<<root->data<<endl;
				return NULL;
			}
		}
		return root;
	}
	return NULL;

}

void inorderSuccessor(Node *root, Node *x)
{
	// Case 1 : Right child is not NULL
	// Then return the leftmost Node of the right subtree
	// of the Node x
	if(x->right!=NULL)
	{
		Node *temp = leftmostNode(x->right);
		cout << "Inorder successor of Node is "<<temp->data<<endl;
		return;
	}

	if(x->right == NULL)
	{
		// We have 2 cases
		// If the rightmost child is None and it is the right most element
		// in the BST, then we dont have any inorder successor
		Node *rel = rightmostNode(root);
		if(rel == x)
		{
			cout <<"Rightmost node is not possible"<<endl;
		}
		else
		{
			findinorderRecursive(root, x);
			
		}
	}
}

int main()
{
	// Function to evaluate the inorder successor of a 
	// BST

	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->right = new Node(6); 
  
    // Case 1  
    inorderSuccessor(root, root->right); 
  
    // case 2 
    inorderSuccessor(root, root->left->left); 
  
    // case 3 
    inorderSuccessor(root, root->right->right); 
  
    return 0; 
}