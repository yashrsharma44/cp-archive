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
	left = right = NULL;
}
};



void inOrder(Node *root)
{
	stack <Node *> s;

	// Create a current Node to track the elements
	Node *curr = root;

	while(curr!=NULL || s.empty()==false)
	{	
		while(curr!=NULL)
			{
				s.push(curr);
				curr = curr->left;
			}
		
			// Now we are sure that we have no curr element
			curr = s.top();
			s.pop();
		
			cout << curr->data <<" "<<endl;

			curr = curr->right;

	}	
}

int main()
{
	// Iterative method to traverse a tree
	// Uses stack to store the elements 

	Node *root = new Node(1);
	  root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
  
    inOrder(root); 
    return 0;
}