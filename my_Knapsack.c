#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_mat.h"
#define SIZE 5
#define W 20


int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
 
 int KnapSack(int weight[], int value[], int selected_bool[]){
    int i, j;
    int K[SIZE+1][W+1];

    for (i = 0; i <= SIZE; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
               K[i][j] = 0;
            else if (weight[i-1] <= j){
                K[i][j] = max(value[i-1] + K[i-1][j-weight[i-1]], K[i-1][j]);
            }
            else
                K[i][j] = K[i-1][j];
        }
    }

    i = SIZE;
    j = W;
    while (j > 0 && i > 0)
    {
        while (i > 0 && K[i][j] == K[i-1][j])
        {
            i--;
        }
        selected_bool[i-1] = 1;
        j -= weight[i-1];
        i--;
    }
    return K[SIZE][W];
 }
    

int main(){
    int selected[SIZE];
    char items[SIZE][21];
    int value[SIZE];
    int weight[SIZE];
    int i, j = 0;
    char result[SIZE][21];

    for (i = 0; i < SIZE; i++)
    {
        scanf("%20s", items[i]);
        scanf("%d", &value[i]);
        scanf("%d", &weight[i]);
        selected[i] = 0;
    }

    int maxValue = KnapSack(weight,value, selected);
    printf("Maximum profit: %d\n", maxValue);
    printf("Selected items:");

    for (i = 0; i < SIZE; i++)
    {
        if (selected[i] == 1)
        {
            strcpy(result[j], items[i]);
            j++;
        }
        
    }
    
    for (i = 0; i < j; i++)
    {
        printf(" %s", result[i]);
    } 
}
