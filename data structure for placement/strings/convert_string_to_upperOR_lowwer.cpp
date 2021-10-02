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
    string s;
    cin>>s;

    // accii value od 'A' = 65
    // accii value od 'a' = 97
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] >= 'A' && s[i] <= 'Z')
    //     {
    //         s[i] = s[i] + 32;
    //     }
        
    // }
    // cout<<"Lowwer case :" <<s<<endl;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] >= 'a' && s[i] <= 'z')
    //     {
    //         s[i] = s[i] - 32;
    //     }
        
    // }
    // cout<<"Upper case :" <<s<<endl;


    // Inbuild Function
    transform(s.begin(),s.end(),s.begin() ,:: toupper);
    cout<<"Upper case :" <<s<<endl;
    transform(s.begin(),s.end(),s.begin() ,:: tolower);
    cout<<"Lower case :" <<s<<endl;
    return 0;
}