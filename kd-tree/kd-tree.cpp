#include <bits/stdc++.h>

using namespace std;


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

Node *createNode(int x, int y, int depth)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;
	temp->depth = depth;
	temp->x = x;
	temp->y = y;
	return temp;

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

// Function to check if the given rectangle lies in the Bounding box
bool checkInBB(pair<int,int> &Xlim, pair<int,int> &Ylim, pair<int,int> &D1, pair<int,int> &D2)
{
	// Check if x lies inside the range
	if((D1.first > Xlim.first && D1.first < Xlim.second) && (D2.first > Xlim.first && D2.first < Xlim.second))
	{
		if((D1.second > Ylim.first && D1.second < Ylim.second) && (D2.second > Ylim.first && D2.second < Ylim.second))
		{
			return true;
		}
	}
	return false;
}

// Function to check if query rectangle intersects the BBox

bool checkIntersection(pair<int,int> &Xlim, pair<int,int> &Ylim, pair<int,int> &D1, pair<int,int> &D2)
{
	// Make sure only 1 diagonal lies inside the BBox
	// Check if first point lies inside
	if((D1.first > Xlim.first && D1.first < Xlim.second))
	{
		if((D1.second > Ylim.first && D1.second < Ylim.second))
		{
			if(!(D2.first > Xlim.first && D2.first < Xlim.second) || !(D2.second > Ylim.first && D2.second < Ylim.second))
			{
				return true;
			}
		}
	}

	// Same for 2nd point
	else if((D2.first > Xlim.first && D2.first < Xlim.second))
	{
		if((D2.second > Ylim.first && D2.second < Ylim.second))
		{
			if(!(D1.first > Xlim.first && D1.first < Xlim.second) || !(D1.second > Ylim.first && D1.second < Ylim.second))
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}

}

Node* BuildTree(Node *root, int depth, vector< pair <int,int> > &S, pair <int,int>&Bx , pair <int,int> &By)
{

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
	// Check if the Node is a leaf
	if(root->left == NULL && root->right==NULL)
	{
		if(checkInBB(root->xlim, root->ylim, D1, D2))
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
	// Create a KD Tree
	Node *root= createNode(0,0,0);

	int points[7][2] = {{3, 6}, {17, 15}, {13, 16}, {6, 12}, 
                       {9, 1}, {2, 7}, {10, 19}};

	vector <pair<int, int> > point(7);
	int i=0;
	// Store the max value of x and y
	int maxx=-1,maxy=-1;
	for(i=0;i<7;i++)
	{
		point[i].first = points[i][0];
		point[i].second = points[i][1];
		if(points[i][0] > maxx)
		{
			maxx = points[i][0];
		}
		if(points[i][1] > maxy)
		{
			maxy = points[i][1];
		}
	}

	// Point to  define the limit of x and y boundary
	pair<int,int> Rx = {0,maxx+2};
	pair<int,int> Ry = {0,maxy+2};

	root = BuildTree(root, 0, point, Rx, Ry);

	// print_val(root);

	// List of nodes which might lie in a given range
	pair<int,int>D1 = {12,14};
	pair<int,int>D2 = {18, 20};

	vector<pair<int,int> > qlist;

	Query(root, D1, D2, qlist);

	cout<<"HEY";
}