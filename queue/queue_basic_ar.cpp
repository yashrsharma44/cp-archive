#include <bits/stdc++.h>

using namespace std;

class Queue
{
public:
	int front, rear, size;
	unsigned capacity;
	int *array;
};

// Initial function to create a queue of a given capacity
// Initial size is 0

Queue* createQueue(unsigned capacity)
{
	Queue*queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = new int[(queue->capacity)];
	return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Function to check if the Queue is empty
int isEmpty(Queue* queue)
{
	return (queue->size==0);
}

// Function to add an element
void enqueue(Queue* queue, int item)
{
	if(isFull(queue))
	{
		return;
	}
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size += 1;
	cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue
int dequeue(Queue* queue)
{
	if (isEmpty(queue))
	{
		return -9999;
	}
	int item = queue->array[queue->front];
	queue->front = (queue->front+1)%queue->capacity;
	queue->size -=1;
	return item;
	
}
void print_queue(Queue* queue)
{
	int *ar = queue->array;
	int size = queue->capacity;
	for(int i=0;i<size;i++)
	{
		cout<<ar[i]<<endl;
	}
}

// Function to get front of a queue
int front(Queue* queue)
{
	if(isEmpty(queue))
		return -9999;
	return queue->array[queue->front];
}

// Function to get the rear of a queue
int rear(Queue* queue)
{
	if(isEmpty(queue))
		return -9999;
	return queue->array[queue->rear];
}

// Driver code 
int main()  
{  
    Queue* queue = createQueue(4);  
  
    enqueue(queue, 10);  
    print_queue(queue);
    enqueue(queue, 20);
    print_queue(queue);  
    enqueue(queue, 30);
    print_queue(queue);  
    enqueue(queue, 40);  
  	print_queue(queue);
    cout<<dequeue(queue)<<" dequeued from queue\n";  
  
    cout << "Front item is " << front(queue) << endl;  
    cout << "Rear item is " << rear(queue) << endl;  
  
    print_queue(queue);
    enqueue(queue, 300);
    print_queue(queue); 
    return 0;  
}  
  