#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;

	Node(int key)
	{
		this->data = key;
		left = right = NULL;
	}
};

Node *insert(Node *root, int val)
{
	if(root==NULL)
		return new Node(val);

	else if(val < root->data)
	{
		root->left = insert(root->left, val);
	}
	else
	{
		root->right = insert(root->right, val);
	}
}

Node *getInorderSuccessor(Node *root)
{
	Node *curr = root;

	while(curr && curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}

Node *deleteNode(Node *root, int val)
{
	// Base case
	if(!root)
		return NULL;

	// First find the Node that contains the val
	if(val < root->data)
	{
		root->left = deleteNode(root->left, val);
	}
	else if(val > root->data)
	{
		root->right = deleteNode(root->right, val);
	}
	else
	{
		// We found the element, now we need to decide how to delete it

		// Case 1 and 2: We have no child or atmost 1 child
		if(root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		if(root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}

		// Case 3: We have 2 childrens
		Node *temp = getInorderSuccessor(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

// A utility function to do inorder traversal of BST 
void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
}

int main()
{
	// To demonstrate the deletion of an element in a bst

	Node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    cout<<"Inorder traversal of the given tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 30\n"<<endl;
    root = deleteNode(root, 30); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 50\n";
    root = deleteNode(root, 50); 
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root); 
  
    return 0; 
}