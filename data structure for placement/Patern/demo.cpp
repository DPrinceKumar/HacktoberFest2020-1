#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 245567;

    int ans = 0;
    int i = 0;

    int tp = n;

    while (tp)
    {
        tp /= 10;
        i++;
    }

    while (n)
    {
        int k = 10;
        int rem = n % k;
        if (rem % 2 == 0)
        {
            rem++;
        }
        else
        {
            rem--;
        }
        ans = ans * 10 + rem;

        n /= 10;
    }
    // 674453
    // 354476
    cout << ans << endl;
    int ans2 = 0;

    while (ans)
    {
        int k = 10;
        int rem = ans % k;

        ans2 = ans2 * 10 + rem;
        ans /= 10;
    }

    cout << ans2;
    return 0;
}

/*



saving  = 0;
if(inp == 120 && tenp == 90){
    temp += 120;
}
elif(inp == 60){
    
}
elif(inp == 30){
    saving += 30;
}

*/

/*
1 5 10 20 50
*/

// n =  58
// 50 = 1
// 5 = 1
// 1 = 3

// if (n >= 50)
// {
//     n = n - 50;
//     c++;
// }
// else if (n >= 20)
// {
//     n = n - 20;
//     c++;
// }
// else if (n >= 10)
// {
//     n = n - 10;
//     c++;
// }
// else if (n >= 5)
// {
//     n = n - 5;
//     c++;
// }
// else if (n >= 1)
// {
//     n = n - 1;
//     c++;
// }
// return c;
