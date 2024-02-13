#include<stdio.h>
#include<stdlib.h>
#include "my_mat.h"

#ifndef N
#define N 10 
#endif

int copy[N][N];

void createMatrix(int matrix[N][N]){
    int i, j;
    
    for(i =0; i< 10; i++){
        for(j=0; j<10; j++){
            scanf("%d", &matrix[i][j]);
            copy[i][j] = matrix[i][j];

        }
    }
}

void shortestPath(int x, int y , int matrix[N][N]){
    int i, j, k;

    for(k = 0; k < N; k++)
    {
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                if (copy[i][k] != 0 && copy[k][j] != 0)
                {
                    if(copy[i][j] > (copy[i][k] + copy[k][j]) || copy[i][j] == 0)
                        copy[i][j] = copy[i][k] + copy[k][j];
                }
            }
        }
    }
    if (copy[x][y] == 0 ||x == y){
        printf("-1\n");
    }
    else{
    printf("%d\n" ,copy[i][j]);
    }
}

void existPath(int x, int y, int matrix[N][N]){
    if(copy[x][y] !=0 && x!=y){
       printf("True\n");
    }
       else {
       printf("False\n");
       }
    
}
