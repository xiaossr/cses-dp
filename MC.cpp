#include <iostream>
using namespace std;

int N, X;
int coins[103], dp[1000005];

int main()
{
	cin >> N >> X;
	for (int i = 0; i < N; i++)
		cin >> coins[i];

	for (int i = 1; i <= X; i++)
		dp[i] = X + 3;
	dp[0] = 0;

	for (int i = 1; i <= X; i++)
		for (int j = 0; j < N; j++)
			if (i - coins[j] >= 0 && dp[i - coins[j]] != X + 3)
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);

	cout << (dp[X] == X + 3 ? -1 : dp[X]) << "\n";

	return 0;
}