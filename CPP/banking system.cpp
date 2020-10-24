//created by Amit Kumar

#include<bits/stdc++.h>     
using namespace std; 

//////////////////typecasting from string to integer
int toString(char a[]) {
  int c, sign, offset, n;
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }
  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
  n = 0;
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
  if (sign == -1) {
    n = -n;
  }
  return n;
}

///////////////////  Validation of string for charwise data type check//////////////////////////
bool validation_number(string n){
    int flag=1;
    for(int i=0;i<n.length();i++)
    {
        if(isdigit(n[i])==0)
        flag=0;
    }
    if(flag==1)
    return true;
    else
    {
        return false;
    } 
}

bool validation_alpha(string n){
    int flag=1;
    for(int i=0;i<n.length();i++)
    {   if((isalpha(n[i])==0)&&n[i]!=' ')
        flag=0;
    }
    if(flag==1)
    return true;
    else
    {
        return false;
    }
}

////////////////////login system
bool isloggedin(){
   string username,password,un,pw;
   cout<<"Enter User Name"<<" ";
   cin>>username;
   cout<<"enter password"<<" ";
   cin>>password;
   ifstream read("record");
   getline(read,un);
   getline(read,pw);
   if(un==username && pw==password){
     return true;
    }
   else{
     return false;
    }
}

//////////////////////////////////// Base Class////////////////////////////////////////////
class account     
{ public:
    int accountno;
    string name;
    int dep;
    char type;
    public:
    // //static int count;
// //    account()
// //   {
// //     count++;
// //   }
    void create_account();    //function to create a new account
    void show_account() const;    //function to show account details
    void modify();    //function to modify account details
    void adep(int);    //function to accept deposit amount
    void draw(int);    //function to subtract withdrawal amount
    void report() const;    //function to show data in tabular format
    int retaccountno() const;    //For returning account number
    int retbal() const;    //For returning balance amount
    char qtype() const;    //For returning type of account
    void operator ++();   //For giving balance when subjected to one month interset rate increment
    void operator ++(int);  //For giving balance when subjected to one year interset rate increment
};  

// //int account::count=0;//static count thinga.....////////////////////////

void account::create_account()
{
    string xaccountno,xdep;
    string xname;
    char xtype;
    int sign = 1, number = 0, index = 0;
    for(int i=0;i<=1;)
    {
        cout<<"\nEnter The Account Number :";
        cin>>xaccountno;
        if(xaccountno[0] == '-'){
        sign = -1;
        index = 1;
        }
     
         while(xaccountno[index] != '\0'){
          if(xaccountno[index] >= '0' && xaccountno[index] <= '9'){
            number = number*10 + xaccountno[index] - '0';
         } else {
            break;
                }
            index++;
             }
    /* multiply number with sign to make it negative number if sign < 0*/
          number = number * sign;
        
         if(validation_number(xaccountno))
         { 
		    accountno=number;
            break;}
         else
         {
            cout<<"Invalid Account Number"<<endl;
         }
        
    }
    
    for(int i=0;i<=1;)
    {
        cout<<"\n\nEnter, Name of The Account Holder : ";
        cin>>xname;
        if(validation_alpha(xname))
        {name=xname;
        break;}
        else
        {   cout<<"Invalid Name"<<endl;
        }
    }
    for(int i=0;i<=1;)
    {
        cout<<"\nEnter Type of Account(Current/Savings) char input: ";
        cin>>xtype;

        if(isalpha(xtype))
        {type=xtype;
        break;}
        else
        {
            cout<<"Invalid type"<<endl;
        }
        
    }
    for(int i=0;i<=1;)
    {
        cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
        cin>>xdep;     //We have set the minimum initial amount for savings be 500 & for current be 1000   


      sign = 1; number = 0; index = 0;
        if(xdep[0] == '-'){
        sign = -1;
        index = 1;
    }
     
    while(xdep[index] != '\0'){
        if(xdep[index] >= '0' && xdep[index] <= '9'){
            number = number*10 + xdep[index] - '0';
        } else {
            break;
        }
        index++;
    }
    /* multiply number with sign to make it negative number if sign < 0*/
    number = number * sign;
        
        if(validation_number(xdep))
        {if(((type=='s'||type=='S')&&(number>=500))||((type=='c'||type=='C')&&(number>=500)))
            {dep=number;
              break;
			}
		}
        else
        {
            cout<<"Please check the condition"<<endl;
        }
}
    cout<<"\n\n\nCongrats Account Has Been Created..";
}

