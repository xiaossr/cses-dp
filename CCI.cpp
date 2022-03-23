#include <iostream>
using namespace std;

int N, X;
int coins[103], dp[1000005];

int main()
{
	cin >> N >> X;
	for (int i = 0; i < N; i++)
		cin >> coins[i];

	dp[0] = 1;
	for (int i = 1; i <= X; i++)
		for (int j = 0; j < N; j++)
			if (i - coins[j] >= 0)
				dp[i] += dp[i - coins[j]], dp[i] %= (int)1e9 + 7;

	cout << dp[X] << "\n";

	return 0;
}