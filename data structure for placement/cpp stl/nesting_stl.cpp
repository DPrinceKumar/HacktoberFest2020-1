#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    // map<pair<string,string>,vector<int>> mp;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     string fn,ln;
    //     cin>>fn>>ln;
    //     int sn;
    //     cin>>sn;
    //     for (int j = 0; j < sn; j++)
    //     {
    //         int x;
    //         cin>>x;
    //         mp[{fn,ln}].push_back(x);
    //     }
        
    // }

    // for (auto &&i : mp)
    // {
    //     auto full_nm = i.first;
    //     auto list_nm = i.second;

    //     cout<<full_nm.first<<" "<<full_nm.second<<endl;
    //     for (auto &&ie : list_nm)
    //     {
    //         cout<<ie<<" ";
    //     }
    //     cout<<endl;
    
    // }
    
    
    map<int,set<string>> mp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s; 
        cin>>s;
        int x;
        cin>>x;
        mp[x].insert(s);
    }
    for (auto &&i : mp)
    {
        auto f = i.first;
        auto s = i.second;
        for (auto &&j : s)
        {
            cout<<j<<" "<<f<<endl;
        }
        
    }
    
       
    return 0;
}