#include "NumClass.h"
#include <stdio.h>

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


int isArmstrongRec(int num, int numOfDigits){
    if(num == 0){return 0;}
    int sum = 0;
    int reminder = num % 10;
    num = num / 10;
    sum += power(reminder, numOfDigits) + isArmstrongRec(num, numOfDigits);
    return  sum;
}


int isArmstrong(int n){
    int sum = isArmstrongRec(n, countDigits(n));
    if(sum == n) {return  TRUE;}
    else {return FALSE;}
}


int isPalindromeRec(int n, int sum){
    if(n == 0){return sum;}
    else {
        int num = sum;
        int reminder = n % 10;
        n = n / 10;
        num = num * 10 + reminder;
        return isPalindromeRec(n, num);
    }
}


int isPalindrome(int n){
    int newNum = isPalindromeRec(n, 0);
    if(newNum == n){return TRUE;}
    else{return FALSE;}
}



