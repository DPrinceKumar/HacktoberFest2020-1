//problems
//Write a function reverseWords() that takes a message as a string and reverses the order of the words in place. ?

//solution
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long
using namespace std;

void rev_chars(string &s, int st, int last){
	char c;
	int mid = (last-st+1)/2;
	for(int i=0; i<mid; i++){
		c= s[st+i];
		s[st+i] = s[last-i];
		s[last-i]=c; 
	}
}

void rev_words(string &s, int len)
{
	int st=0,end;
	for(int i=0; i<=len; i++)
	{
		if(i==len||s[i]==' ')
		{
			end = i-1;
			rev_chars(s,st,end);
			st = i+1;
		}
	}
}

int main(){
	int t;  //test cases
	cin>>t;
	while(t--)
	{
		string s;
		getline(cin,s); // abug is there, please use space after test case for input first string else it will simply takes enter as first string
		cout<<"initial s:"<<s<<endl;
		int n = s.length();
		rev_chars(s,0,n-1);
		rev_words(s,n);
		cout<<"reversed s:"<<s<<endl;
	}
}
