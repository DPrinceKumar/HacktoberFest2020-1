/* 
    C++ program to print a matrix in spiral form 
    Contributed By: Sreejit De
*/

#include<bits/stdc++.h>
using namespace std;
#define C 4
#define R 3
void print(int arr[R][C],int i, int j, int m, int n){
    if((i>=m)||(j>=n))
        return;
    
    for(int c=j;c<n;c++)
        cout<<arr[i][c]<<" ";
    for(int c=i+1;c<m;c++)
        cout<<arr[c][n-1]<<" "; 

    for(int c=n-2;c>=j;c--){
        if(m-1!=i)
            cout<<arr[m-1][c]<<" ";
    }
    for(int c=m-2;c>i;c--){
        if(n-1!=j)
            cout<<arr[c][j]<<" "; 
    }
    print(arr,i+1,j+1,m-1,n-1);   
}
int main(){
    int arr[R][C];
    int i,j;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            cin>>arr[i][j];
        }
    }
    print(arr,0,0,R,C);
    return 0;

}