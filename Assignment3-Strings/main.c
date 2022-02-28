#include <stdio.h>
#include <stdlib.h>
#include "stringlib.c"

#define WORD 30
#define TXT 1024

int wordLength;



int initialize(char w[], char t[], char ABC[]){

    int c = 65; //ASCII value of 'A'
    for (int i = 0; i < 26; i++) { //filling the array with the ASCII value of the ALPHABET
        ABC[i] = c;
        c++;
    }

    char input = 0;
    int temp = 0;

    while(input!=' ' && input!='\t' && input!='\n'){
        scanf("%c", &input);
        w[temp] = input;
        temp++;
    }
    wordLength=temp-1;

    if(temp<30){
        while(temp<30){
            w[temp] = 0;
            temp++;
        }
    }

    int cur = 0;
    while (input != '~') {
        scanf("%c", &input);
        t[cur] = input;
        cur++;
    }

    if(cur<1024) {
        while (cur < 1024) {
            t[cur] = 0;
            cur++;
        }
    }
    return 0;
}







int main(void){

    char t[TXT];
    char w[WORD];
    char ABC[26];


    initialize(w, t, ABC);


    GematriaSequences(w, t, ABC);
    AtbashSequences(w, t);
    AnagramSequences(w, t, ABC, wordLength);


    return 0;
}

