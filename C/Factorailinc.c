//METHOD 1 - Factorial of a number using for loop.
#include <iostream>
using namespace std;
int main()
{
  int i,fac=1,num;
  cout<<"Enter number of which u want to calculate factorial";
  cin>>num;
    
    for(i=1;i<=num;i++)
    {
      fac=fac*i;
    }
   
   cout<<"factorial of " <<num<< "is:" <<fac<<endl;
  
  return 0;
}

//METHOD 2 - Factorial of a number using Recursion.
#include<iostream.h>
using namespace std;
int factorial(int n);
int main()
{
  int n,fact=0;
  cout<<"Enter the number whose factorial is to be calculated"<<endl;
  cin>>n;
  fact=factorial(n);
  cout<<"Factorial of"<<n<<"is"<<fact;
  return 0;
}

int factorial(int n)
{
  if(n>1)
    return n*factorial(n-1);
  else
    return 1;
}
