// C program for Knight Tour problem 
#include<stdio.h> 
#include <bits/stdc++.h>

using namespace std;
// #define N 8 
  
int solveKTUtil(int x, int y, int movei, int **sol, 
                int xMove[],  int yMove[], int N); 
  
/* A utility function to check if i,j are valid indexes 
   for N*N chessboard */
bool isSafe(int x, int y, int **sol, int N) 
{ 
    return ( x >= 0 && x < N && y >= 0 && 
             y < N && sol[x][y] == -1); 
} 
  
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int **sol, int N) 
{ 
    for (int x = 0; x < N; x++) 
    { 
        for (int y = 0; y < N; y++) 
            printf(" %2d ", sol[x][y]); 
        printf("\n"); 
    } 
} 
  
/* This function solves the Knight Tour problem using 
   Backtracking.  This function mainly uses solveKTUtil() 
   to solve the problem. It returns false if no complete 
   tour is possible, otherwise return true and prints the 
   tour. 
   Please note that there may be more than one solutions, 
   this function prints one of the feasible solutions.  */
bool solveKT(int N) 
{ 
    int **sol = (int **)malloc(N * sizeof(int *));
    for(int i=0;i<N;i++)
    {
        sol[i] = (int *)malloc(N*sizeof(int));
    }
    
    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++) 
        for (int y = 0; y < N; y++) 
            sol[x][y] = -1; 
  
    /* xMove[] and yMove[] define next move of Knight. 
       xMove[] is for next value of x coordinate 
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
  
    // Since the Knight is initially at the first block 
    sol[0][0]  = 0; 
  
    /* Start from 0,0 and explore all tours using 
       solveKTUtil() */
    if (solveKTUtil(0, 0, 1, &sol[0], xMove, yMove, N) == false) 
    { 
        printf("Solution does not exist"); 
        return false; 
    } 
    else
        printSolution(sol, N); 
  
    return true; 
} 
  
/* A recursive utility function to solve Knight Tour 
   problem */
int solveKTUtil(int x, int y, int movei, int **sol, 
                int *xMove, int *yMove, int N) 
{ 
   int k, next_x, next_y; 
   if (movei == N*N) 
       return true; 
  
   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < N; k++) 
   { 
       next_x = x + xMove[k]; 
       next_y = y + yMove[k]; 
       if (isSafe(next_x, next_y, sol, N)) 
       { 
         sol[next_x][next_y] = movei; 
         if (solveKTUtil(next_x, next_y, movei+1, sol, 
                         xMove, yMove, N) == true) 
             return true; 
         else
             sol[next_x][next_y] = -1;// backtracking 
       } 
   } 
  
   return false; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    cout<<"Enter the dimensions!";
    int n;
    cin>>n;
    solveKT(n); 
    return 0; 
} 