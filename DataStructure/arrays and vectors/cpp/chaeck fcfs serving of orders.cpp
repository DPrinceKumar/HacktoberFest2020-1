//problem
//I have two registers: one for take-out orders, and the other for the other folks eating inside the cafe. 
//All the customer orders get combined into one list for the kitchen, where they should be handled first-come, first-served.

//The take-out orders as they were entered into the system and given to the kitchen. (takeOutOrders)
//The dine-in orders as they were entered into the system and given to the kitchen. (dineInOrders)
//Each customer order (from either register) as it was finished by the kitchen. (servedOrders)

//Given all three vectors, write a function to check that my service is first-come, first-served. 
//All food should come out in the same order customers requested it.

//solution
// as we need to check order of dishes, we can simply think it as in stack point of view.
// Go through each entry in served list and check if it is on top of any of other two lists(take / dine).
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long

using namespace std;


  bool isFCFS(const vector<int>& take, const vector<int>& dine, const vector<int>& served)
{                                    //returns booleans(true/ false).
    auto takeIter = take.cbegin();   //iterator for takeorder
    auto dineIter = dine.cbegin();	// iterator for DineOrder

    for (int order : served) {
        if (takeIter != take.cend() && order == *takeIter) {
            ++takeIter;
        }
        else if (dineIter != dine.cend() && order == *dineIter) {
            ++dineIter;
        }
        else {
            return false;
        }
    }
    if (dineIter != dine.cend() || takeIter != take.cend()) {
        return false;
    }
    return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> take,dine,sereved;
		int temp,n=1;
		cout<<"enter take list, press 1 after each entry to enter more else enter other key\n";
		while(n==1){
			cin>>temp;
			take.pb(temp);
			cin>>n;
		}
		n=1;
		cout<<"enter dine list, press 1 after each entry to enter more else enter other key\n";
		while(n==1){
			cin>>temp;
			dine.pb(temp);
			cin>>n;
		}
		n=1;
		cout<<"enter served list, press 1 after each entry to enter more else enter other key\n";
		while(n==1){
			cin>>temp;
			sereved.pb(temp);
			cin>>n;
		}
		if(isFCFS(take,dine,sereved)){
			cout<<"its FCFS";
		}
		else cout<<"you need to improve";                      
	}
}



