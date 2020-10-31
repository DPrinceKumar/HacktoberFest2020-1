#include <iostream>
using namespace std;

template <class T>

void swap(const T &a, const T &b)
{
  T temp;
  temp=a;
  a=b;
  b=temp;
}

int main()
{
  int a,b;
  float c,d;
  char a1[10];
  char b1[10];

  cout<<"Enter the two integers : \n";
  cin>>a>>b;
  cout<<"Before swapping : \t"<<a<<" "<<b<<endl;
  swap(a,b);
  cout<<"After swapping : \t"<<a<<" "<<b<<endl;

  cout<<"Enter the two floating point values : \n";
  cin>>c>>d;
  cout<<"Before swapping : \t"<<c<<" "<<d<<endl;
  swap(c,d);
  cout<<"After swapping : \t"<<c<<" "<<d<<endl;
  cout<<"Enter the two character items : \n";
  cin>>a1;
  cin>>b1;
  cout<<"Before swapping : \t"<<a1<<" "<<b1<<endl;
  swap(a1,b1);
  cout<<"After swapping : \t"<<a1<<" "<<b1<<endl;
  return 0;

}
