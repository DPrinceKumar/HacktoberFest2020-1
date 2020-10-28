//problems
//Write a function that takes a string and reverses the letters in place.

//solution
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long
using namespace std;

void solve(string &s){
	char c;
	int n = s.length();
	for(int i=0; i<n/2; i++){
		c= s[i];
		s[i] = s[n-1-i];
		s[n-1-i]=c; 
	}
}
int main(){
	int t;  //test cases
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<"initial s:"<<s<<endl;
		solve(s);
		cout<<"reversed s:"<<s<<endl;
	}
}
