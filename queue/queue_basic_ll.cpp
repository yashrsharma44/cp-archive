// Basic implementation of queue in cpp

#include <bits/stdc++.h>
using namespace std;

class QNode 
{
public:
	int key;
	QNode* next;
};

class Queue
{
public:
	QNode *front, *rear;
};

QNode* newNode(int k)
{
	QNode* new_node = new QNode();
	new_node->next = NULL;
	new_node->key = k;
	return new_node;
}

Queue* createQueue()
{
	Queue *q = new Queue();
	q->front = q->rear = NULL;
	return q;
}

void enQueue(Queue *q, int k)
{
	// Create a new Node
	QNode *temp = newNode(k);

	// If queue is empty
	// then front and rear is 
	// the same
	if(q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}

	// Add the new node at
	// the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp;
}

int main()
{
	// Basic implementation of queue using linked list in cpp
}