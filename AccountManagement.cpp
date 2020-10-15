#include<iostream>
using namespace std;

class Account{
	string name;
	string accNo;
	string accType;
	float amount;
	public:
		void Input(void);
		void depositAmount(void);
		void withdrawAmount(void);
		void Display(void);
};
 
void Account::Input(void)
{
	string fname,lname;
	cout<<"Enter the First Name of customer:\n";
	cin>>fname;
	cout<<"Enter the Last Name of customer:\n";
	cin>>lname;
	name = fname+" "+lname;
	cout<<"Enter the Account type of customer:\n";
	cin>>accType;
	cout<<"Enter the Account number of customer:\n";
	cin>>accNo;	
}
void Account::depositAmount(void)
{
	while(true)
	{
	    cout<<"Enter the amount to be deposited:\n";
	    cin>>amount;
	    if(amount>0)
	    break;
	    else
	    {
	    	cout<<"Invalid amount entered. Enter valid amount.\n";
	    	continue;
		}
	}
}
void Account::withdrawAmount(void)
{
	float withdraw;
	while(true)
	{
	    cout<<"Enter the amount to be withdrawed:\n";
	    cin>>withdraw;
	    if(withdraw>=0)
	    break;
	    else
	    {
	    	cout<<"Invalid amount entered. Enter valid amount.\n";
	    	continue;
		}
	}
	if(withdraw>amount)
	{
		cout<<"Not enough money in account.\n";
	}
	else
	{
		amount = amount-withdraw ;
	}
}
void Account::Display(void)
{
	cout<<"\n";
	cout<<"Name of the customer is: "<<name<<"\n";
	cout<<"Account balance is: "<<amount<<"\n";
	cout<<"**********************************************";
	cout<<"\n";
}
int main()
{
	Account acc[6];
	for(int i=0;i<6;i++)
	{
		acc[i].Input();
		acc[i].depositAmount();
		acc[i].withdrawAmount();
		acc[i].Display();
	}
	Account *ac = new Account();
		ac->Input();
		ac->depositAmount();
		ac->withdrawAmount();
		ac->Display();
	Account *a = new Account();
		a->Input();
		a->depositAmount();
		a->withdrawAmount();
		a->Display();
		
	return 0;		
}
