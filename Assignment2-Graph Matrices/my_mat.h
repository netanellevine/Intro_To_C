#include <stdio.h>

/*
 this function is the A function - receiving the variables of the matrix
 */
void entermat(int mat[10][10]);

/*
  this function using the Floyd Warshall algorithm
 */
void floyd_warshall_algo(int mat[10][10]);

/*
  this is the function for option 'B' - receiving the two verticals and returning if there is a path - if there is
  the function return 1 for true, if there is not the function return 0 for false
 */
int pathExists(int mat[10][10], int i, int j);

/*
  this is the function for option 'C' - receiving the two verticals and returning if there is a path - if there is
  the function return the shortest, if there is not the function return -1
 */
int shortestPath(int mat[10][10], int i, int j);

/*
 receiving 2 numbers and returning the smallest one
 */
int min(int a, int b);