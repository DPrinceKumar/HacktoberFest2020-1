// This code demonstrates median in a running stream of integers

#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int>p;
	priority_queue<int,vector<int>,greater<int> >q;
	int d;
	cin>>d;
	float med=d;
	p.push(d);
	cin>>d;
	while(d!=-1)
	{
		if(p.size()>q.size())	
		{
			if(d<med)
			{
				q.push(p.top());
				p.pop();
				p.push(d);
			}
			else
			q.push(d);
			med=(p.top()+q.top())/2;
		}
		else if(p.size()==q.size())
		{
			if(d<med)
			{
				p.push(d);
				med=p.top();
			}
			else
			{
				q.push(d);
				med=q.top();
			}
		}
		else
		{
			if(d<med)
			p.push(d);
			else
			{
				p.push(q.top());
				q.pop();
				q.push(d);
			}
			med=(p.top()+q.top())/2;
		}
		cout<<med<<endl;
		cin>>d;
	}
  return 0;
}
