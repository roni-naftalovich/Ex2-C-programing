#include<stdio.h>
#include<stdbool.h>
#include "my_mat.h"

int copy[N][N];

int createMatrix(int matrix[10][10]){
    
    for(i =0; i< 10; i++){
        for(j=0; j<10; j++){
            scanf("%d", &matrix[i][j]);
            copy[i][j] = matrix[i][j];

        }
    }
}

int shortestPath(int i , int j){
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
    if (copy[i][j] == 0 ||i == j){
        printf("-1\n");
    }
    else
    printf("%d\n" copy[i][j]);
}

void existPath(int i, int j){
    if(copy[i][j] !=0 && i!=j)
       printf("True\n");
       else 
       printf("False\n");
    
}
