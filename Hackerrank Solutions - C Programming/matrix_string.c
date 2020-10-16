#include<stdio.h>
#include<stdlib.h>

void main(){
    char str[50]="Have a nice day";
    char arr[4][4];
    int i,j,k=0;
    printf("Enter a string: ");
//    scanf("%s",str);

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(str[k]==' ')
                k++;
            arr[j][i]=str[k++];
        }
    }

     for(i=0;i<4;i++){
        for(j=0;j<4;j++){
           printf("%c  ",arr[i][j]);
        }
        printf("\n");
    }
}
