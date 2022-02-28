#include <stdio.h>
#include <stdlib.h>
#include "stringlib.h"
#include <string.h>

#define TXT 1024
#define WORD 30
#define maxLength 2048 // for the length of the array *2 of the GematriaSequences. (if we get a word with only 1 letter and a text with 1024 times the same letter of the word, we need to have space for 1024 times the letter and 1024 times the sequence "~")
#define A 65
#define Z 90
#define a 97
#define z 122



//a function that calculate the gimatric value of the given word
int sum(char w[], char ABC[]){
    int counter = 0;
    for(int i=0; i<30; i++){
        for(int j=0; j<26; j++){
            if(w[i] == ABC[j] || w[i] == ABC[j]+32)
                counter+=j+1;
        }
    }
    //we add +1 to the number because the array starts with 0 but a=A=1, b=B=2 and so on, so we add 1 to get the real gematric value;

    return counter;

}



//////////////1//////////////
void GematriaSequences(char w[], char t[], char ABC[]){
    int g[maxLength];// for the gematria function's output

    for(int i=0; i<maxLength; i++){
        g[i] = 0;
    }

    int start, end;
    int l=0;
    int counter=0;
    int size = 0; // for the end-start length
    int wordSize = sum(w, ABC); // the word's gimatric sum
    start = 0;
    end = start;
    while(start<TXT && end<TXT){// if it's in the range of 'a'-'z' ro 'A'-'Z'
        size=end-start;
        if(size==0){
            if((t[start]>64 && t[start]<91) || (t[start]>96 && t[start]<123)){
                for(int i=0; i<26; i++){
                    if(t[start] == ABC[i] || t[start] == ABC[i]+32)
                        counter+=i+1;
                }
            }
            if(counter == wordSize){
                g[l] = t[start];
                l++;
                g[l] = '~';
                l++;
                start++;
                end = start;
                counter = 0;
            }
            else if(counter>wordSize){
                start++;
                end = start;
                counter = 0;
            }
            else{
                end++;
            }
        }
        else{
            if(counter==0){ // if the size of the word is at least 2 chars but the chars are not letters e.g. ' ' or '/' so we restart the counting
                start++;
                end = start;
            }

            if((t[end]>64 && t[end]<91) || (t[end]>96 && t[end]<123)){
                for(int i=0; i<26; i++){
                    if(t[end] == ABC[i] || t[end] == ABC[i]+32)
                        counter+=i+1;
                }
            }

            if(counter == wordSize){
                if((t[end]>64 && t[end]<91) || (t[end]>96 && t[end]<123)){
                    int temp = start;
                    while(temp<=end){
                        g[l] = t[temp];
                        l++;
                        temp++;
                    }
                    g[l] = '~';
                    l++;
                }
                start++;
                end = start;
                counter = 0;
            }
            else if(counter>wordSize){
                start++;
                end = start;
                counter = 0;
            }
            else{
                end++;
            }

        }

    }

    l--;
    printf("Gematria Sequences: ");
    int i=0;
    while(i<l){
        printf("%c", g[i]);
        i++;
    }
    printf("\n");

}



