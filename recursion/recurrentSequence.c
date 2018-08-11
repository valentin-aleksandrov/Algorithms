#include <stdio.h>

long getPower(int base, int power){
    if (power == 1) {
        return base;
    }
    return base * getPower(base,power-1);
}

long getFactorial(int number){
    if (number == 0) {
        return 1;
    }
    return number * getFactorial(number-1);
}
int main(){
    printf("%ld\n", getPower(3,20));
    printf("%ld\n", getFactorial(20));
    return 0;
}
