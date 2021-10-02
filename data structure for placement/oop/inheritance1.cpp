#include<bits/stdc++.h>
using namespace std;
// Base class
class employee{
    string name;
    public :
    int age;
        employee(){}
        employee(string nm)
        {
            name = nm;
            age = 20;
        }
}   ; 
// Derived Class

class programer :public employee{
    public:
    int lancode = 1;
        programer(int ids)
        {
            age = ids; 
        }
        void getdate()
        {
             cout<<age<<endl;
        }
};
int main()
{
    // employee a1("dipak"),a2("micky");
    // cout<<a1.age;

    programer p1(55);
    p1.getdate();
    cout<<p1.lancode<<endl;
    // cout<<p1.age<<endl;
    return 0;
}