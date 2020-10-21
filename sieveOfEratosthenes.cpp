#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void sieveOfEratosthenes(int N)
{
       ll i,j,p[N+1]={0};
       vector< int >v;
       for( i=3; i<=N;i+=2){
         p[i]=1;
       }

       for(i=3;i<=N;i+=2){
           if(p[i]==1){
              for(j=i*i;j<=N;j+=i){
               p[j]=0;
             }
          }
       }

        p[2]=1;
        p[1]=p[0]=0;

        for(i=0;i<=N;i++){
        if(p[i]==1){
        v.push_back(i);
        }
       }

       for(i=0;i<v.size();i++){
       cout<<v[i]<<" ";
       }

 }


int main()
{
      ll N;cin>>N;
      sieveOfEratosthenes(N);
      return 0;
}
