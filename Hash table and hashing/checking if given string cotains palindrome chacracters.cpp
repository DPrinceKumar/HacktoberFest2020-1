//problem
//Write an efficient function that checks whether any permutation ? of an input string is a palindrome. ?
//You can assume the input string only contains lowercase letters.

//Examples:

//"civic" should return true
//"ivicc" should return true
//"civil" should return false
//"livci" should return false

//solution
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long
using namespace std;

  bool hasPalindromePermutation(const string& str)
{
    // track characters we've seen an odd number of times
    unordered_set<char> unpairedCharacters;

    for (char c : str) {
        if (unpairedCharacters.find(c) != unpairedCharacters.end()) {
            unpairedCharacters.erase(c);
        }
        else {
            unpairedCharacters.insert(c);
        }
    }

    // the string has a palindrome permutation if it
    // has one or zero characters without a pair
    return unpairedCharacters.size() <= 1;
}

int main(){
	int t;  //test cases
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		if(hasPalindromePermutation(s)){
			cout<<"true\n\n";
		}else
		cout<<"false\n\n";
	}
}
