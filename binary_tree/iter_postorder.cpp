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
	}
};

void postOrder(Node *root)
{
	// base case
	if(root==NULL)
		return;
}

int main()
{
	// To demonstrate the post order traversal of
	// binary tree using stack
}