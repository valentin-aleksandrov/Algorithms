#include <stdio.h>

void printElements(int* array, int lastIndex){
    if (lastIndex == 0) {
        printf("%d ", array[lastIndex]);
        return;
    }
    printf("%d ", array[lastIndex]);
    printElements(array,lastIndex-1);
}

int main(){
    int array[] = {2,4,10,20,30};
    int size = 5;
    printElements(array,size-1);
    puts("");
    return 0;
}
