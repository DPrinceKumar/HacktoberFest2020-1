#include<bits/stdc++.h>
using namespace std;
class base1{
    public:
        void g()
        {
            cout<<"hello"<<endl;
        }
};
class base2{
    public:
        void g()
        {
            cout<<"hiii"<<endl;
        }
};

class derived : public base1, public base2{
    int a; 
   
        
};

int main()
{
    derived d;
    d.g();
    return 0;
}