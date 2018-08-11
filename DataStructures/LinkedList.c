#include <stdio.h>
#include <stdlib.h>

struct node{
int number;
struct node* next;
};
struct node* pushFront(struct node* head, int value) {
    if (head == NULL) {
        head = (struct node*) malloc (sizeof(struct node));
        head->number = value;

        return head;
    }
    struct node* newElement = (struct node*) malloc (sizeof(struct node));
    newElement->number = value;
    newElement->next = head;

    head = newElement;
    return head;
}
struct node* pushBack (struct node* head, int value) {
    if (head == NULL) {
        head = (struct node*) malloc (sizeof(struct node));
        head->number = value;

        return head;
    }
    struct node* newElement = (struct node*) malloc (sizeof(struct node));
    newElement->number = value;
    newElement->next = NULL;
    struct node* currentElement = head;
    while (currentElement->next != NULL) {
        currentElement = currentElement->next;
    }
    currentElement->next = newElement;
    return head;
}
struct node* insertElement (struct node* head, int value, int index) {
    struct node* currentElement = head;

    struct node* newElement = (struct node*) malloc (sizeof(struct node));
    newElement->number = value;
    newElement->next = NULL;
    int i;

    for (i = 0; i < index-1; i++) {
        if (currentElement->next == NULL) {
            puts("Invalid index!");
            return head;
        }
        currentElement = currentElement->next;
    }
    newElement->next = currentElement->next;
    currentElement->next = newElement;
    return head;
}

int main() {
    struct node* head = NULL;
    head = pushFront(head, 7);
    head =  pushFront(head, 3);
    head = pushBack(head, 18);
    head = insertElement(head, 8, 1);
    printf("The value is == %d\n", head->number);
    printf("The value is == %d\n", head->next->number);
    printf("The value is == %d\n", head->next->next->number);
    printf("The value is == %d\n", head->next->next->next->number);
    return 0;
}
