#include "NumClass.h"

int power(int a, int b){
    if (b == 0){return TRUE;}
    return a * power(a,b-1);
}


int countDigits(int n){
    int num = n;
    int digits = 0;
    while(num > 0){
        digits++;
        num = num / 10;
    }
    return digits;
}


int isArmstrong(int n){
    int num = n;
    int digits = countDigits(n);
    int sum = 0;
    while (num > 0) {
        int reminder = num % 10;
        sum += power(reminder, digits);
        num = num / 10;
    }
    if(sum == n){return 1;}
    else{return 0;}
}


int isPalindrome(int n){
    int num = n;
    int digits = countDigits(n);
    int arrOfDigits[digits];
    int i;
    for(i = 0; i < digits; i++){
        arrOfDigits[i] =  num % 10;
        num = num / 10;
    }
    int j = digits -1;
    for(i = 0; i <= digits/2; i++){
        if(arrOfDigits[i] == arrOfDigits[j]){
            j--;
        }
        else{return 0;}
    }
    return 1;
}

