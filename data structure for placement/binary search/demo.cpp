#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
    // vector<int> v  = {1,2,3,4,5,6,7,8};
    // int key = 8;
    // int l   = 0;
    // int r = v.size()-1;

	// binary seach
	// while (r-l > 1)
	// {
	// 	int mid = (r+l)/2;
	// 	if (v[mid] < key)
	// 	{
	// 		l = mid;
	// 	}
	// 	else{
	// 		r = mid;
	// 	}
		
	// }
	
	// if (v[l] == key)
	// {
	// 	cout<<"Found : "<<v[l]<<endl;
	// }
	// else if (v[r] == key)
	// {
	// 	cout<<"Found : "<<v[r]<<endl;
	// }
	// else{
	// 	cout<<"Not found :( "<<endl;;
	// }
	
//  LOWWER BOUND
	// vector<int> v  = {1,3,4,5,6,7,8};
    // int key = 3;
    // int l   = 0;
    // int r = v.size()-1;
	
	// while (r-l > 1)
	// {
	// 	int mid = (r+l)/2;

	// 	if (v[mid] > key)
	// 	{
	// 		r = mid;
	// 	}
	// 	else{
	// 		l = mid+1;
	// 	}
		
	// }

	// while (r-l > 1)
	// {
	// 	int mid = (l + r)/2;
	// 	if (v[mid]<key)
	// 	{
	// 		l = mid +1;
	// 	}
	// 	else{
	// 		r = mid;
	// 	}
		
	// }
	
	// if (v[l] >= key)
	// {
	// 	cout<<"Found : "<<v[l]<<endl;
	// }
	// else if (v[r] >= key)
	// {
	// 	/* code */
	// 	cout<<"Found : "<<v[r]<<endl;
	// }
	// else{
	// 	cout<<"Not Found :( "<<endl;;
	// }
	
	
// UPPER BOUND
	
	vector<int> v  = {1,3,4,5,6,7,8};
    int key = 8;
    int l   = 0;
    int r = v.size()-1;

	while(r-l > 1){
		int mid =  (r + l)/2;
		if (v[mid]<= key)
		{
			l = mid + 1;
		}
		else{
			r  = mid;
		}
		
	}
	
	
	if(v[l] > key)
	{
		cout<<"Found : "<<v[l]<<endl;
	}
	else if (v[r] > key)
	{
		/* code */
		cout<<"Found : "<<v[r]<<endl;
	}
	else{
		cout<<"Not Found :( "<<endl;;
	}
	




    return 0;
}