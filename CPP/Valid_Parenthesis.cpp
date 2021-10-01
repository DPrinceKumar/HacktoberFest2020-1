//Sampad Patra

//Hacktoberfest2021

//Recursive code to find the set of all valid parenthesis for a given number of parenthesis.
//For n =2 the valid parenthesis are
// ()()
// (())



#include<bits/stdc++.h>
using namespace std;

// Guide function for recursion.
//o is open parenthesis
//c is closed parenthesis
void solve(int o,int c,vector<string> &ans,string a)
{
	if(c==0 && o==0)
	{
		ans.push_back(a); //push back the string when number of closed and open parenthesis becomes zero
		return;
	}
	
	if(o>0)                // can add open parenthesis only if count of o is more than zero.
	{
		string a1 = a + '(';
		solve(o-1,c,ans,a1);
		
	}
	if(c>o)                // can add closed parenthesis only if the number of closed poarenthesis is more than open.
		{
			string a2 = a+')';
			solve(o,c-1,ans,a2);
		}
		return;
}

//Driver auxilliary function
vector<string> bal(int n)
{
	vector<string> ans;
	int o=n,c=n;
	string a="";
	solve(o,c,ans,a);
	return ans;         //returns a vector of string that contains all the valid parenthesis.
}


//main function
int main()
{
	int n;
    cin>>n;
	vector<string> v = bal(n);

    //Print the parenthesis that is returned by the function.
	for(auto i:v)
		cout<<i<<endl;
	return 0;
}