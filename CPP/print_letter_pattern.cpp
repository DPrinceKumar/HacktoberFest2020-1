/*
patterns include
 * * ***** 
 * * ******
 * *     **
 * *     **
 * * ***** 
 * *       
 * *       
 * *       
 * *     
  
   ****  
  *    * 
 *      *
 *      *
 *      *
 *      *
  *    * 
   ****   

 ********
       **
       **
       **
       **
 *     **
 ********
  ****** 
*/

#include <iostream>
using namespace std;

void J(int n) 
{ 
   cout<<"\n";
    for (int i = 0; i < 8; i++) { 
        cout<<" ";
  
        for (int h = 0; h < 8; h++) { 
            if (i < 1) { 
               cout<<"*"; 
            } 
            else if (i == 5 && h < 1) { 
                cout<<"*";  
            } 
            else if (i < 7 && h > 5) { 
                cout<<"*";  
            } 
            else if (i == 7 
                     && (h == 0 || h == 7)) 
               cout<<" ";  
            else if (i > 5) { 
                cout<<"*";  
            } 
            else
                cout<<" ";  
        } 
        cout<<"\n";  
    } 
} 
void O(int n) 
{ 
     cout<<"\n"; 
    for (int i = 0; i < 8; i++) { 
        cout<<" "; 
        for (int o = 0; o < 8; o++) { 
            if (i == 0 && (o <= 1 || o >= 6 - i)) 
                cout<<" "; 
            else if (i == 1 
                     && (o == 0 || o == 8 - i 
                         || (o < 6 && o > 1))) 
                cout<<" "; 
            else if (i == 2 
                     && (o == 1 || o == 8 - i 
                         || (o < 6 && o > 1))) 
                cout<<" "; 
            else if ((i == 3 || i == 4 || i == 5) 
                     && (o > 0 && o < 7)) 
               cout<<" "; 
            else if (i == 6 
                     && (o == 0 || o == 8 + 5 - i 
                         || (o < 6 && o > 1))) 
                cout<<" "; 
            else if (i == 7 
                     && (o <= 1 || o >= 6 - i + 7)) 
                cout<<" ";
            else { 
                cout<<"*"; 
            } 
        } 
        cout<<"\n";
    } 
} 
void P(int n) 
{   
    cout<<"\n"; 
    for (int i = 0; i < 8+n; i++) { 
        cout<<" "; 
        { 
            cout<<"* * "; 
        } 
  
        for (int r = 0; r < 6; r++) { 
            if (i == 0 && r < 5) 
                cout<<"*"; 
            else if (i == 1) 
                cout<<"*"; 
            else if (i < 4 && i > 0 && r > 3) { 
                cout<<"*"; 
            } 
  
            else if (i == 4 && r < 5) { 
                cout<<"*";  
            } 
            else
                cout<<" "; 
        } 
        cout<<"\n"; 
    } 
} 
int main() {
    int k=1;
    cout<<"Welcome to the letter printer"<<endl;
    while(k){
    int f=0,n;
    while(f==0)
    {
        cout<<"Enter a size.";
        cin>>n;
        if(n>=7 && n%2 !=0)
        {
            f++;
        }
        else{
            cout<<"Invalid size.";
            continue;
            
        }
    }
    string c;
    int m=0;
    while(m==0)
    {
        cout<<"Enter a letter.";
        getline(cin,c);
        if(c=="J"||c=="O"||c=="P")
        {
            m++;
        }
    
        else{
            cout<<"Invalid letter.";
            continue;
            
        }
    }
switch(c[0]){
    case 'P':
        P(n);
    break;
    case 'O':
        O(n);
    break;
    case 'J':
        J(n);
    break;
    default:
        break;
}
string ans;
cout<<"Would you like to continue(Y or N)";
getline(cin,ans);
if(ans=="N"||ans=="n"){
    k=0;
}
else
    continue;
}
return 0;
}