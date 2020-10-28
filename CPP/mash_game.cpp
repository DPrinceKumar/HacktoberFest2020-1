// MASH game code

#include <iostream>
#include <string>
#include <time.h>

using namespace std;
// a function to generate random numbers
int random(int){
      srand((unsigned) time(0));
    int rnum = (rand()%3+1);
    return rnum;
}
// main function
int main(){
    int f=0,choice;
    do{
    cout<<"1)Play MASH or 2) End Program"<<endl;
    cin>>choice;
    switch (choice) { 
    case 1: { 
    string per1,per2,per3;
    cout<<"Enter the name of a person you like:";
    getline(cin,per1);
    cout<<"Enter the name of a person you like:";
    getline(cin,per2);
    cout<<"Enter the name of a person you dislike:";
    getline(cin,per3);
    
    
    int a,b,c;
    //checking if number is valid
    cout<<"Enter a number between 1-100:";
    cin>>a;
    if(a<100&&a>1){
        a=a;
    }
    else{
        a=0;
        cout<<"Enter a valid number"<<endl;};
    cout<<"Enter a number between 1-100:";
    cin>>b;
     if(b<100&&b>1){
        b=b;
    }
    else{
        b=0;
        cout<<"Enter a valid number"<<endl;};
    cout<<"Enter a number between 1-100:";
    cin>>c;
     if(c<100&&c>1){
        c=c;
    }
    else{
        c=0;
        cout<<"Enter a valid number"<<endl;};
    
    
    //taking city name input
    string loc1,loc2,loc3;
    cout<<"Enter the name of a city or state you like:";
    cin>>loc1;
    cout<<"Enter the name of a city or state you like:";
    cin>>loc3;
    cout<<"Enter the name of a city or state you dislike:";
    cin>>loc2;
    
    //taking job title input
    string job1,job2,job3;
    cout<<"Enter a Job title you like :";
    getline(cin,job1);
    cout<<"Enter a Job title you like :";
    getline(cin,job2);
    cout<<"Enter a Job title you like :";
    getline(cin,job3);
    
    //taking company name input
    string com1,com2,com3;
    cout << "Enter a company or restaurant you like:";
    getline(cin, com1);
    cout << "Enter a company or restaurants you like:";
    getline(cin, com2);
    cout << "Enter a company or restaurant you dislike:";
    getline(cin,com3);
    
    
    int n,l,m;
    cout<<"Enter a number between 10000 and 500000";
    cin>>n;
    if(n<100&&n>1){
        n=n;
    }
    else{
        n=0;
        cout<<"Enter a valid number"<<endl;};
    cout<<"Enter a number between 10000 and 500000";
    cin>>l;
    if(l<100&&l>1){
        l=l;
    }
    else{
        l=0;
        cout<<"Enter a valid number"<<endl;};
    cout<<"Enter a number between 10000 and 500000";
    cin>>m;
    if(m<100&&m>1){
        m=m;
    }
    else{
        m=0;
        cout<<"Enter a valid number"<<endl;};
    
    
    string car1,car2,car3;
    cout << "Enter a vehicle you like:";
    getline(cin, car1);
    cout << "Enter a vehicle you like:";
    getline(cin, car2);
    cout << "Enter a vehicle you dislike:";
    getline(cin,car3);
    //switch cases to generate random outputs
    //1
     switch(random(0)){
    case 1:
    cout<< "You will live in a Mansion"<< endl;
    break;
      
    case 2:
    cout<< "You will live in a Apartment"<< endl;
    break;
    case 3:
    cout<<"You will live in a Shack"<<endl;
    break;
    default:
    cout<< "You will live in a House"<< endl;
    }
    
    //2
    switch(random(1)){
    case 1:
    cout<< "You will be happily married to "<< per1 << endl;
    break;
      
    case 2:
    cout<< "You will be happily married to "<< per2 << endl;
    break;
      
    default:
    cout<< "You will be happily married to "<< per3 << endl;
    }
    //3
    switch(random(2)){
    case 1:
    cout<< "You  and your spouse will have "<< a<<" children."<<endl;
    break;
      
    case 2:
    cout<< "You and your spouse will have  "<< b<<" children."<< endl;
    break;
      
    default:
    cout<< "You and your spouse will have "<< c<<" children."<< endl;
    }
    //4
    switch(random(3)){
    case 1:
    cout<< "You will live in "<< loc1 << endl;
    break;
      
    case 2:
    cout<< "You will live in  "<< loc2 << endl;
    break;
      
    default:
    cout<< "You will live in  "<< loc3 << endl;
    }
    //5
    switch(random(5)){
    case 1:
    cout<< " You will work at  "<< com1 ;
    break;
      
    case 2:
    cout<< "Y You will work at  "<< com2 ;
    break;
      
    default:
    cout<< " You will work at  "<< com3;
    }
    
    //6
    switch(random(4)){
    case 1:
    cout<< "as a  "<< job1;
    break;
      
    case 2:
    cout<< "as a  "<< job2 ;
    break;
      
    default:
    cout<< "as a  "<< job3;
    }
    //7
    switch(random(6)){
    case 1:
    cout<< "making $  "<< n << endl;
    break;
      
    case 2:
    cout<< "making $ "<< l << endl;
    break;
      
    default:
    cout<< "making $  "<< m << endl;
    }
    //8
    switch(random(7)){
    case 1:
    cout<< "You will drive "<< car1 << endl;
    break;
      
    case 2:
    cout<< "You will drive "<< car2 << endl;
    break;
      
    default:
    cout<< "You will drive "<< car3 << endl;
    }
 
        break; 
    } 
    case 2: { 
        f++; 
        cout<<"Thanks for Playing";
        break; 
    } 
    default: 
        cout<<"Wrong Input"<<endl; 
    } 
}
//breaks the whole code
while(f==0);
}