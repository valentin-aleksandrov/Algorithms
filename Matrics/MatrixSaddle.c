#include <stdio.h>
#define N 3

int isElementMaxRowMinCol(int matrix[N][N], int i, int j){
    int x;
    int element = matrix[i][j];
    int maxElement = matrix[i][0];
    for (x = 1; x < N; x++) {
        if(matrix[i][x] > maxElement){
            maxElement = matrix[i][x];
        }
    }
    if(element < maxElement){
        return 0;
    }

    int minElement = matrix[0][j];
    for (x = 1; x < N; x++) {
        if(matrix[x][j] < minElement){
            minElement = matrix[x][j];
        }
    }
    if (element > minElement) {
        return 0;
    }
    return 1;
}

int isElementMinRowMaxCol(int matrix[N][N], int i, int j){
    int x;
    int element = matrix[i][j];
    int maxElement = matrix[0][j];
    for (x = 1; x < N; x++) {
        if(matrix[x][j] > maxElement){
            maxElement = matrix[x][j];
        }
    }
    if(element < maxElement){
        return 0;
    }

    int minElement = matrix[i][0];
    for (x = 1; x < N; x++) {
        if(matrix[i][x] < minElement){
            minElement = matrix[i][x];
        }
    }
    if (element > minElement) {
        return 0;
    }
    return 1;
}
int isElementUnqueOnThisRowColumn(int matrix[N][N], int i, int j){
    int x,y;
    int currentNumber = matrix[i][j];
    for(x = 0; x < N; x++){
        if(x == j) {
            continue;
        }
        if (matrix[i][x] == currentNumber) {
            return 0;
        }
    }
    for(x = 0; x < N; x++){
        if(x == i) {
            continue;
        }
        if (matrix[x][j] == currentNumber) {
            return 0;
        }
    }
    return 1;
}
int main(){
    int matrix[N][N] = {{1,2,80}, {4,3,80}, {9,50,79}};
    int i,j;
    int counter = 0;
    for (i = 0; i < N; i++) {
        for(j = 0; j < N; j++){
            if (isElementUnqueOnThisRowColumn(matrix,i,j)) {
                if(isElementMaxRowMinCol(matrix,i,j) || isElementMinRowMaxCol(matrix,i,j)){
                    counter++;
                }
            }
        }
    }
    printf("Броя на седла == %d\n", counter);
    return 0;
}
