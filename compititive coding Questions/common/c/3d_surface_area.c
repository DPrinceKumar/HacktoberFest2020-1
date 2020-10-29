#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int h,k;
    scanf("%d %d",&h,&k);
    int sa=2*h*k;
    int** a=(int**)calloc(h+2,sizeof(int*));
    a[0]=calloc(k+2,sizeof(int));
    a[h+1]=calloc(k+2,sizeof(int));
    for(int i=1;i<=h;i++){
        a[i]=calloc(k+2,sizeof(int));
        for(int j=1;j<=k;j++){
            int x;
            scanf("%d",&x);
            a[i][j]+=x;
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=k;j++){
            if(a[i][j]>a[i][j+1]){
                sa+=a[i][j]-a[i][j+1];
            }
            if(a[i][j]>a[i][j-1]){
                sa+=a[i][j]-a[i][j-1];
            }
            if(a[i][j]>a[i+1][j]){
                sa+=a[i][j]-a[i+1][j];
            }
            if(a[i][j]>a[i-1][j]){
                sa+=a[i][j]-a[i-1][j];
            }
        }
    }
    printf("%d",sa);
}
