#include <stdio.h>
#include <stdlib.h>


void recursivePrinting(int* arr, int* sequenceIndexs, int index){
    int nextIndex = sequenceIndexs[index];

    if (sequenceIndexs[nextIndex] == -1) {
        printf("%d ", arr[nextIndex]);
        printf("%d ", arr[index]);

        return;
    }

    recursivePrinting(arr,sequenceIndexs, nextIndex);
    printf("%d ", arr[index]);
}
int getMaxElement(int* arr, int size){
    int max = arr[0];
    int i;
    for(i = 1; i < size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}
int getIndexOfMaxElement(int* arr, int size){
    int i;
    int index = 0;
    int max = arr[0];
    for(i = 1; i < size; i++){
        if (max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void printfLongestIncreasingSequence(int* arr, int* sequenceIndexs, int size){
    int startIndex = getIndexOfMaxElement(sequenceIndexs,size);
    recursivePrinting(arr,sequenceIndexs, startIndex);
}

int main(){
    int arr[] = {9, 8, 40, 5, 30, 1, 0};
    int size = sizeof(arr)/sizeof(int);
    int longestSubSequencesLenghts[size];
    int longestSubSequence[size];
    int i;
    for(i = 0; i < size; i++){
        longestSubSequencesLenghts[i] = 1;
        longestSubSequence[i] = -1;
    }

    int j;
    for (i = 1; i < size; i++) {
        for(j = 0; j < i; j++){
            if (arr[j] > arr[i]) { // test 1
                int currentLenght = longestSubSequencesLenghts[i];
                int newLenght = longestSubSequencesLenghts[j]+1;
                if (currentLenght > newLenght) {
                    longestSubSequencesLenghts[i] = currentLenght;
                } else {
                    longestSubSequencesLenghts[i] = newLenght;
                    longestSubSequence[i] = j;
                }

            }
        }
    }
    int x;
    for(x = size - 1,i=0; x >= 0; x--){
        printf("Subsequence[%d] lenght == %d \n",i++, longestSubSequencesLenghts[x]);
    }
    printf("The longest decrising subsequence is of lenght:");
    printf("%d\n",getMaxElement(longestSubSequencesLenghts,size));
    puts("Here is the longest decrising SubSequence:");
    printfLongestIncreasingSequence(arr,longestSubSequence,size);
    puts("");
    return 0;
}
