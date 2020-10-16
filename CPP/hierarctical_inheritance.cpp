#include <iostream>
#include <conio.h>

using namespace std;

class person
{
    char name[100],gender[10];
    int age;
    public:
        void getdata()
        {
            cout<<"Name: ";
            fflush(stdin);  /*clears input stream*/
            gets(name);
            cout<<"Age: ";
            cin>>age;
            cout<<"Gender: ";
            cin>>gender;
        }
        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Gender: "<<gender<<endl;
        }
};

class student: public person
{
    char institute[100], level[20];
    public:
        void getdata()
        {
            person::getdata();
            cout<<"Name of College/School: ";
            fflush(stdin);
            gets(institute);
            cout<<"Level: ";
            cin>>level;
        }
        void display()
        {
            person::display();
            cout<<"Name of College/School: "<<institute<<endl;
            cout<<"Level: "<<level<<endl;
        }
};

class employee: public person
{
    char company[100];
    float salary;
    public:
        void getdata()
        {
            person::getdata();
            cout<<"Name of Company: ";
            fflush(stdin);
            gets(company);
            cout<<"Salary: Rs.";
            cin>>salary;
        }
        void display()
        {
            person::display();
            cout<<"Name of Company: "<<company<<endl;
            cout<<"Salary: Rs."<<salary<<endl;
        }
};

int main()
{
    student s;
    employee e;
    cout<<"Student"<<endl;
    cout<<"Enter data"<<endl;
    s.getdata();
    cout<<endl<<"Displaying data"<<endl;
    s.display();
    cout<<endl<<"Employee"<<endl;
    cout<<"Enter data"<<endl;
    e.getdata();
    cout<<endl<<"Displaying data"<<endl;
    e.display();
    getch();
    return 0;
}
