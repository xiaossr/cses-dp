#include <iostream>
using namespace std;

long long N, x[5005], dp[5005][5005][2][2], s[5005][5005];

int main()
{
	// range dp
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> x[i], dp[i][i][(N + 1) % 2][(N + 1) % 2] = x[i];

	for (int len = 1; len < N; len++)
	{
		for (int i = 0; i < N - len; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					if (j == k) // choose this round
						dp[i][i + len][j][k] = max(dp[i + 1][i + len][!j][k] + x[i], dp[i][i + len - 1][!j][k] + x[i + len]);
					else
						dp[i][i + len][j][k] = min(dp[i + 1][i + len][!j][k], dp[i][i + len - 1][!j][k]);
				}
			}
		}
	}

	/*for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
			for(int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
				{
					cout << "left: " << i << ", right(inclusive): " << j << "\n";
					cout << "last choice made: " << k << ", looking at: " << l << "\n";
					cout << "value: " << dp[i][j][k][l] << "\n\n";
				}*/

	cout << dp[0][N - 1][0][0] << "\n";

	return 0;
}