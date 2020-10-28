//codeforces 129B
//students and shoelaces
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long

int main()
{
int n,m;
cin>>n>>m;
vector<vector<int>>a(n+1);
vector<int>b(n+1,0);
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
    b[x]++;
    b[y]++;

}
queue<int>q;
for(int i=1;i<n+1;i++)
{
    if(b[i]==1)
        q.push(i);
}
if(q.empty()){
    cout<<0;
    return 0;
}
int cnt=0;
while(!q.empty())
{
    while(!q.empty())
    {
        int tp = q.front();
        b[tp]--;
        for(int i=0;i<a[tp].size();i++)
        {
            b[a[tp][i]]--;
        }
        q.pop();
    }
    for(int i=1;i<n+1;i++)
    {
        if(b[i]==1)
        {
            q.push(i);
        }
    }
    cnt++;

}

cout<<cnt;
}
