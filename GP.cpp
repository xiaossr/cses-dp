#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int N;
char grid[1003][1003];
int dp[1003][1003];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> grid[i];
	dp[0][0] = (grid[0][0] == '.' ? 1 : 0);

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == '*') continue;
			if (i) dp[i][j] += (grid[i - 1][j] == '.' ? dp[i - 1][j] : 0);
			if (j) dp[i][j] += (grid[i][j - 1] == '.' ? dp[i][j - 1] : 0);
			dp[i][j] %= MOD;
		}

	cout << dp[N - 1][N - 1] << "\n";

	return 0;
}