#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
    
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    char ch[n+1];
    cin.getline(ch,n);
    cin.ignore();
    int i = 0;
    int curr = 0;
    int mxlen = 0;
    int sindx = 0;
    int eindx = 0;
    while (1)
    {
        if (ch[i]==' ' || ch[i] == '\0')
        {
            if (curr>mxlen)
            {
                mxlen = curr;
                eindx = sindx;
            }
            curr = 0;
            sindx = i+1;   
        }
        else{

        curr++;
        }
        if (ch[i] == '\0')
        {
            break;
        }
        i++;
        
        
    }
    
    cout<<mxlen<<endl;
    for (int i = 0; i < mxlen; i++)
    {
        cout<<ch[i+eindx];
    }
    
    return 0;
}