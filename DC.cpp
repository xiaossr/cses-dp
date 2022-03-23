#include <iostream>
using namespace std;

typedef long long ll;

int N;
int dp[1000005];

int main()
{
	cin >> N;

	dp[0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 6; j++)
			if (i - j >= 0)
				dp[i] += dp[i - j], dp[i] %= (int) 1e9 + 7;

	cout << dp[N] << endl;

	return 0;
}