#include<iostream>
#include<conio.h>
class matrix{
int a[2][2],b[2][2];
int i,j;
int sum;
public:
    void getmatrix();
    void putmatrix();
};
    void matrix :: getmatrix(){
            cout<<"Enter the Matrix a : ";
                for(int i=0;i<=1;i++){
                    for(int j=0;j<=1;j++){
                        cin>>a[i][j];
                    }
                }
                cout<<"Enter the Matrix b : ";
                for(int i=0;i<=1;i++){
                    for(int j=0;j<=1;j++){
                        cin>>b[i][j];
                    }
                }

    }
    void matrix :: putmatrix(){
            cout<<"The matrix is : ";
                for(int i=0;i<=1;i++){
                    for(int j=0;j<=1;j++){
                        cout<<a[i][j];

    }
                }
                cout<<"The matrix is : ";
                for(int i=0;i<=1;i++){
                    for(int j=0;j<=1;j++){
                        cout<<b[i][j];

    }
                }
    }
   void sum(matrix m1 , matrix m2){
          for(int i=0;i<=1;i++){
                    for(int j=0;j<=1;j++){
                        cout<<m1.a[i][j]+m2.b[i][j];
                    }
          }

    }
    void main(){
        matrix m1,m2;
        m1.getmatrix();
        m2.putmatrix();
        sum(m1,m2);
        getch();
    }
