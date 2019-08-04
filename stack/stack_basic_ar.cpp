#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack
{
// Class Variables
	int top;

public:
	int a[MAX];
	// Constructor
	Stack()
	{
		top = -1;
	}

	// Currently writing down the class methods, will define them later
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if(top >= (MAX-1))
	{
		cout<<"Stack Overflow!";
		return false;
	}
	else
	{
		a[++top] = x;
		cout << x<<" pushed into stack!";
		return true;
	}
}

int Stack::pop()
{
	if(top<0)
	{
		cout<<"Stack underflow!";
		return -9999;
	}
	else
	{
		int x = a[top--];
		return x;
	}
}

int Stack::peek()
{
	if(top<0)
	{
		cout<<"Stack is empty";
		return -9999;
	}
	else
	{
		return a[top];
	}
}

bool Stack::isEmpty()
{
	return (top<0);
}


int main() 
{ 
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
    cout <<s.peek() <<" Element peek!";
  
    return 0; 
} 