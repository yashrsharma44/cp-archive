#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *next;
};

void push_node(Node **node, int val)
{
	// Create a new Node
	Node *new_node = new Node();
	new_node->data = val;
	new_node->next = (*node);
	(*node) = new_node;
	return;
}

void insertAfter(Node *prev_node, int val)
{
	if(prev_node==NULL)
	{
		return;
	}

	Node *new_node = new Node();

	new_node->data = val;

	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node **node, int val)
{
	// Create a new Node
	Node *new_node = new Node();
	new_node->data = val;
	new_node->next=NULL;

	// Check if node is NULL
	if(*node==NULL)
	{
		*node = new_node;
		return;
	}
	Node *last = *node;
	while(last->next!=NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	return;
}

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}  
  
/* Driver code*/
int main()  
{  

		// Function to add Node at front, at a given Node and at the back
	cout<<"START!";
    /* Start with the empty list */
    Node* head = NULL;  
      
    // Insert 6. So linked list becomes 6->NULL  
    append(&head, 6);  
      
    // Insert 7 at the beginning.  
    // So linked list becomes 7->6->NULL  
    push_node(&head, 7);  
      
    // Insert 1 at the beginning.  
    // So linked list becomes 1->7->6->NULL  
    push_node(&head, 1);  
      
    // Insert 4 at the end. So  
    // linked list becomes 1->7->6->4->NULL  
    append(&head, 4);  
      
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    insertAfter(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    printList(head);  
      
    return 0;  
} 