//////////////2//////////////
void AtbashSequences(char w[], char t[]) {
    // wordLength length of the word
    // wAtbash[] original word at atBash language
    // wAtbashReverse[] original word at atBash language but reversed
    // newTextLength length of the output text -> MAX 2048

    int at[maxLength]; // for the atbash function's output
    int wAtbash[WORD];
    int wAtbashReverse[WORD];

    int wordLength = 0;
    for (int i = 0; i < maxLength; i++) {
        at[i] = 0;
    }

    for (int i = 0; i < WORD; i++) {
        if (w[i] >= A && w[i] <= Z) {
            wAtbash[i] = A - w[i] + Z;
            wordLength++;
        }
        else if (w[i] >= a && w[i] <= z) {
            wAtbash[i] = a - w[i] + z;
            wordLength++;
        }
    }

    for (int i = 0; i < wordLength; i++) {
        wAtbashReverse[i] = wAtbash[wordLength - i - 1];
    }

    int start = 0;
    int end = wordLength;
    int curr = 0;
    int newTextLength = 0;
    int counter = 0;

    while (start < TXT && end < TXT){
        if ((t[curr] > 64 && t[curr] < 91) ||
            (t[curr] > 96 && t[curr] < 123) || (t[curr] == 32)){
            curr = start;
            counter = 0;
            while (counter < wordLength){
                if ((t[curr] > 64 && t[curr] < 91) ||
                    (t[curr] > 96 && t[curr] < 123) || (t[curr] == 32)){
                    if(t[curr] == wAtbash[counter]){
                        curr++;
                        counter++;
                    }
                    else if(t[curr] == 32 && counter != 0){
                        curr++;
                    }
                    else {
                        counter = 0;
                        break;
                    }
                }
                else {
                    curr++;
                    break;
                }
            }
            if (counter == wordLength){
                int i = 0;
                while (start < curr){
                    if(t[start] == wAtbash[i]){
                        at[newTextLength] = t[start];
                        start++;
                        i++;
                        newTextLength++;
                    }
                    else if (t[start] == 32){
                        at[newTextLength] = t[start];
                        start++;
                        newTextLength++;
                    }
                }
                at[newTextLength] = '~';
                newTextLength++;
            }



            start = curr;
            counter = 0;
            while (counter < wordLength){
                if ((t[curr] > 64 && t[curr] < 91) ||
                    (t[curr] > 96 && t[curr] < 123) || (t[curr] == 32)){
                    if(t[curr] == wAtbashReverse[counter]){
                        curr++;
                        counter++;
                    }
                    else if(t[curr] == 32 && counter != 0){
                        curr++;
                    }
                    else {
                        counter = 0;
                        break;
                    }
                }
                else {
                    curr++;
                    break;
                }
            }
            if (counter == wordLength){
                int i = 0;
                while (start < curr){
                    if(t[start] == wAtbashReverse[i]){
                        at[newTextLength] = t[start];
                        start++;
                        i++;
                        newTextLength++;
                    }
                    else if (t[start] == 32){
                        at[newTextLength] = t[start];
                        start++;
                        newTextLength++;
                    }
                }
                at[newTextLength] = '~';
                newTextLength++;
            }
            curr++;
            start = curr;
        }
        else  {
            curr++;
            start = curr;
        }
    }

    newTextLength--;
    printf("Atbash Sequences: ");
    int i = 0;
    while (i < newTextLength) {
        printf("%c", at[i]);
        i++;
    }
    printf("\n");
}



//////////////3//////////////
void AnagramSequences(char w[], char t[], char ABC[], int wordLength){
    int an[maxLength]; // for the anagram function output

    for(int i=0; i<maxLength; i++){
        an[i] = 0;
    }

    int start=0;
    int end=0;
    int l=0;
    int counter=0;
    int size = 0; // for the end-start length
    int wordSize = sum(w, ABC); // the word's gimatric sum
    while(start<TXT && end<TXT){
        size = end-start;
        if((t[end]>64 && t[end]<91) || (t[end]>96 && t[end]<123)){
            for(int i=0; i<26; i++){
                if(t[end] == ABC[i] || t[end] == ABC[i]+32)
                    counter+=i+1;
            }
        }

        if(counter == wordSize){
            int temp=start;
            int wLength=0;
            int letters=0;
            for(int i=0; i<wordLength; i++){
                for(int j=0; j<size; j++){
                    if(w[i] == t[temp]){
                        wLength++;
                        letters++;
                        break; //moving to the next char in the word
                    }
                    else if(w[i] == ' ' && i!=0){
                        wLength++;
                    }
                    temp++;
                }
                temp = start;
            }
            if(wLength == size && letters+1==wordLength){
                temp = start;
                while(temp<=end){
                    an[l] = t[temp];
                    l++;
                    temp++;
                }
                an[l] = '~';
                l++;
            }
            start++;
            end = start;
            counter = 0;
        }

        else if(counter>wordSize){
            start++;
            end = start;
            counter = 0;
        }
        else{
            end++;
        }

    }

    l--;
    printf("Anagram Sequences: ");
    int i=0;
    while(i<l){
        printf("%c", an[i]);
        i++;
    }

}
