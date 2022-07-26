#include <iostream>
using namespace std;

int T;
const int MOD = 1e9 + 7;
long long dp[1000005][2];

int main()
{
	cin >> T;
	// precalculation

	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= 1e6; i++)
	{
		dp[i][0] += ((dp[i - 1][0] * 4) % MOD + dp[i - 1][1] % MOD) % MOD;
		dp[i][1] += (dp[i - 1][0] % MOD + (dp[i - 1][1] * 2) % MOD) % MOD;
	}

	while (T--)
	{
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
	}

	return 0;
}