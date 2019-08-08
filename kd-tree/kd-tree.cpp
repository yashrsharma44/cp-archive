#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

int crtree = 0;
int qpoint = 0;

// Class for Node
class Node
{
public:
	
	int x;
	int y;
	int depth;
	Node *left, *right;
	pair<int,int> xlim;
	pair<int,int> ylim;

	// Flag to check if the Node is a child
	int flag=0;
	
};

// Helper function to create a Node
// x : X-coord
// y : Y-coord
// depth : depth of Node of a tree
Node *createNode(int x, int y, int depth)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;
	temp->depth = depth;
	temp->x = x;
	temp->y = y;
	return temp;

}

// Function to write values
void write_values(int range){
    ofstream outfile;
    int i=0;
    set <int> ax;
    set <int> ay;

    // int range = 20;
    outfile.open("input.txt");
    for(i=0;i<range;)
    {
    	int val1 = 1 + rand()%101;
    	int val2 = 1 + rand()%101;
    	
        outfile <<val1<<" "<<val2<<endl;
        i+=1;
    
    }
    outfile.close();
}

// comparing function for sorting elements along x/y axis
bool sortby_y(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.second < b.second);
}

bool sortby_x(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.first < b.first);
}

// Function to check if the given Bounding box in the rectangle lies
bool checkInBB(pair<int,int> &Xlim, pair<int,int> &Ylim, pair<int,int> &D1, pair<int,int> &D2)
{
	// Check if the bbox lies inside the query range
	// The coordinates of the range rectangle should be (L,L) and (R,R)

	if(Xlim.first > D1.first && Xlim.second < D2.first)
	{
		if(Ylim.first > D1.second && Ylim.second < D2.second)
		{
			return true;
		}
	}
	return false;
}

// Function to check if query rectangle intersects the BBox
bool checkIntersection(pair<int,int> &Xlim, pair<int,int> &Ylim, pair<int,int> &D1, pair<int,int> &D2)
{
	// Since we are taking the diagonal point as (L,L) and (R,R),
	// so we have 3 cases
	// We are excluding the case where the BBox is inside the query rectangle
	if((Xlim.first > D1.first && Xlim.second < D2.first)&&(Ylim.first > D1.second && Ylim.second < D2.second))
	{
		return false;
	}
	else
	{
		return true;
	}

}

// Function to check if the point lies inside the box
bool checkBox(int x, int y, pair<int,int> &D1, pair<int,int> &D2)
{
	// Check if a given point lies inside a bounding box
	// The diagonal of query rec should be (L,L) and (R,R)

	if(x > D1.first && x < D2.first)
	{
		if(y > D1.second && y < D2.second)
		{
			return true;
		}
	}
	return false;
}


// Function to build the tree
Node* BuildTree(Node *root, int depth, vector< pair <int,int> > &S, pair <int,int>&Bx , pair <int,int> &By)
{
	// Increment the counter for recording number of calls to BuildTree
	::crtree += 1;

	// If the number of elements is 1
	if(S.size() == 1 && root==NULL)
	{
		root = createNode(S[0].first, S[0].second, depth);
		root->xlim = Bx;
		root->ylim = By;
		root->flag = 1;
		return root;
	}
	else if(S.size()!=1 && root==NULL)
	{
		root = createNode(0,0,depth);
		
	}
	root->xlim = Bx;
	root->ylim = By;

	// The dimension about which median is calculated
	int dim = depth % 2;
	// The size of the set
	size_t size = S.size();

	// Sort the set along dim axis
	if(dim==0)
	{
		sort(S.begin(), S.end(), sortby_x);
	}
	else
	{
		sort(S.begin(), S.end(), sortby_y);
	}

	// The median of the set having value along the dimension dim
	int median = (dim==0)? S[size/2].first : S[size/2].second;

	// Set up a child node
	int child_x=0,child_y=0;
	if(dim==0)
	{
		child_x = median;
	}
	else
	{
		child_y = median;
	}

	// Partition the set into two parts along size/2
	vector < pair<int, int> > L(size/2);
	vector < pair <int, int> > R(size - (size/2));

	int i=0,k=0;
	for(i=0;i<size/2;i++)
	{
		L[i].first = S[k].first;
		L[i].second = S[k].second; 
		k+=1;
	}

	for(int j=0;j<(size-(size/2));j++)
	{
		R[j].first = S[k].first;
		R[j].second = S[k].second;
		k+=1;
	}

	// Check if x dimension and set the boundary
	pair <int,int> Lx = Bx;
	pair <int,int> Ly = By;

	pair <int,int> Rx = Bx;
	pair <int,int> Ry = By;
	if(dim==0)
	{
		Lx.second = child_x;
		Rx.first = child_x;
	}
	else
	{
		Ly.second = child_y;
		Ry.first = child_y;
	}

	root->x = child_x;
	root->y = child_y;
	root->left = BuildTree(root->left, depth+1, L, Lx, Ly);
	root->right = BuildTree(root->right, depth+1, R, Rx, Ry);

	return root;

}

