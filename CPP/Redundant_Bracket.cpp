#include<iostream>
#include<cstring>
using namespace std;
#include<stack>


bool checkRedundantBrackets(string input) {
	// Write your code here
	stack<char> s1;

	int n = input.size();
	//cout<<n;


	int i=0;
	while(i<n){
        s1.push(input[i]);
        if(s1.top()==')' && i>0){
            s1.pop();
            int count=0;
            while(s1.top()!='('){
                s1.pop();
                count++;
            }

            s1.pop();

            if(count<=1){
                //cout<<1;
                return true;
                }
            }


        i++;
    }
    //cout<<0;
    return false;



}
int main(){


    string s;
    cin>>s;

    cout<<checkRedundantBrackets(s);


}
