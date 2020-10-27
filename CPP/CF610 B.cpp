#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector <long int> v(n+1);
    long int mini=INT_MAX;
    long long pos=INT_MIN;
    long long fpos=INT_MAX;
    for(long long i=1;i<=n;i++)
    {
        cin>>v[i];
        mini=min(mini,v[i]);
    }
    vector <long int> positions;
    for(long long i=1;i<=n;i++)
    {
        if(v[i]==mini)
        {
            pos=max(pos,i);
            fpos=min(fpos,i);
            positions.push_back(i);
        }

    }
    if(fpos==pos)
    cout<<mini*n+n-pos+fpos-1;
    else
    {
        long int tempmax=n-positions[positions.size()-1]+positions[0]-1;
        for(int i=0;i<positions.size()-1;i++)
            tempmax=max(tempmax,positions[i+1]-positions[i]-1);

        cout<<n*mini+tempmax;
    }


}


