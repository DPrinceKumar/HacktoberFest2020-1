/*
  C++ code to find the longest palindromic subsequence in a string
 */
#include<bits/stdc++.h>
using namespace std;
int longest(string str){
    int n=str.length();
    bool pal[n][n];
    int max=1;
    for(int i=0;i<n;i++){
        pal[i][i]=true;
    }
    int start=0;
    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            start=i;
            pal[i][i+1]=true;
            max=2;
        }
        else
        {
            pal[i][i+1]=false;
        }
        
    }
    for(int length = 3;length<=n;length++){
        for(int i=0; i<n-length+1;i++){
            int j = i+length-1;
            if(pal[i+1][j-1] == true && str[i]==str[j]){
                pal[i][j]=true;
                start=i;
            }
        }
    }
    cout<<str.substr(start,start+max-1);
    return max;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    cout<<longest(s);
}