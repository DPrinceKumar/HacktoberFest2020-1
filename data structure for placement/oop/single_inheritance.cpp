#include <bits/stdc++.h>
using namespace std;
class base
{
    int data;

public:
    int data2;
    void set();
    int get1();
    int get2();
};
void base ::set(void)
{
    data = 10;
    data2 = 20;
}
int base ::get1()
{
    return data;
}
int base ::get2()
{
    return data2;
}

class derived : public base
{
    int data3;

public:
    void process();
    void display();
};
void derived ::process()
{
    data3 = data2 * get1();
}
void derived :: display()
{
    cout<<"value of data 1 "<<get1()<<endl;
    cout<<"value of data 2 "<<get2()<<endl;
    cout<<"value of proccess fun "<<data3<<endl;
}
int main()
{
    derived a1;
    a1.set();
    a1.process();
    a1.display();
    return 0;
}