#include <stdio.h>
#include <stdlib.h>

struct tree{
    int number;
    struct tree *left;
    struct tree *right ;
};

struct tree *newTree(int nu#include <stdio.h>
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

void findEvenNumbersCount(struct tree *root, int* sum){
    if (root != NULL){
        findEvenNumbersCount(root->left,&(*sum));
        if (root != NULL){
            if (root->number != 0 && root->number % 2 == 0) {
                (*sum) += root->number;
            }
        }
        findEvenNumbersCount(root->right,&(*sum));
    }
}

int main(){
    struct tree *root = newTree(1);
    root->left = newTree(2);
    root->right = newTree(3);
    root->left->left = newTree(4);
    root->right->left = newTree(5);
    root->right->right = newTree(6);
    root->right->left->right = newTree(7);
    root->right->right->right = newTree(8);
    root->right->left->right->left = newTree(9);

    int sum = 0;
    findEvenNumbersCount(root,&sum);
    printf("Сума на върховете, които са с четни числа == %d\n", sum);
    return 0;
}
mber){
    struct tree *newElement = (struct tree*) malloc(sizeof(struct tree));
    newElement->number = number;
    newElement->left = NULL;
    newElement->right = NULL;
    return newElement;
}

void findEvenNumbersCount(struct tree *root, int* evenNumbersCount){
    if (root != NULL){
        findEvenNumbersCount(root->left,&(*evenNumbersCount));
        if (root != NULL){
            if (root->number != 0 && root->number % 2 == 0) {
                (*evenNumbersCount)++;
            }
        }
        findEvenNumbersCount(root->right,&(*evenNumbersCount));
    }
}

int main(){
    struct tree *root = newTree(1);
    root->left = newTree(2);
    root->right = newTree(3);
    root->left->left = newTree(4);
    root->right->left = newTree(5);
    root->right->right = newTree(6);
    root->right->left->right = newTree(7);
    root->right->right->right = newTree(8);
    root->right->left->right->left = newTree(9);

    int counter = 0;
    findEvenNumbersCount(root,&counter);
    printf("Count of even Numbers == %d\n", counter);
    return 0;
}
