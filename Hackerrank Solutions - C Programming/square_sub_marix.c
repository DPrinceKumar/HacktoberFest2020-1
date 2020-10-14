#include<stdio.h>
int min(int a,int b,int c){
if(a<b&&a<c){
    return a;
}
else if(b>c){
    return b;
}
else
    return c;
}
void main(){
    int i,j,res=0;
    int mat[4][5]={
                    {1,0,1,1,1},
                    {1,0,1,1,1},
                    {1,1,1,1,1},
                    {1,0,1,1,1}
                   };
    int arr[5][6];
    for(i=0;i<5;i++){
        for(j=0;j<6;j++){
            if(i==0||j==0){
                arr[i][j]=0;
            }
            if(mat[i][j]!=0){
                arr[i][j]=min(mat[i-1][j],mat[i-1,j-1],mat[i][j-1])+1;
            }
            else{
                arr[i][j]=0;
            }
            res=arr[i][j];
        }
    }
    printf("%d",res*res);
}
