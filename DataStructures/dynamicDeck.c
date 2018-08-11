#include <stdio.h>
#include <stdlib.h>

struct deck {
    int number;
    struct deck *next;
    struct deck *prev;
};
void initialiseDeck(struct deck **head, struct deck **tail, int firstNumber){
    (*head) = (struct deck*) malloc(sizeof(struct deck));
    (*head)->number = firstNumber;
    (*head)->next = NULL;
    (*head)->prev = NULL;
    *tail = *head;
}
void pushFront(struct deck **head, int number){
    struct deck *newElement = (struct deck*) malloc(sizeof(struct deck));
    newElement->number = number;
    newElement->next = *head;
    (*head)->prev = newElement;
    *head = newElement;
}
void pushBack(struct deck **tail, int number){
    struct deck *newElement = (struct deck*) malloc(sizeof(struct deck));
    newElement->number = number;
    (*tail)->next = newElement;
    newElement->prev = *tail;
    newElement->next = NULL;
    *tail = newElement;
}
void printElements(struct deck *head){
    while(head != NULL){
        printf("%d | ",head->number);
        head = head->next;
    }
    printf("\n");
}
int isEmpty(struct deck *head){
    if (head == NULL) {
        return 1;
    }
    return 0;
}
struct deck* popFront(struct deck **head){
    if(isEmpty(*head)){
        return NULL;
    }

    struct deck *popElement = *head;
    *head = (*head)->next;
    (*head)-> prev = NULL;
    popElement->next = NULL;
    popElement->prev = NULL;
    return popElement;
}

struct deck* popBack(struct deck **tail){
    if(isEmpty(*tail)){
        return NULL;
    }
    struct deck *popElement = *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    return popElement;
}
void freeDeck(struct deck **head, struct deck **tail){
    struct deck *oldElement = NULL;
    while ((*tail) != NULL) {
        oldElement = *tail;
        *tail = (*tail)->prev;
        if (oldElement != NULL) {
            oldElement->next = NULL;
            oldElement->prev = NULL;
            free(oldElement);
        }
    }
    *head = NULL;
    *tail = NULL;
}
struct deck* peakFront(struct deck *head){
    return head;
}
struct deck* peakBack(struct deck *tail){
    return tail;
}

int main(){
    struct deck *head = NULL;
    struct deck *tail = NULL;
    initialiseDeck(&head,&tail,8);
    pushFront(&head,10);
    pushFront(&head,12);
    pushFront(&head,13);
    pushFront(&head,15);
    pushBack(&tail, -2);
    pushBack(&tail, -20);
    pushBack(&tail, -2250);

    popBack(&tail);
    popBack(&tail);
    printElements(head);
    return 0;
}
