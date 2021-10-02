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
    vector<int> v  = {1,2,3,4,5,6,7,8};
    int key =5;
    int l  = 0;
    int r = v.size()-1;

    
    bool f = false;
    int c = 0;
    while (l <= r)
    {
          c++;
        int mid = ((l + r)/2);
        if (v[mid] == key)
        {
                f = true;
                break;
        }

        if (v[mid] > key)
        {
            r = mid-1;
        }
        else{
            l = mid +1;
        }    
      
    }
    
    if (f)
    {
        cout<<"Found........! "<<c;
    }
    else{
        cout<<"Not Found........!";
    }
    
    return 0;
}