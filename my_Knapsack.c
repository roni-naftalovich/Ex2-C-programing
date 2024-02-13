#include <stdio.h>
#include "my_mat.h"
#define SIZE 5
#define MAX_CAPACITY 20


int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapSack(int weights[], int values[], int selected_bool[]) {

    int i, w;
    int K[SIZE + 1][MAX_CAPACITY + 1];

    for (i = 0; i <= SIZE; i++) {
        for (w = 0; w <= MAX_CAPACITY; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    i = SIZE;
    w = MAX_CAPACITY;
    while (w > 0 && i > 0)
    {
        while (i > 0 && K[i][w] == K[i-1][w])
        {
            i--;
        }
        selected_bool[i-1] = 1;
        w -= weights[i-1];
        i--;
    }

    // Return the maximum value
    return K[SIZE][MAX_CAPACITY];
}
    

int main(){

char items[SIZE];
int weights[SIZE];
int values[SIZE];
int selected[SIZE];
int result[SIZE];
int i;

for(i=0;i<SIZE;i++){
    scanf("%c" , &items[i]);
    scanf("%d" , &weights[i]);
    scanf("%d" , &values[i]);
    selected[i]=0;
}

int maxValue = knapSack( weights, values, selected);
printf("Maximum profit: %d\n", maxValue);

for (i=0;i<SIZE;i++){
    if(selected[i] !=0){
        result[i]=selected[i];
    }
    else{
        result[i]=0;
    }}
    printf("Selected items:");
    for(i=0;i<SIZE;i++){
        if(result[i] !=0){
        printf(" %c", items[i]);
    }}


}
