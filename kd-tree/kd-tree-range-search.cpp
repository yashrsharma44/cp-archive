#include <bits/stdc++.h>

using namespace std;


// Defining a Node class for individual nodes
class Node
{
public:
	int point[2];
	Node *left, *right;
	int min[2] = {999, 999};
	int max[2] = {-999,-999};
};

Node* new_node(int *a)
{
	Node *temp = new Node();

	temp->left = temp->right = NULL;

	temp->point[0] = a[0];
	temp->point[1] = a[1];
	return temp;
}

// Function to insert a Node into the tree
Node *insert(Node *root, int *point, int depth)
{
	// Empty tree
	if(root == NULL)
		return new_node(point);

	// Current dimension of comparision
	int cd = depth % 2;
	// Set the min/max x and y points for a given root
	root->min[0] = (root->min[0] > point[0])? point[0] : root->min[0];
	root->min[1] = (root->min[1] > point[1])? point[1] : root->min[1];

	root->max[0] = (root->max[0] < point[0])? point[0] : root->max[0];
	root->max[1] = (root->max[1] < point[1])? point[1] : root->max[1];
		

	if(point[cd] < (root->point[cd])){
		root->left = insert(root->left, point, depth+1);
	}
	else
		root->right = insert(root->right, point, depth+1);

	return root;
}

// Function to check if two points are same
bool arePointSame(int *p1, int *p2)
{
	for(int i=0;i<2;i++)
	{
		if(p1[i]!=p2[i])
			return false;
	}
	return true;
}


// Helper function to check if a point
// lies inside a given rectangle
bool check_range(int *diag1, int *diag2, int *point)
{
	// Check if the x-coord lies between diag1 and diag2 x-coords
	// Similarly for y-coord lies between diag1 and diag2

	int small_x = diag1[0] <= diag2[0] ? diag1[0] : diag2[0];
	int big_x = diag1[0] >= diag2[0] ? diag1[0] : diag2[0];

	int small_y = diag1[1] <= diag2[1] ? diag1[1] : diag2[1];
	int big_y = diag1[1] >= diag2[1] ? diag1[1] : diag2[1];

	if((point[0] <= big_x) && (point[0] >= small_x))
	{
		if((point[1] <= big_y) && (point[1] >= small_y))
		{
			return true;
		}
	}
	return false;
}

// Function to find all the points inside a given rectangle
// Uses a vector list to store all the points

// void query(Node *root, int *in_point, int *diag1, int *diag2 , vector <int> &result)
// {
// 	// Check if the root is a leaf
// 	if(root->left == NULL && root->right == NULL)
// 	{
// 		if(check_range(diag1, diag2, root->point))
// 		{
// 			result.push_back(root->point);
// 		}
// 		return;
// 	}


// }

// subsetBB : This function checks if the point's range list lies inside 
// a given Node's bounding box

bool subsetBB(Node *root, int *diag1, int *diag2)
{

	// First we shall find the remaining points of the 
}


int main()
{
	Node *root = NULL;
	int points[][2] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, 
                       {9, 1}, {2, 7}, {10, 19}};
    for(int i=0; i<7;i++)
    {
    	root = insert(root, points[i], 0);
    }




}
