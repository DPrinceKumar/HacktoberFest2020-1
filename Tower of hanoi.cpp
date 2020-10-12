#include<iostream>
using namespace std;
void TowerofHanoi(int n, char Beg, char Aux, char Des)
{
	if(n==1)
	{
		cout<<Beg<<" -> "<<Aux<<endl;
		return ;
	}
	TowerofHanoi(n-1,Beg,Des,Aux);
	cout<<Beg<<" -> "<<Aux<<endl;
	TowerofHanoi(n-1,Aux,Beg,Des);
}
int main()
{
	int n;
	char Beg,Aux,End;
	cout<<"Enter number of Rings"<<endl;
	cin>>n;
	TowerofHanoi(n,'A','B','C');
	return 0;
}
