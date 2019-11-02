#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node(int k)
	{
		this->data = k;
		left = right = NULL;
	}
};

void preOrder(Node *root)
{
	// Base case
	if(root==NULL)
		return;

	// Create an empty stack and push elements into it
	stack <Node *> s;
	s.push(root);

	while(!s.empty())
	{
		Node *root = s.top();
		s.pop();
		cout << root->data <<" "<<endl;

		// Here we are pushing right before left
		// as we want left before right

		if(root->right)
			s.push(root->right);
		if(root->left)
			s.push(root->left);
	}
}

int main()
{
	// To demonstrate the pre order traversal 
	// using stack
  Node *root = new Node(10);	
	root->left        = new Node(8); 
  root->right       = new Node(2); 
  root->left->left  = new Node(3); 
  root->left->right = new Node(5); 
  root->right->left = new Node(2); 
  preOrder(root); 
  return 0; 

}