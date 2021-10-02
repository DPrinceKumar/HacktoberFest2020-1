#include<bits/stdc++.h>
using namespace std;
float eps = 1e-6;
double nTHroot(double n){
    double l = 1;
    double r = n;
    while (r-l > eps)
    {
        double mid = (l + r)/2;
        // if ((mid*mid) == n)
        // {
        //    return mid;
        // }
        
        if ((mid*mid) < n)
        {
            l = mid;
        }
        else{
            r = mid;
        }
        
    }
    // cout<<setprecision(20);
    return l;
}
int main()
{
    cout<<float(eps)<<endl;
    double n;
    cin>>n;
    double ans = nTHroot(n);
    cout<<ans<<endl;
    
    return 0;
}