// C++ program to for Kinight's tour problem usin 
// Warnsdorff's algorithm 
#include <bits/stdc++.h> 
// int N = 8;

using namespace std;

// Move pattern on basis of the change of 
// x coordinates and y coordinates respectively 
static int cx[8] = {1,1,2,2,-1,-1,-2,-2}; 
static int cy[8] = {2,-2,1,-1,2,-2,1,-1}; 

// function restricts the knight to remain within 
// the 8x8 chessboard 
bool limits(int x, int y, int N) 
{ 
	return ((x >= 0 && y >= 0) && (x < N && y < N)); 
} 

/* Checks whether a square is valid and empty or not */
bool isempty(int a[], int x, int y, int N) 
{ 
	return (limits(x, y, N)) && (a[y*N+x] < 0); 
} 

/* Returns the number of empty squares adjacent 
to (x, y) */
int getDegree(int a[], int x, int y, int N) 
{ 
	int count = 0; 
	for (int i = 0; i < N; ++i) 
		if (isempty(a, (x + cx[i]), (y + cy[i]), N)) 
			count++; 

	return count; 
} 

// Picks next point using Warnsdorff's heuristic. 
// Returns false if it is not possible to pick 
// next point. 
bool nextMove(int a[], int *x, int *y, int N) 
{ 
	int min_deg_idx = -1, c, min_deg = (N+1), nx, ny; 

	// Try all N adjacent of (*x, *y) starting 
	// from a random adjacent. Find the adjacent 
	// with minimum degree. 
	int start = rand()%N; 
	for (int count = 0; count < N; ++count) 
	{ 
		int i = (start + count)%N; 
		nx = *x + cx[i]; 
		ny = *y + cy[i]; 
		if ((isempty(a, nx, ny, N)) && 
		(c = getDegree(a, nx, ny, N)) < min_deg) 
		{ 
			min_deg_idx = i; 
			min_deg = c; 
		} 
	} 

	// IF we could not find a next cell 
	if (min_deg_idx == -1) 
		return false; 

	// Store coordinates of next point 
	nx = *x + cx[min_deg_idx]; 
	ny = *y + cy[min_deg_idx]; 

	// Mark next move 
	a[ny*N + nx] = a[(*y)*N + (*x)]+1; 

	// Update next point 
	*x = nx; 
	*y = ny; 

	return true; 
} 

/* displays the chessboard with all the 
legal knight's moves */
void print(int a[], int N) 
{ 
	for (int i = 0; i < N; ++i) 
	{ 
		for (int j = 0; j < N; ++j) 
			cout<<a[j*N+i]<<"\t"; 
		cout<<endl; 
	} 
} 

/* checks its neighbouring sqaures */
/* If the knight ends on a square that is one 
knight's move from the beginning square, 
then tour is closed */
bool neighbour(int x, int y, int xx, int yy, int N) 
{ 
	for (int i = 0; i < 8; ++i) 
		if (((x+cx[i]) == xx)&&((y + cy[i]) == yy)) 
			return true; 

	return false; 
} 

/* Generates the legal moves using warnsdorff's 
heuristics. Returns false if not possible */
bool findClosedTour(int N) 
{ 
	// Filling up the chessboard matrix with -1's 
	
	int a[N*N]; 
	for (int i = 0; i< N*N; ++i) 
		a[i] = -1; 

	// Randome initial position 
	int sx = rand()%N; 
	int sy = rand()%N; 

	// Current points are same as initial points 
	int x = sx, y = sy; 
	a[y*N+x] = 1; // Mark first move. 

	// Keep picking next points using 
	// Warnsdorff's heuristic 
	for (int i = 0; i < (N*N)-1; ++i) 
		if (nextMove(a, &x, &y, N) == 0) 
			return false; 
	
	// Check if tour is closed (Can end 
	// at starting point) 
	if (!neighbour(x, y, sx, sy, N)) 
		return false; 

	cout<<"1111";

	print(a, N); 
	return true; 
} 

// Driver code 
int main() 
{ 
	// To make sure that different random 
	// initial positions are picked. 
	srand(time(NULL)); 

	// Accept the value of N

	cout<<"Enter the size of the chessboard!"<<endl;
	int n;
	cin>>n;

	// ::N = n;

	// While we don't get a solution 
	while (!findClosedTour(n)) 
	{ 
	; 
	} 

	return 0; 
} 
