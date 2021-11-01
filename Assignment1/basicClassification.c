#include "NumClass.h"

int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}


int isPrime(int n){
    int i = 2;
    while(i <= n/2){
        if(n % i == 0){
            return 0;
        }
        i++;
    }
    return 1;
}


int isStrong(int n){
    int num = n;
    //int digits = countDigits(n);
    int sum = 0;
    while(num > 0){
        int reminder = num % 10;
        sum += factorial(reminder);
        num = num / 10;
    }
    if (sum == n){return 1;}
    else{return 0;}
}

