// Program to illustrate the resultant array with k sorted arrays
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, pair<int,int> > node;
vector<int>merge(vector<vector<int> > v)
{
	vector<int>r;   //vector to store the resultant array
	priority_queue<node,vector<node>,greater<node> > p;   //minimum priority queue (or min heap) 
	for(int i=0;i<v.size();i++)
	p.push({v[i][0],{i,0}});
	while(!p.empty())
	{
		node c=p.top();
		p.pop();
		int e=c.first;
		int x=c.second.first;
		int y=c.second.second;
		r.push_back(e);
		if(y+1<v[x].size())
		p.push({v[x][y+1],{x,y+1}});
	}
	return r;
}
int main() {
	int n,k;
	cout<<"enter the size of each array\n";
	cin>>n; //a variable to store size of each array
	cout<<"enter the number of arrays\n";
	cin>>k; //a variable to store the number of sorted arrays
	cout<<"enter the elements of array\n";
	vector<vector<int> >v;  //vector of vector to insert the elements of array
	for(int i=0;i<k;i++)
	{	
		vector<int>t;
		for(int j=0;j<n;j++)
		{
			int a;
			cin>>a;
			t.push_back(a);
		}
		v.push_back(t);
		t.clear();
	}
	vector<int>t=merge(v);  //function call implementation
	cout<<"the resultant array is\n";
	for(int x=0;x<t.size();x++)   //printing resultant array
	cout<<t[x]<<" ";
	return 0;
}
