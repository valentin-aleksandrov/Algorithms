#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
    struct node *prev;
};

void initialiseList(struct node **head, struct node **tail, int firstNumber){
    (*head) = (struct node*) malloc(sizeof(struct node));
    (*head)->number = firstNumber;
    (*head)->next = NULL;
    (*head)->prev = NULL;
    *tail = *head;
}
void printElements(struct node *head){
    while(head != NULL){
        printf("%d | ",head->number);
        head = head->next;
    }
    printf("\n");
}
void reverseElementsPrinting(struct node *tail){
    while(tail != NULL){
        printf("%d | ",tail->number);
        tail = tail->prev;
    }
    printf("\n");
}

void push(struct node **head, int number){
    struct node *newElement = (struct node*) malloc(sizeof(struct node));
    newElement->number = number;
    newElement->next = *head;
    (*head)->prev = newElement;
    *head = newElement;
}
void addBack(struct node **tail, int number){
    struct node *newElement = (struct node*) malloc(sizeof(struct node));
    newElement->number = number;
    (*tail)->next = newElement;
    newElement->prev = *tail;
    newElement->next = NULL;
    *tail = newElement;
}
int getSize(struct node *head){
    struct node *currentElement = head;
    int counter = 0;
    while (currentElement != NULL) {
        counter++;
        currentElement = currentElement->next;
    }
    return counter;
}

struct node* findByIndex(struct node *head, int index){
    struct node *currentElement = head;
    if((index >= getSize(head)) || (index < 0)){
        printf("No such element\n");
        return NULL;
    }
    int i;
    for(i = 0; i < index; i++, currentElement = currentElement->next);
    return currentElement;
}
void insert(struct node **head, struct node **tail, int position, int number){
    int size = getSize(*head);
    if(position < 0 || position > size){ // debug 1
        puts("Invalid position");
        return;
    }
    struct node *currentElement = findByIndex(*head,position);
    if (currentElement == NULL) {
        addBack(&(*tail),number);
        return;
    }
    if(currentElement->prev == NULL){
        push(&(*head),number);
    } else {
        currentElement = currentElement->prev;
        struct node *newElement = (struct node*) malloc(sizeof(struct node));
        newElement->number = number;
        newElement->next = currentElement->next;
        currentElement->next = newElement;
        newElement->prev = currentElement;
        struct node *after = newElement->next;
        after->prev = newElement;
    }
}
int isEmpty(struct node *head){
    if (head == NULL) {
        return 1;
    }
    return 0;
}
struct node* pop(struct node **head){
    if(isEmpty(*head)){
        return NULL;
    }

    struct node *popElement = *head;
    *head = (*head)->next;
    (*head)-> prev = NULL;
    popElement->next = NULL;
    popElement->prev = NULL;
    return popElement;
}

struct node* removeFromTail(struct node **tail){
    if(isEmpty(*tail)){
        return NULL;
    }
    struct node *popElement = *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    return popElement;
}
void freeList(struct node **tail, struct node **head){
    struct node *oldElement = NULL;
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

struct node* removeFromIndex(struct node **head, struct node **tail, int index){
    if (isEmpty(*head)) {
        return NULL;
    } else if(index == 0){
        return pop(&(*head));
    } else if (index == getSize(*head) - 1) {
        return removeFromTail(&(*tail));
    } else {
        struct node *currentElement = findByIndex(*head,index);
        struct node *prevElement = currentElement->prev;
        struct node *afterElement = currentElement->next;
        prevElement->next = currentElement->next;
        afterElement->prev = prevElement;
        currentElement->next = NULL;
        currentElement->prev = NULL;
        return currentElement;
    }
}

int main(){
    struct node *head = NULL;
    struct node *tail = NULL;

    initialiseList(&head,&tail,10);
    push(&head,8);
    addBack(&tail,20);
    addBack(&tail,30);
    addBack(&tail,40);
    addBack(&tail,50);
    addBack(&tail,60);
    insert(&head, &tail,1, 180);
    printElements(head);

    freeList(&tail,&head);
    return 0;
}
