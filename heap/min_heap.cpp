#include <bits/stdc++.h>

using namespace std;


void swap(int *x, int *y)
{
	int k = *x;
	*x = *y;
	*y = k;
}

class MinHeap
{
	int *harr;
	int capacity;
	int heap_size;

public:
	// Constructor
	MinHeap(int capacity);

	// Returns the parent for a given index of a Node
	int parent(int i){return (i-1)/2;}

	// Returns the left child for a given index of a Node
	int left(int i){return (2*i + 1);}

	// Returns the right child for a given index of a Node
	int right(int i){return (2*i + 2);}



	// to heapify a subtree with the root at given index
	void MinHeapify(int );

	// Function to extract min element which is the root
	int extractMin();

	// Decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the root of the Min Heap
	int getMin(){return harr[0];}

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a key
	void insertKey(int k);
};


// Constructor: Builds a heap from a given class array
MinHeap::MinHeap(int cap)
{
	this->heap_size = 0;
	this->capacity = cap;
	this->harr = new int[cap];
}

// Insert a new Node
void MinHeap::insertKey(int k)
{
	// If Heap size is attained
	if(heap_size == capacity)
	{
		cout<<"Heap Overflow! Could not insert a key";
		return;
	}

	// Insert key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap if the property is violated
	while(i!=0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
	return;
}

// Decreases value of key at index i to new_val. It is assumed that
// new_val is smaller than harr[i]
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while(i!=0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Method to remove the minimum element (or root) from min heap
int MinHeap::extractMin()
{
	// If no elements are present
	if(heap_size<=0)
		return -9999;
	if(heap_size==1)
	{
		heap_size--;
		return harr[0];	
	}

	// Store the minimum value and remove it from the heap
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;

}


// This function deletes key at index i. It first reduced value to
// minus infinite then calls extractMin()
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A Recursive method to heapify a subtree with the root at the 
// given index. This assumes that the subtree is always heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l<heap_size && harr[l] < harr[i])
		smallest = l;
	if(r<heap_size && harr[r] < harr[i])
		smallest = r;
	if(smallest!=i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}


int main()
{
	// Implementing a min heap method
	MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
}