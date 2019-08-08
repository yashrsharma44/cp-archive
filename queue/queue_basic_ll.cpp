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

QNode *deQueue(Queue *root)
{
	// If queue is NULL return NULL
	if(root->front == NULL)
	{
		return NULL;
	}

	// Store the front element and move the front Node forward
	QNode *temp = root->front;
	root->front = root->front->next;

	// Check if the front is NULL if yes, then rear is also NULL
	if(root->front == NULL)
		root->rear = NULL;

	return temp;

}

int main()
{
	// Basic implementation of queue using linked list in cpp
	Queue* q = createQueue(); 
    enQueue(q, 10); 
    enQueue(q, 20); 
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    enQueue(q, 40); 
    enQueue(q, 50); 
    QNode* n = deQueue(q); 
    if (n != NULL) 
        cout << "Dequeued item is " << n->key; 
    return 0; 
}