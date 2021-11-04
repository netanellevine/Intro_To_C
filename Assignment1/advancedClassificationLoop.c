#include "NumClass.h"

int power(int a, int b){
    if (b == 0){return 1;}
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
    if(sum == n){return TRUE;}
    else{return FALSE;}
}

// I was told to change it because I used the array without knowing it's size.
//int isPalindrome(int n){
//    int num = n;
//    int digits = countDigits(n);
//    int arrOfDigits[digits];
//    int i;
//    for(i = 0; i < digits; i++){
//        arrOfDigits[i] =  num % 10;
//        num = num / 10;
//    }
//    int j = digits -1;
//    for(i = 0; i <= digits/2; i++){
//        if(arrOfDigits[i] == arrOfDigits[j]){
//            j--;
//        }
//        else{return FALSE;}
//    }
//    return TRUE;
//}

int isPalindrome(int n){
    int num = n, sum = 0;
    while (n >= 0){
        int reminder = n % 10;
        n = n / 10;
        sum = sum * 10 + reminder;
    }
    if( sum == num){return TRUE;}
    else{return FALSE;}
}
