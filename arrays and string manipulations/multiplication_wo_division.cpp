//problem
//You have a vector of integers, and for each index you want
// to find the product of every integer except the integer 
//at that index.
//task :-= don't use division

//solution
// 4n space as well as 3n time
//we can do better but eventually complaxity will be O(n)
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void solve()
{
	int n,temp;   //n = no. of values in list, temp is used for input
	cin>>n;
	vector<int> ar,ans;   //ar is for storing problem list, ans for storing answer list
	int after[n],prev[n];  //after[i] ->stores multiplication after that index
	for(int i = 0; i<n; i++) //prev[i] ->stores multiplication before that index
	{
		cin>>temp;
		ar.pb(temp);     //input
	}
	prev[0] = 1; after[n-1]=1;  //storing edge values
	for(int i=1; i<n; i++){		//filling prev and after lists
		after[n-1-i] = ar[n-i]*after[n-i];
		prev[i] = prev[i-1]*ar[i-1];
	}
	for(int i=0; i<n; i++)
	{
		ans.pb(prev[i]*after[i]);  //giving solution
		cout<<ans[i]<<"	";
	}
}

int main()
{
	int t;  //test cases
	cin>>t;
	while(t--)
	{
		solve(); //calling solve method to print output
	}
	return 0;
}
