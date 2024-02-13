#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_mat.h"
#define S 5
#define W 20

int max(int n1, int n2){
    if(n1 > n2)
        return n1;
    return n2;
 }
 
 int KnapSack(int weight[], int value[], int selected_boll[]){
    int i, j;
    int K[S+1][W+1];

    for (i = 0; i <= S; i++)
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

    i = S;
    j = W;
    while (j > 0 && i > 0)
    {
        while (i > 0 && K[i][j] == K[i-1][j])
        {
            i--;
        }
        selected_boll[i-1] = 1;
        j -= weight[i-1];
        i--;
    }
    return K[S][W];
 }
    

int main(){
    int selected[S];
    char items[S][21];
    int value[S];
    int weight[S];
    int i, j = 0;
    char result[S][21];

    for (i = 0; i < S; i++)
    {
        scanf("%20s", items[i]);
        scanf("%d", &value[i]);
        scanf("%d", &weight[i]);
        selected[i] = 0;
    }

    int maxValue = KnapSack(weight,value, selected);
    printf("Maximum profit: %d\n", maxValue);
    printf("Selected items:");

    for (i = 0; i < S; i++)
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
