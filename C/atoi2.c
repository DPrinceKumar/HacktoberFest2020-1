#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int atoi2(char x[]){
int i = 0, cont = 0, c = 0, temp = 0;
    while (1){
        if (x[c] == '\0') break;
        c++;
    }
    while (1){
        if (x[i] == '.'){
            cont++;
            return 0;
            break;
        }
        else if(x[i] - '0' > 31 && x[i] - '0' < 127){
            cont++;
            return 0;
            break;
        }
        else if (x[i] == '\0') break;
        i++;
    }
    if(cont==0){
        int po = pow(10, c-1);
        for(i=0; i<c; i++){
            temp = temp + (x[i] - '0') * po;
            po = po/10;
        }
    }
    return temp;
}

int main(){
    char lie[1024];
    scanf("%s", lie);
    printf("%d\n", atoi2(lie));
    return 0;
}