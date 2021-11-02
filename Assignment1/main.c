#include <stdio.h>
#include "NumClass.h"

int main() {
    int start = 0, end = 0, i;
    printf("Enter the first number: \n");
    scanf("%d", &start);
    printf("Enter the second number: \n");
    scanf("%d", &end);
        int j = 100;
        while (start > end && j > 0) {
            printf("The first number must be smaller than the second number!!\n");
            printf("Please try again.\n");
            printf("Enter the first number: \n");
            scanf("%d", &start);
            printf("Enter the second number: \n");
            scanf("%d", &end);
            j--;
        }
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

