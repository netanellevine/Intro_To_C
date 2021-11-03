#include <stdio.h>
#include "NumClass.h"

int main() {
    int start = 0, end = 0, i;
//    printf("Enter the first number: \n");
    scanf("%d", &start);
    scanf("%d", &end);
    printf("The Armstrong numbers are:");
    for(i = start; i <= end; i++ ){
        if(isArmstrong(i) == TRUE){
            printf(" %d", i);
        }
    }
    printf("\n");
    printf("The Palindromes numbers are:");
    for(i = start; i <= end; i++ ){
        if(isPalindrome(i) == TRUE){
            printf(" %d", i);
        }
    }
    printf("\n");
    printf("The Prime numbers are:");
    for(i = start; i <= end; i++ ){
        if(isPrime(i) == TRUE){
            printf(" %d", i);
        }
    }
    printf("\n");
    printf("The Strong numbers are:");
    for(i = start; i <= end; i++ ){
        if(isStrong(i) == TRUE){
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}

