#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *next;
};

void deleteNode(Node** head, int val)
{
	// Check the position of the val to be deleted
	Node* pos = *head;
	// Pointer to the previous Node
	Node *prev = NULL;

	// Corner cases
	// If the LL is 1 element
	if(pos!=NULL && pos->data==val)
	{
		*head = pos->next;
		return;
	}

	// Make sure you check the Null condition before accesssing the data
	while(pos!=NULL&&pos->data!=val)
	{
		prev = pos;
		pos = pos->next;
	}
	// If key wasn't present in LL
	if(pos==NULL)
		return;

	prev->next = pos->next;

}

void push(Node** head, int val)
{
	//Create a new Node
	Node *new_node = new Node();
	new_node->data = val;
	new_node->next=NULL;

	if(*head==NULL)
	{
		*head = new_node;	
		return;
	}

	// Create a copy for traversal
	Node *copy = *head;
	while(copy->next!=NULL)
	{
		copy = copy->next;
	}
	copy->next = new_node;
	return;

}

// This function prints contents of linked list starting from  
// the given node 
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 
  
/* Drier program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
  
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 5); 
    puts("\nLinked List after Deletion of 1: "); 
    printList(head); 
    return 0; 
}