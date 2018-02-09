#include <iostream>

using namespace std;

void bubble_sort(int* arr, int size);
void swap(int* a, int* b);
void print_arr(int* arr, int size);
int binary_search(int* arr, int size, int value);

int main(int argc, char const *argv[]) {
    int arr[]={2,4,10,43,4,5,8,9,7,0,8,10,45,44,39};
    int arr_size = 15;
    bubble_sort(arr,arr_size);
    print_arr(arr,arr_size);

    cout << "***********************" << endl;
    cout << binary_search(arr,arr_size,39) << endl;
    return 0;
}
int binary_search(int* arr, int size, int element){
    int l = 0;
    int r = size - 1;
    int m = (l+r)/2;
    while(l <= r){
        if(arr[m] == element){
            return m;
        } else if(arr[m] > element){
            r = m - 1;
        } else{
            l = m + 1;
        }
        m = (l+r)/2;
    }
    return -1; // if there is no such element
}
void bubble_sort(int* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size - i; j++){
            if(arr[j-1] > arr[j]){
                swap(&arr[j-1],&arr[j]);
            }
        }
    }
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_arr(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}
