#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int die()
{  
    srand(time(0));
    int x =rand()%6+1;

    return x;
}

int main()
{
    int die1;
    //int die2;

while(1)
{
    die1= die();
    //die2=die();
    break;
}

    cout << die1<<endl;
    //cout << die2<<endl;

    return 0;
}
