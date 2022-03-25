#include <iostream>
using namespace std;

string s1, s2;
int dp[5005][5005];

int main()
{
	cin >> s1 >> s2;

	for (int i = 0; i <= s1.length(); i++)
		for (int j = 0; j <= s2.length(); j++)
			dp[i][j] = 1e5 + 3;

	dp[0][0] = 0;
	for (int i = 1; i <= s1.length(); i++)
		dp[i][0] = i;
	for (int j = 1; j <= s2.length(); j++)
		dp[0][j] = j;

	for (int i = 1; i <= s1.length(); i++)
		for (int j = 1; j <= s2.length(); j++)
			dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])));

	cout << dp[s1.length()][s2.length()] << "\n";

	return 0;
}