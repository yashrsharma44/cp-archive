#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

// Iterative Solution
Node* LCA_Iter(Node *root, int n1, int n2)
{
	while(root!=NULL)
	{
		if(root->data > n1 && root->data > n2)
		{
			root = root->left;
		}

		else if(root->data < n1 && root->data < n2)
		{
			root =root->right;
		}
		else
			break;
	}
	return root;
}

// Recursive Solution
Node* LCA(Node *root, int n1, int n2)
{
	// Base case
	if(root==NULL)
		return NULL;

	// Else if the root is greater than n1 and n2
	if(root->data > n1 && root->data > n2)
	{
		return LCA(root->left, n1, n2);
	}

	if(root->data < n1 && root->data < n2)
	{
		return LCA(root->right, n1, n2);
	}
	return root;
}

int main()
{
	// Function to demonstrate the lowest common ancestor
	// of a given node
	Node *root = new Node(20);  
    root->left = new Node(8);  
    root->right = new Node(22);  
    root->left->left = new Node(4);  
    root->left->right = new Node(12);  
    root->left->right->left = new Node(10);  
    root->left->right->right = new Node(14);  
  
    int n1 = 10, n2 = 14;  
    Node *t = LCA(root, n1, n2);  
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;  
  
    n1 = 14, n2 = 8;  
    t = LCA(root, n1, n2);  
    cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;  
  
    n1 = 10, n2 = 22;  
    t = LCA(root, n1, n2);  
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;  

    n1 = 14, n2 = 8;  
    t = LCA_Iter(root, n1, n2);  
    cout<<"LCA_Iter of " << n1 << " and " << n2 << " is " << t->data << endl;  
  
    n1 = 10, n2 = 22;  
    t = LCA_Iter(root, n1, n2);  
    cout << "LCA_Iter of " << n1 << " and " << n2 << " is " << t->data << endl;  
    return 0;  
}