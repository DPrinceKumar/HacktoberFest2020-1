  
//problems
//you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

//Write a function that takes an integer flightLength (in minutes) and a vector of integers movieLengths (in minutes) and returns a boolean indicating whether there are two numbers in movieLengths whose sum equals flightLength.

//When building your function:

//Assume your users will watch exactly two movies
//Don't make your users watch the same movie twice
//Optimize for runtime over memory  
  
//solution
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long
using namespace std;
  
  bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // movie lengths we've seen so far
    unordered_set<int> movieLengthsSeen;

    for (int firstMovieLength : movieLengths) {
        int matchingSecondMovieLength = flightLength - firstMovieLength;
        if (movieLengthsSeen.find(matchingSecondMovieLength) != movieLengthsSeen.end()) {
            return true;
        }
        movieLengthsSeen.insert(firstMovieLength);
    }

    // we never found a match, so return false
    return false;
}

int main(){
	int t;  //test cases
	cin>>t;
	while(t--)
	{
		int fl_len,temp,n;
		cin>>fl_len>>n;
		vector<int> m_len;
		for(int i=0; i<n;i++){
			cin>>temp;
			m_len.pb(temp);
		}
		if(canTwoMoviesFillFlight(m_len,fl_len)){
			cout<<"movies can be seen";
		}else
		cout<<"sorry no movies for yuo";
	}
}
