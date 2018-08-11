#include <stdio.h>
#define BUFFER_SIZE 50

void testingPrinting(int* deck){
    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ",deck[i]);
    }
    printf("\n");
}

void initializesDeck(int* deck){
    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        deck[i] = 0;
    }
}
int isFull(int size){
    if (size < BUFFER_SIZE) {
        return 0;
    }
    return 1;

}
int isEmpty(int size){
    if(size == 0){
        return 1;
    }
    return 0;
}
int pop(int* deck, int* size){
    if(!isEmpty(*size)){
        (*size)--;
        int element = deck[(*size)];
        deck[(*size)] = 0;
        return element;
    }
    printf("The Deck is empty\n");
    return 0;
}
void push(int* deck, int* size, int element){
    if (isFull(*size)) {
        printf("The deck is full\n");
        return;
    }
    deck[(*size)] = element;
    (*size)++;
}
int peek(int* deck, int size){
    if(!isEmpty(size)){
        return deck[size - 1];
    }
    printf("The deck is empty\n");
    return 0;
}
int peekBack(int* deck, int size){
    if(!isEmpty(size)){
        return deck[0];
    }
    printf("The deck is empty\n");
    return 0;
}
void shiftElementsToLeft(int* deck, int size){
    int i;
    for (i = 1; i < size; i++) {
        deck[i-1] = deck[i];
    }
    deck[i-1] = 0;
}
int removeFirst(int* deck, int* size){
    if(isEmpty(*size)){
        printf("The deck is empty\n");
        return 0;
    }
    int element = deck[0];
    shiftElementsToLeft(deck,*size);
    (*size)--;
    return element;
}
void shiftElementsToRight(int* deck, int size){
    int i;
    for(i = size; i > 0; i--){
        deck[i] = deck[i-1];
    }
    deck[0] = 0;
}
void addFirst(int* deck, int* size, int element){
    if (isFull(*size)) {
        printf("The deck is full\n");
        return;
    }
    shiftElementsToRight(deck,*size);
    (*size)++;
    deck[0] = element;
}
int main(){
    int deck[BUFFER_SIZE];
    initializesDeck(deck);
    int size = 0;

    int number1 = 2;
    int number2 = 4;
    int number3 = 5;
    int number4 = 6;
    int number5 = 3;
    int number6 = 8;

    push(deck,&size, number1);
    push(deck,&size, number2);
    push(deck,&size, number3);
    addFirst(deck,&size,number4);
    testingPrinting(deck);

    printf("%d\n",removeFirst(deck, &size));
    printf("%d\n",removeFirst(deck, &size));

    testingPrinting(deck);
    return 0;
}
