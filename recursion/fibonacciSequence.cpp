#include <iostream>
#include <cmath>
using namespace std;

int get_n_fib_member(int n);

int main(int argc, char const *argv[]) {
    int fibonachi_num;
    cout << "Enter the N-th fibonachi member: ";
    cin >> fibonachi_num;
    cout << "The fibonachi number is == " << get_n_fib_member(fibonachi_num);

    cout << endl;
    return 0;
}

int get_n_fib_member(int n){
    if(n == 1){
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    if(n > 1){
        return get_n_fib_member(n-1) + get_n_fib_member(n-2);
    }
}
