#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min(int a,int b){
    if(a>b){
        return b;
    }
    else {
        return a;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int a0=0;a0<t;a0++){
        int n;
        scanf("%d",&n);
        int flag=0;
        char* b=(char*)malloc(n*sizeof(char));
        int* a=calloc(26,sizeof(int));
        char x;
        scanf("%c",&x);
        for(int i=0;i<n;i++){
            char x;
            scanf("%c",&x);
            if(x=='_'){
                flag=1;
            }
            else{
                a[(int)x-65]++;

            }
            b[i]=x;
        }
        int c=0;
        if(flag==1){
            for(int  i=0;i<26;i++){

                if(a[i]==1){
                    c=1;
                    break;
                }
            }
            if(c==0){
                printf("YES\n");
                continue;;
            }
            else {
                printf("NO\n");
                continue;
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(b[i]!='_'&&b[i]!=b[i-1]&&b[i]!=b[i+1]){
                    printf("NO\n");
                    c=1;
                    break;
                }
            }
            if(c==0){
                printf("YES\n");
            }
        }
    }
}
