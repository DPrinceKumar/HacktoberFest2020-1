#include<iostream> 
using namespace std; 
int main() 
{ 
int a[20],n; 
int i,j,k,r,nr_digits=0,divisor=1,largest; 
cout<<"enter the size of the array "; 
cin>>n; 
for(i=0;i<n;i++) 
cin>>a[i]; //a[]={ 78,46,302,193,24,28} 78%10=8, 46%10=6,302%10=2 
largest=a[0]; 
for(i=1;i<n;i++) //Find the largest Number 
{ 
if(a[i] > largest) // largest=78, i=1, 46>78 X, i=2, 302>78 ,largest=302
largest=a[i]; 
} 
while(largest > 0) //Find number of digits in largest number largest=302 
{ //302>0 ,nr-digits=1,largest=302/10=30, 30>0 
nr_digits++; // nr-digits=2,largest=30/10=3, 3>0, nr-digits=3,largest=3/10=0 
largest /= 10; // 0>0 X 
} 
for(i=0; i < nr_digits; i++) // repeat the procedure for the nr of times equal to the nr. of digits 
{ //i=0,1,2, 
int radix[10][10]={0}, count[10]={0}; // count[]= 0,0,0,0,0,0,0,0,0,0 
for(j=0;j<n;j++) // for repeating the procedure for all n elements 
{ 
r=(a[j]/divisor)%10; // get the next least significant digit for every iteration 
radix[r][ count[r]]=a[j]; // this digit ‘r’ decides the row in which the current number should be 
count[r]++; //stored. ‘count’ array value for ‘r’th location decides the column in 2D 
} // array to which the number should go. After storing a number in a 
//particular row, the corresponding ‘count’ array element should be 
//incremented by one. 
int index=0; //now collect elements from 2D array back to ‘a’ array 
for(k=0; k<10; k++) // go to all the rows one by one 
{ // k=8 count[8]=2 j=0,1 
for(j=0; j< count[k]; j++) // in each row go up to those columns given by the value in the ‘count’ 
a[index++] = radix[k][j]; // array 
} 
divisor*=10; // 078 divisor=divisor*10 =1*10=10 r=a[j]/divisor%10= 78/10%10= 7%10=7 
} // div=div*10 = 10*10=100 r=78/100%10=0%10=0 
for(i=0;i<n;i++) 
cout<<a[i]<<" "; 
return 0; 
}
