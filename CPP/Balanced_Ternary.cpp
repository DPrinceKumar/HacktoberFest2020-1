/*          STEPS
       1. Convert decimal to ternary number system.
       2. Convert ternary to balanced ternary system, using below steps: 
            - traverse the ternary number, right to left by leaving 0 and 1 as it is
            - when encounter 2, change it to Z and add +1 to the next digit in iteration.
            - Some digits may become +3, then replace +3 with 0 and add +1 to next digit in iteration.
            - complete this process until you convert all the digits.
*/

#include <bits/stdc++.h>
using namespace std;

//      OUTPUT
//            Equivalent Balanced Ternary of 238 is: 100Z11

string balancedTernary(int n)
{
	string output = "";
	while (n > 0) {
		int rem = n % 3;
		n = n / 3;
		if (rem == 2) {
			rem = -1;
			n++;
		}
		output = (rem == 0
					? '0'
					: (rem == 1)
							? '1'
							: 'Z')
				+ output;
	}
	return output;
}

int main()
{

	int n = 238;

	cout << "Equivalent Balanced Ternary of "
		<< n << " is: "
		<< balancedTernary(n);

	return 0;
}
