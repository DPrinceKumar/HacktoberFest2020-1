#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long
using namespace std;

vector<int> merge_sorted(vector<int> &arr1,vector<int> &arr2){
	vector<int> arr3; 
    int i = 0, j = 0; 
  	int n1 = arr1.size();
  	int n2 = arr2.size();
    // Traverse both array 
    while (i<n1 && j <n2) 
    { 
        // Check if current element of first 
        // array is smaller than current element 
        // of second array. If yes, store first 
        // array element and increment first array 
        // index. Otherwise do same with second array 
        if (arr1[i] < arr2[j]) 
            {
            	arr3.pb(arr1[i++]);
			}
        else
            {
            	arr3.pb(arr2[j++]);
			} 
    } 
    // Store remaining elements of first array 
    while (i < n1) 
        arr3.pb(arr1[i++]); 
    // Store remaining elements of second array 
    while (j < n2) 
        arr3.pb(arr2[j++]);    
    return arr3;
} 


int main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> a,b;
		int n,m,temp;
		cin>>n>>m;
		for(int i=0; i<n; i++){
			cin>>temp;
			a.pb(temp);
		}
		for(int i=0; i<m; i++){
			cin>>temp;
			b.pb(temp);
		}
		vector<int> c = merge_sorted(a,b);
		//output vector
		cout << "[";
		for (size_t i = 0; i < c.size(); ++i) {
    		if (i > 0) {
        	cout << ", ";
    		}
    		cout << c[i];
			}
		cout << "]" << endl;
	}
}


