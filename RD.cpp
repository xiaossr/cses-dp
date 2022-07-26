#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[1000006];
// dp[i] = steps required to get to i

vector<int> fd(int a)
{
	vector<int> ret;
	while (a != 0)
	{
		ret.push_back(a % 10);
		a /= 10;
	}

	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		dp[i] = N + 3;
	dp[N] = 0;

	for (int i = N; i > 0; i--)
	{
		if (dp[i] == N + 3) continue;
		auto d = fd(i);
		for (const auto& k : d)
			dp[i - k] = min(dp[i - k], dp[i] + 1);
	}

	cout << dp[0] << "\n";

	return 0;
}