#include<stdio.h>
#include "my_mat.h"


int main(){

    int matrix[N][N];
    int i;
    int j;
    char n;
    scanf("%c", &n);

while (n != 'A')
{
   scanf("%c", &n);

}

createMatrix(matrix);
while(n != 'D' && n != EOF){
    if(n == 'A'){
        createMatrix(matrix);
    }
    if (n == 'B')
    {
        scanf(" %d" , &i);
        scanf(" %d" , &j);
        existPath(i , j);
    }
    if (n == 'C')
    {
        scanf(" %d" , &i);
        scanf(" %d" , &j);
        shortestPath(i , j);
    }
    
    (" %c", &n);
}
}