// Function to add all nodes recursively into a list
void add_all_nodes(Node *root, vector<pair<int,int> > &qlist)
{
	// Check if the Node is leaf, if yes then add it into the list
	if(root->left==NULL && root->right==NULL)
	{
		pair<int,int> p = {root->x, root->y};
		qlist.push_back(p);
		return;
	}
	add_all_nodes(root->left, qlist);
	add_all_nodes(root->right, qlist);
}

//Function to query the points in a given range of bounding box
void Query(Node *root, pair<int,int> &D1, pair<int,int> &D2, vector<pair<int,int> > &qlist)
{
	// Increment the counter for recording number of calls to Query
	::qpoint += 1;

	// Check if the Node is a leaf
	if(root->left == NULL && root->right==NULL)
	{
		if(checkBox(root->x, root->y, D1, D2))
		{
			pair<int,int> p = {root->x, root->y};
			qlist.push_back(p);
			
		}
		return;
	}

	// If the rectangle of query lies in the BB push all Nodes
	if(checkInBB(root->xlim, root->ylim, D1, D2))
	{
		add_all_nodes(root, qlist);
	}

	// Check if the query range intersects the BBox
	if(checkIntersection(root->xlim, root->ylim, D1, D2))
	{
		Query(root->left, D1, D2, qlist);
		Query(root->right, D1, D2, qlist);
	}
	return;

}


void print_val(Node *root)
{
	if(root!=NULL)
	{
		print_val(root->left);
		cout<<"depth"<<root->depth<<" "<<root->x<<" "<<root->y<<endl;
		print_val(root->right);
	}
		return;
}

int main()
{

	// Create dummy values in input.txt
	// write_values();

	// Create a KD Tree
	Node *root= createNode(0,0,0);

	// Accept the number of points from user
	int n;
	int choice=0,i=0;
	cout<<"Enter 1 for manually entering values, 0 otherwise"<<endl;
	cin>>choice;
	cout<<"Enter the number of points :"<<endl;
	cin>>n;
	vector <pair<int, int> > point(n);
	// Store the max value of x and y
	int maxx=-1,maxy=-1;	

	if(choice==0)
	{
		write_values(n);

		// open a file in read mode
		ifstream infile;
		infile.open("input.txt");

		int x=0,y=0;
		while(infile >> x >> y)
		{
			point[i].first = x;
			point[i].second = y;
			if(point[i].first > maxx)
			{
				maxx = point[i].first;
			}
			if(point[i].second > maxy)
			{
				maxy = point[i].second;
			}
			i+=1;
		}
	}
	else
	{	
		for(i=0;i<n;i++)
		{
			cout<<"Enter the "<<(i+1)<<"th point"<<endl;
			cin>>point[i].first;
			cin>>point[i].second;
			if(point[i].first > maxx)
			{
				maxx = point[i].first;
			}
			if(point[i].second > maxy)
			{
				maxy = point[i].second;
			}
		}
	}

	// Point to  define the limit of x and y boundary
	pair<int,int> Rx = {0,maxx};
	pair<int,int> Ry = {0,maxy};

	root = BuildTree(root, 0, point, Rx, Ry);

	// print_val(root);

	// Accept the points of the diagonal of the Query Rectangle
	cout<<"Enter the diagonals of the Query Rectangle that you want to search"<<endl;
	cout<<"Make sure that the points are in (L,L) (R,R) order"<<endl;
	cout<<"i.e. Lower-Left and Upper-Right points"<<endl;
	int x1,x2,y1,y2;
	cout<<"Enter 1st (x,y)"<<endl;
	cin>>x1>>y1;
	cout<<"Enter 2nd (x,y)"<<endl;
	cin>>x2>>y2;
	

	// List of nodes which might lie in a given range
	pair<int,int>D1 = {x1, y1};
	pair<int,int>D2 = {x2, y2};

	vector<pair<int,int> > qlist;

	Query(root, D1, D2, qlist);

	// Store the output points into output.txt
	ofstream outfile;
	outfile.open("output.txt");

	for(int i=0;i<qlist.size();i++)
	{
		outfile << qlist[i].first <<" "<<qlist[i].second <<endl;
	}
	outfile.close();

	cout << "Number of calls to BuildTree is "<<::crtree<<endl;
	cout << "Number of calls to Query is "<<::qpoint<<endl;
}