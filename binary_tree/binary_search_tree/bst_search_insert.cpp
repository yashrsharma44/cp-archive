#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int key;
	Node *left, *right;
	Node(int key)
	{
		this->key = key;
		left = right =NULL;
	}
};

void inorder(Node *root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	cout <<root->key <<" "<<endl;
	inorder(root->right);
}

Node* search(Node *root, int val)
{
	if(root==NULL || root->key == val)
	{
		return root;
	}
	else if(val > root->key)
	{
		return search(root->right, val);
	}
	else
	{
		return search(root->left, val);
	}
}

Node* insert(Node *root, int key)
{
	// base case
	if(root == NULL)
	{
		Node *newNode = new Node(key);
		return newNode;
	}

	// Check if the key is less than the root
	else if(key < root->key)
	{
		root->left = insert(root->left, key);
	}
	else
	{
		root->right = insert(root->right, key);
	}

	return root;
}

int main()
{
	Node *root = new Node(50);

	root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
   
    // print inoder traversal of the BST 
    inorder(root); 

    Node* cal = insert(root, 50);
    cout <<"Searched element"<<cal->key<<endl;
   
    return 0; 
}