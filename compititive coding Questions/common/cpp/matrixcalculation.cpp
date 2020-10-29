#include <iostream>
using namespace std;
class matrix
{
    public:
    void addition();
    
    void substraction();
    void multiplication();
    void transpose();

};
void matrix::addition()
{
    

    int a[100][100];
    int b[100][100];
    int sum[100][100];

    int rows;
    
    int coloum;
    

    cout<<"*****WELCOME TO THE ADDITION OF MATRIX*****\n";
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
void matrix::substraction()
{
    
    int a[100][100];
    int b[100][100];
    int sum[100][100];

    int rows;
    
    int coloum;
    

    cout<<"*****WELCOME TO THE SUBSTRACTION*****\n";
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
       sum[i][j]=a[i][j]-b[i][j];


    cout<<"the substraction of two matrix is "<<"\n";
     for (int i=0;i<rows;++i){
       for (int j=0;j<coloum;++j)
       cout<<sum[i][j]<<" ";
       cout<<"\n";
     }
       
        
}
void matrix::multiplication()
{
    int row1;
    int row2;
    int coloum1;
    int coloum2;
    int a[100][100];
    int b[100][100];
    int mult[100][100];


    cout<<"******WELCOME TO THE MULTIPLICATION**********\n";
    cout<<"please enter the no of rows of first matrix \n";
    cin>>row1;
    cout<<"please enter the no of coloums of first matrix \n";
    cin>>coloum1;
    for (int i=0;i<row1;++i)
      for(int j=0;j<coloum1;++j)
      {
          cout<<"please enter the values of "<<i+1<<","<<j+1<<"\n";
          cin>>a[i][j];
      }

    cout<<"please enter the no of rows of second  matrix \n";
    cin>>row2;
    cout<<"please enter the no of coloums of second  matrix \n";
    cin>>coloum2;
    for (int i=0;i<row2;++i)
        for(int j=0;j<coloum2;++j){
      
          cout<<"please enter the values of "<<i+1<<","<<j+1<<"\n";
          cin>>b[i][j];
        } 
      
    for (int i=0;i<row1;++i)
        for(int j=0;j<coloum2;++j) 
            mult[i][j]=0;
       
    for (int i=0;i<row1;++i)
     

     
      for(int j=0;j<coloum2;++j)
          for(int k=0;k<coloum2;++k)
          {
               mult[i][j]=a[i][k]*b[k][j];
          } 
          cout<<"the multiplication is \n";     
    for (int i=0;i<row1;++i){
        for(int j=0;j<coloum2;++j) 
      
        cout<<mult[i][j]<<" ";
        cout<<"\n";
        }
}
void matrix::transpose()
{
    int row;
    int coloum;
    int a[100][100];
    int t[100][100];
    cout<<"*****WELCOME TO THE TRANSPOSE OF MATRIX*****\n";
    cout<<"please enter the no of rows\n";
    cin>>row;
    cout<<"please enter the value of coloum\n";
    cin>>coloum;

    for(int i=0;i<row;++i)
      for (int j=0;j<coloum;++j)
      {
          cout<<"please enter the elements "<<i+j<<","<<j+1<<"\n";
          cin>>a[i][j];
      }
      cout<<"your inputed matrix is \n";
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        cout<<a[i][j]<<" ";
        cout<<"\n";

    }
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < coloum; ++j) {
         t[j][i] = a[i][j];
      }
    
    cout<<"the transpose matrix is\n";
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        cout<<t[i][j]<<" ";
        cout<<"\n";

    }

}
int main()
{  int ch;
  cout<<"*****WELCOME*****\n";
  cout<<" 1: for addition of matrix\n 2: for substraction of matrix\n 3: multiplication of matrix\n 4: transpose of matrix\n 5: to exit\n";

    cout<<"please enter your choice\n";
    cin>>ch;
    matrix obj;
    switch (ch)
    {
      case 1: obj.addition();
              break;
      case 2: obj.substraction();
              break;
      case 3: obj.multiplication();
              break;
      case 4: obj.transpose();
              break;
      case 5: exit;
      default :cout<<"invalid choice\n";
              break;
            
    }

  
}
