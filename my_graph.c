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
   scanf(" %c", &n);

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
        existPath(i , j, matrix);
    }
    if (n == 'C')
    {
        scanf(" %d" , &i);
        scanf(" %d" , &j);
        int shortest=shortestPath(i , j, matrix);
        if(shortest==-1){
            printf("-1\n");
        }else{
           printf("%d\n" ,shortest); 
        }
    }
    
    scanf(" %c", &n);
}
}
