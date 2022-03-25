#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int N, M, a[100005];
int dp[100005][103];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> a[i];

	if (a[1] == 0)
		for (int i = 1; i <= M; i++)
			dp[1][i] = 1;
	else dp[1][a[1]] = 1;

	for (int i = 2; i <= N; i++)
	{
		if (a[i] == 0)
			for (int j = 1; j <= M; j++)
				dp[i][j] = ((dp[i - 1][j - 1] +
				dp[i - 1][j]) % MOD + dp[i - 1][j + 1]) % MOD;
		else
			dp[i][a[i]] = ((dp[i - 1][a[i] - 1] + 
				dp[i - 1][a[i]]) % MOD + dp[i - 1][a[i] + 1]) % MOD;
	}

	int ans = 0;
	for (int i = 1; i <= M; i++)
		ans += dp[N][i], ans %= MOD;

	cout << ans << "\n";

	return 0;
}
