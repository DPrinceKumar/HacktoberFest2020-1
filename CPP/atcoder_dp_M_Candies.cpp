#include<bits/stdc++.h>
using namespace std;


/*

dp(i,j)   -> sum({	dp(i-1,j) ,dp(i-1,j-1) ,dp(i-1,j-2)  , ............ dp(i-1,j-ai)	})
dp(i,j-1) -> sum({			  dp(i-1,j-1) ,dp(i-1,j-2) ,dp(i-1,j-3)  , ......... dp(i-1,j-1-ai)	})
dp(i,j)   -> dp(i,j-1)  - dp(i-1,j-1-ai) + dp(i-1,j)

*/

const int mod = 1e9 + 7;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<int> a(n + 1);
	for (int i = 1 ; i <= n ; i++)cin >> a[i];

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	dp[0][0] = 1;

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 0 ; j <= k; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] %= mod;
			if (j - 1 - a[i] >= 0)dp[i][j] -= dp[i - 1][j - 1 - a[i]];
			dp[i][j] = (dp[i][j] + mod) % mod;
		}
	}
	cout << dp[n][k] << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();
	return 0;
}