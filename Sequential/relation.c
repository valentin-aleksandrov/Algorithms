#include <stdio.h>
#include <stdlib.h>

int isRealeationTrue(int* array, int size){
    int i;
    for (i = 1; i < size-1; i++) {
        if(i % 2 == 0){
            if ((array[i] >= array[i-1]) || (array[i] >= array[i+1])) {
                return 0;
            }
        } else {
            if ((array[i] <= array[i-1]) || (array[i] <= array[i+1])) {
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int array[] = {1,100,2,99,3,97,4,96,5,95,6,94};
    // int array[] = {1,4,2,3,1};
    int size = sizeof(array)/sizeof(int);
    if (isRealeationTrue(array,size)) {
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}
