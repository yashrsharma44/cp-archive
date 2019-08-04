#include <bits/stdc++.h>

using namespace std;

class StackNode{
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data)
{
	StackNode* stacknode = new StackNode();
	stacknode->data = data;
	stacknode->next = NULL;
	return stacknode;
}

int isEmpty(StackNode* root)
{
	return !root;
}

void push(StackNode** root, int data)
{
	StackNode* new_node = new StackNode();
	new_node->next = *root;
	new_node->data = data;
	*root = new_node;
	cout << data <<"pushed to stack\n";
}

int pop(StackNode** root)
{
	if(isEmpty(*root))
		return -9999;

	// Have a pointer to the Node which would be removed
	// So that we can free them when required
	StackNode* temp = *root;
	*root = (*root)->next;

	int popped = temp->data;
	free(temp);
	return popped;
}

int peek(StackNode* root)
{
	if(isEmpty(root))
		return -9999;

	return root->data;
}

int main()
{
	// Implement a stack using Linked Lists
	StackNode* root = NULL; 
  
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30); 
  
    cout << pop(&root) << " popped from stack\n"; 
  
    cout << "Top element is " << peek(root) << endl; 
  
    return 0; 
}