#include <iostream> 
#include <vector> 
using namespace std; 
int main() { 
    //vector<int> * vp = new vector<int>(); 
    vector<int> v; 
    for (int i = 0; i < 100; i++)
    { 
      cout << "cap:" << v.capacity() << endl; 
      cout << "size:" << v.size() << endl; 
      v.push_back(i + 1); 
    } 
    // user input in  a vector 
    int n;
    cin>>n;
    for(int i=0; i<n;i++)
    {
         int a;
         cin>>a;
         v.push_back(a);
    }
      v.push_back(10); 
      v.push_back(20); 
      v.pop_back(); 
            cout << v[0] << endl; 
            cout << v[1] << endl; 
            cout << v[2] << endl; 
            cout << v[3] << endl; 
            cout << v[4] << endl; 
            cout << v.at(2) << endl; 
            cout << v.at(6) << endl; 

    for(auto  it: v)
    {
     cout<<it<<" ";
    }
    // sorting in  a vector
    sort(v.begin(),v.end());
    // printing the  sorted vector
    for(auto  it: v)
    {
     cout<<it<<" ";
    }
        return 0;
 } 
