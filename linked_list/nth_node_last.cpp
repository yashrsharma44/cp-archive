#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *next;
};

void push(Node **head, int val)
{
	Node *temp = new Node();
	temp->data = val;
	temp->next = *head;
	*head = temp;
}

int printNthFromLast(Node *head, int n)
{
	// We keep two pointers and traverse ref pointer
	// to n steps and then traverse both of them till
	// ref pointer reaches NULL. This ensures that head 
	// traverses l-x steps from start == x steps from back

	Node *head_ref=head, *temp=head;
	int count=0;
	while(count<n)
	{
		if(temp->next==NULL)
		{
			return -1;
		} 
		temp = temp->next;
		count++;
	}
	// cout<<"COUNT"<<count<<endl;
	while(temp!=NULL)
	{
		head_ref = head_ref->next;
		temp = temp->next;
	}
	return head_ref->data;
}

int main() 
{ 
  /* Start with the empty list */
  Node* head = NULL; 
  push(&head, 20); 
  push(&head, 4); 
  push(&head, 15); 
  push(&head, 35); 
  
  cout<<printNthFromLast(head, 4); 
} 