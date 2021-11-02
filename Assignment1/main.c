#include <stdio.h>
#include "NumClass.h"

int main() {
    int start, end, i;
    printf("Enter the first number: \n");
    scanf("%d", &start);
    printf("Enter the second number: \n");
    scanf("%d", &end);
    printf("The Prime numbers within the range of [%d,%d] are: ", start, end);
    for(i = start; i <= end; i++ ){
        if(isPrime(i) == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("The Armstrong numbers within the range of [%d,%d] are: ", start, end);
    for(i = start; i <= end; i++ ){
        if(isArmstrong(i) == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("The Strong numbers within the range of [%d,%d] are: ", start, end);
    for(i = start; i <= end; i++ ){
        if(isStrong(i) == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("The Palindrome numbers within the range of [%d,%d] are: ", start, end);
    for(i = start; i <= end; i++ ){
        if(isPalindrome(i) == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

