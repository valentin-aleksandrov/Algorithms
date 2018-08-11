#include <stdio.h>
#include <stdlib.h>

struct tree{
    int number;
    struct tree *left;
    struct tree *right ;
};

struct tree *newTree(int number){
    struct tree *newElement = (struct tree*) malloc(sizeof(struct tree));
    newElement->number = number;
    newElement->left = NULL;
    newElement->right = NULL;
    return newElement;
}

void printAllPositiveNumbers(struct tree *root){
    if (root != NULL){
        printAllPositiveNumbers(root->left);
        if (root != NULL){
            if (root->number > 0) {
                printf("%d |", root->number);
            }
        }
        printAllPositiveNumbers(root->right);
    }
}

void printAllNegativeNumbers(struct tree *root){
    if (root != NULL){
        printAllNegativeNumbers(root->left);
        if (root != NULL){
            if (root->number < 0) {
                printf("%d |", root->number);
            }
        }
        printAllNegativeNumbers(root->right);
    }
}

int main(){
    struct tree *root = newTree(1);
    root->left = newTree(2);
    root->right = newTree(-3);
    root->left->left = newTree(4);
    root->right->left = newTree(-58);
    root->right->right = newTree(-60);
    root->right->left->right = newTree(7);
    root->right->right->right = newTree(8656);
    root->right->left->right->left = newTree(9);

    puts("All positive numbers from the binary tree:");
    printAllPositiveNumbers(root);
    puts("");

    puts("All negative numbers from the binary tree:");
    printAllNegativeNumbers(root);
    puts("");

    return 0;
}
