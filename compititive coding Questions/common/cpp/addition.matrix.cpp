#include<iostream>
using namespace std;
int main()
{ 
    int a[100][100];
    int b[100][100];
    int sum[100][100];

    int rows;
    
    int coloum;
    

    cout<<"*****WELCOME*****"<<"/n";
    cout<<"please enter the no of rows of first matrix\n";
    cin>>rows;
    cout<<"please enter the coloums of first matrix\n";
    cin>>coloum;
    for (int i=0;i<rows;++i)
       for (int j=0;j<coloum;++j)
       {
           cout<<"please enter the element "<<i+1<<","<<j+1<<"\n";
           cin>>a[i][j];
       }
      cout<<"please enter the no of rows of second matrix\n";
    cin>>rows;
    cout<<"please enter the coloums of second matrix\n";
    cin>>coloum;
     for (int i=0;i<rows;++i)
       for (int j=0;j<coloum;++j)
       {
           cout<<"please enter the element "<<i+1<<","<<j+1<<"\n";
           cin>>b[i][j];
       } 
    
     for (int i=0;i<rows;++i)
       for (int j=0;j<coloum;++j)
       sum[i][j]=a[i][j]+b[i][j];


    cout<<"the addition of two matrix is "<<"\n";
     for (int i=0;i<rows;++i){
       for (int j=0;j<coloum;++j)
       cout<<sum[i][j]<<" ";
       cout<<"\n";
     }
       
           
           
       
} 
