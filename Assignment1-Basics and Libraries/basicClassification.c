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
            return FALSE;
        }
        i++;
    }
    return TRUE;
}


int isStrong(int n){
    int num = n;
    int sum = 0;
    while(num > 0){
        int reminder = num % 10;
        sum += factorial(reminder);
        num = num / 10;
    }
    if (sum == n){return TRUE;}
    else{return FALSE;}
}

