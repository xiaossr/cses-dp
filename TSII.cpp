#include <iostream>
using namespace std;

int N;
const int MOD = 1e9 + 7;
int dp[505][130000]; // knapsack 

int main()
{
	cin >> N;

	dp[0][0] = 1;

	int s = N * (N + 1) / 2;
	if (s % 2)
	{
		cout << "0\n";
		return 0;
	}

	s /= 2;

	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= s; j++)
			dp[i][j] += (dp[i - 1][j] + (j - i >= 0 ? dp[i - 1][j - i] : 0)) % MOD, dp[i][j] %= MOD;

	cout << dp[N][s] << "\n";

	return 0;
}