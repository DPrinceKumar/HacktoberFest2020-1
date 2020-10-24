// Rahul Roy
// Github Profile: https://github.com/rahulroy06/
#include<iostream>
#include<string.h>
using namespace std;

int main(){
double c, f, k;
int choice;
char a;
conv:
cout<<"\t\tWelcome to Temperature Converter"<<endl;
cout<<"\tYou can Perform any of the following conversions"<<endl;
cout<<"_________________________________________________________________"<<endl<<endl;
cout<<"Choose any of the followning Conversion"<<endl;
cout<<"\t 1 : Celsius into Farhenhiet"<<endl;
cout<<"\t 2 : Farhenhiet into Celsius"<<endl;
cout<<"\t 3 : Kelvin into Celsius"<<endl;
cout<<"\t 4 : Celsius into Kelvin"<<endl;
cout<<"\t 5 : Kelvin into Farhenhiet"<<endl;
cout<<"\t 6 : Farhenhiet into Kelvin"<<endl<<endl;
cout<<"Please select an appropriate option[1-6] : ";
cin>>choice;

if(choice != ' '){
	switch(choice){
		case 1:
			cout<<"\t\tConverting Celsius in Farhenhiet"<<endl;
			cout<<"Enter temperature in Celcius"<<endl;
			cin>>c;
			f = (c * 9/5)+32;
			cout<<"The temperture in Farhenhiet = "<<f<<endl; break;
		case 2: 
			cout<<"\t\tConverting Farhenhiet into Celsius"<<endl;
			cout<<"Enter temperature in Farhenhiet"<<endl;
			cin>>f;
			c = (5.0/9)*(f - 32);
			cout<<"The temperture in Celsius = "<<c<<endl; break;
		case 3:
			cout<<"\t\tConverting Kelvin into Celsius"<<endl;
			cout<<"Enter temperature in Kelvin"<<endl;
			cin>>k;
			c = k - 273.15;
			cout<<"The temperture in Celsius = "<<c<<endl; break;
		case 4:
			cout<<"\t\tConverting Celsuis into Kelvin"<<endl;
			cout<<"Enter temperature in Celsuis"<<endl;
			cin>>c;
			k = c + 273.15;
			cout<<"The temperture in Kelvin = "<<k<<endl;  break;
		case 5:
			cout<<"\t\tConverting Kelvin in Farhenhiet"<<endl;
			cout<<"Enter temperature in Kelvin"<<endl;
			cin>>k;
			f = ((k-273.15) * 9/5)+32;
			cout<<"The temperture in Farhenhiet = "<<f<<endl; break;
		case 6: 
			cout<<"\t\tConverting Fahrenheit into Kelvin"<<endl;
			cout<<"Enter temperature in Farhenheit"<<endl;
			cin>>f;
			k = ((5.0/9)*(f - 32))+273;
			cout<<"The temperture in Kelvin = "<<k<<endl; break;
		default:
			cout<<"you have entered an in valid entry, Please try again"<<endl;
			cout<<"_____________________________________________________"<<endl;    
			goto conv;
	}
}	
cout<<"Do you want to do more conversion [y/n]?"<<endl;
cin>>a;
switch(a){
	case 'Y':
		goto conv; break;
	case 'y':
		goto conv; break;
	case 'n':
		exit;
	case 'N':
		exit;
	default:
		exit;
}
return 0;
}
