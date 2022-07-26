#include <iostream>
using namespace std;

int N, X, h[1003], s[1003];
int dp[1003][100005]; // dp[i][h], consider space saving

int main()
{
	cin >> N >> X;

	for (int i = 1; i <= N; i++) cin >> h[i];
	for (int j = 1; j <= N; j++) cin >> s[j];

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= X; j++)
			dp[i][j] = -1;

	dp[0][0] = 0;

	for(int i = 1; i <= N; i++)
		for (int j = 0; j <= X; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if(j - h[i] >= 0 && dp[i - 1][j - h[i]] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
		}

	cout << dp[N][X] << "\n";

	return 0;
}