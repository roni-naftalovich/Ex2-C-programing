#ifndef MY_MAT_H
#define MY_MAT_H
#define N 10
#define SIZE 5
#define W 20

void existPath(int i, int j, int[N][N]);
int shortestPath(int i , int j, int[N][N]);
void createMatrix(int matrix[N][N]);
int KnapSack(int weight[], int value[], int selected_boll[]);

#endif
