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
    else{
        return a;
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int page=0,s=0;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        int  q=0,pq=0;
        while(q<arr[i]){
            page++;
            pq=q;
            q=min(q+k,arr[i]);
            if(page<=q && page>pq){
                s++;
            }
        }
    }
    printf("%d",(s));
}