void account::show_account() const
{
    cout<<"\nAccount Number : "<<accountno;
    cout<<"\nAccount Holder Name : ";
    cout<<name;
    cout<<"\nType of Account : "<<type;
    cout<<"\nBalance amount : "<<dep;
}


void account::modify()
{
    cout<<"\nAccount Number : "<<accountno;
    cout<<"\nModify Account Holder Name : ";
    cin>>name;  
   cout<<"\nModify Type of Account : ";
    cin>>type;
    cout<<"\nModify Balance amount : ";
    cin>>dep;
}
 
 
void account::adep(int x)
{
    dep+=x;
}
    
void account::draw(int x)
{
    dep-=x;
}
    
void account::report() const
{
    cout<<accountno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<dep<<endl;
}
    
int account::retaccountno() const
{
    return accountno;
}

int account::retbal() const
{
    return dep;
}

char account::qtype() const
{
    return type;
}

void account::operator ++()
{
    cout<<"Your deposit next month with 5% monthly increment will be "<<(dep*0.05)+dep<<endl;
}

void account::operator ++(int)
{
    cout<<"Your deposit next year with 12% year increment will be "<<(dep*0.12)+dep<<endl;
}
////////////////////////////////////////////////////////////// Derived classes///////////////////////////////////////////
class scheme:public account
{
    int z;
    public:
    void monthly(account a)
    {

    }
    void yearly(account a)
    {

    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void write_account();    //function to write record in binary file
void display_sp(int);    //function to display account details given by user/input
void modify_account(int);    //function to modify 
void delete_account(int);    //function to delete
void display_all();        //function to display all account details
void dep_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();    //starting screen

int main()
{int choice;
 cout<<"1:  register";
 cout<<"\n2: log in";
 b:cout<<"\nyour choice : ";
 cin>>choice;
 if(choice==1)
 {
  string username,password;
  cout<<"select a username ";
  cin>>username;
  cout<<"choose password ";
  cin>>password;
  ofstream file("record");
  file<<username<<endl<<password;
  file.close();
  system("clear");
cout << "Flushing the output stream." << flush;
  main();
 }
 else if(choice==2)
 {
  bool status =isloggedin();
  if(!status)
  {
   cout<<"\t\tEither user name or password entered is wrong  "<<endl<<"\t\t\ttry again "<<endl;
   system("pause");
   goto b;
   return 0;
  }
  else
  {
   cout<<"succesfully logged in ";
   system("clear");
    char ch;
    int num;
        cout<<"\n\n\t\t\tWelcome To SB BANKING SYSTEM";
        cout<<"\n\n\t\tA C++ Project created by Amit Kumar and Saksham Sharma";
    do
    {
        cout<<"\n\n\n\tACTION MENU";
        cout<<"\n\n\t01. NEW ACCOUNT";
        cout<<"\n\n\t02. DEPOSIT";
        cout<<"\n\n\t03. WITHDRAW";
        cout<<"\n\n\t04. BALANCE ENQUIRY";
        cout<<"\n\n\t05. COMPLETE ACCOUNT HOLDERS LIST";
        cout<<"\n\n\t06. CLOSE AN ACCOUNT";
        cout<<"\n\n\t07. MODIFY AN ACCOUNT";
        cout<<"\n\n\t08. EXIT";
        cout<<"\n\n\tSelect Your Option (1-8) ";
        cin>>ch;
        // system("clear");   //Clear The Screen
        cout << "Flushing the output stream." << flush;
        switch(ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout<<"\n\n\tEnter The Account Number : "; cin>>num;
            dep_withdraw(num, 1);
            break;
        case '3':
            cout<<"\n\n\tEnter The Account Number : "; cin>>num;
            dep_withdraw(num, 2);
            break;
        case '4': 
            cout<<"\n\n\tEnter The Account Number : "; cin>>num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout<<"\n\n\tEnter The Account Number : "; cin>>num;
            delete_account(num);
            break;
         case '7':
            cout<<"\n\n\tEnter The Account Number : "; cin>>num;
            modify_account(num);
            break;
         case '8':
            cout<<"\n\n\tThanks For Visiting Our Bank!";
            break;
         default :cout<<"\a";
        }
        cin.get();
    }while(ch!='8');
    return 0;
	}
  }
}// Function To write the account data to .dat file 
void write_account()
{   account ac;
    ofstream x;
    x.open("info.dat",ios::binary|ios::app);
    ac.create_account();
    x.write((char *)&ac, sizeof(ac));
    x.close();
}


void display_sp(int n)      //function to retrive a record from file stored
{
	account ac;
	int flag=0;
	ifstream inFile;
    inFile.open("info.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
    while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retaccountno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
    inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}//function to modify record of an account which is stored in file
void modify_account(int n)
{   bool found=false;
    account ac;
    fstream x;
    x.open("info.dat",ios::binary|ios::in|ios::out);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!x.eof() && found==false)
    {
        x.read((char *) &ac, sizeof(ac));
        if(ac.retaccountno()==n)
        {
            ac.show_account();
            cout<<"\n\nEnter The New Details of account"<<endl;
            ac.modify();
            long unsigned int pos=(-1)*static_cast<int>(sizeof(account));
            x.seekp(pos,ios::cur);
            x.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\n\n\t Record Updated";
            found=true;
          }
    }
    x.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}//function to delete a record from file
void delete_account(int n)
{ 
    account ac;
    ifstream x;
    x.open("info.dat",ios::binary);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    ofstream y;
    y.open("Temp.dat",ios::binary);
    x.seekg(0,ios::beg);
    while(x.read((char *) &ac, sizeof(ac)))
    {
        if(ac.retaccountno()!=n)
        {
            y.write((char *) &ac, sizeof(ac));
        }
    }
    x.close();
    y.close();
    remove("info.dat");
    rename("Temp.dat","info.dat");
    cout<<"\n\n\tRecord Deleted ..";
}// function to display account details from the stored file
void display_all()
{
    account ac;
	ifstream inFile;
	inFile.open("info.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

	cout<<"A/c no.\t\tNAME\t\t\t\tType\t\t     Balance\n\n";

	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}// function to withdraw amout from the account
void dep_withdraw(int n, int option)
{
    int amt;
    bool found=false;
    account ac;
    fstream x;
    x.open("info.dat", ios::binary|ios::in|ios::out);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!x.eof() && found==false)
    {
        x.read((char *)&ac, sizeof(ac));
        if(ac.retaccountno()==n)
        {
            ac.show_account();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nEnter The amount to be deposited";
                cin>>amt;
                ac.adep(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                cout<<"\n\nEnter The amount to be withdraw";
                cin>>amt;
                int bal=ac.retbal()-amt;
                if((bal<500 && ac.qtype()=='S') || (bal<1000 && ac.qtype()=='C'))
                    cout<<"Insufficience balance";
                else
                    ac.draw(amt);
            }
            long unsigned int pos=(-1)*static_cast<int>(sizeof(ac));
            x.seekp(pos,ios::cur);
            x.write((char *) &ac, sizeof(ac));
            cout<<"\n\n\t Record Updated";
            found=true;
           }
         }
    x.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
