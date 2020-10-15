#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    vector<ll>indeg(n+1);
    for(ll i=1;i<=n;i++)
    indeg[i]=0;
    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<ll>q;
    for(ll i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        q.push(i);
    }
    vector<ll>topo;
    while(!q.empty())
    {
        ll curr=q.front();
        q.pop();
        topo.push_back(curr);
        for(auto neb:adj[curr])
        {
            if(indeg[neb]==0)
            continue;
            indeg[neb]--;
            if(indeg[neb]==0)
            q.push(neb);
        }
        
    }
    for(auto x:topo)
    cout<<x<<" ";
}
