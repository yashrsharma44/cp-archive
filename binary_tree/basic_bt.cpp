#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int key;
	Node *left, *right;
};

// Helper function to create a new Node
Node *newNode(int key)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;
	temp->key = key;
	return temp;
}

// Inorder traversal

void inorder(Node *root)
{
	if(!root)
	{
		return;
	}

	inorder(root->left);
	cout <<root->key<<" "<<endl;
	inorder(root->right);
}

// Function to insert a Node
void insert(Node *root, int key)
{
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		Node *root = q.front();
		q.pop();

		if(root->left == NULL)
		{
			Node *lchild = newNode(key);
			root->left = lchild;
			break;
		}
		else
		{
			q.push(root->left);
		}

		if(root->right == NULL)
		{
			Node *rchild = newNode(key);
			root->right = rchild;
			break;
		}
		else
		{
			q.push(root->right);
		}
	}
}



int main()
{
	// Function to add a value to an empty node at any level 
	// for a binary tree
	// Here we use level order traversal to traverse all the nodes
	// at a given level. If we don't find the node at a certain level
	// we add the Node at that level and stop the traversal

	Node *root = newNode(10);

	root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before insertion:"<<endl; 
    inorder(root); 
  
    int key = 12; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"<<endl; 
    inorder(root); 
  
    return 0; 

}