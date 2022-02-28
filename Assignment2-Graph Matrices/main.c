#include <stdio.h>
#include "my_mat.h"


int main(void){
    char dec;//the decision of the user
    int mat[10][10];
    int i, j;
    while(dec != 'D'){
        scanf("%c", &dec);
        switch (dec) {
            case 'A':
                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        mat[i][j]=0;
                    }
                }
                entermat(mat);
                break;

            case 'B':
                scanf("%d%d", &i, &j);
                if(pathExists(mat,i,j)==1){
                    printf("True\n");
                }
                else{
                    printf("False\n");
                }
                break;


            case 'C':
                scanf("%d%d", &i, &j);
                if(shortestPath(mat, i, j)>0){
                    printf("%d", mat[i][j]);
                    printf("\n");
                }
                else{
                    printf("-1\n");
                }
                break;
        }
    }
    return 0;
}