#include <iostream>
#include <cmath>
using namespace std;

long long A, B;

// digit dp ideas
// long long dp[20][10][10][2];
// dp[i][cur][k][tight] = number of numbers with i digits, prev digit k and cur digit cur
// i = current digit (location 0-17)
// cur = chosen digit (0-9)
// k = prev digit (0-9)
// tight = if next to max num or not
// dp[i][cur][k][tight] += dp[i - 1][k][for other 0-9]["other" depends on tight]
// starting 0 can be adj

long long xpow(long long x, long long y)
{
	long long ret = 1;
	while (y)
	{
		if (y & 1)
			ret *= x;
		y /= 2, x *= x;
	}

	return ret;
}

// combinatronic solution
long long solve(long long num)
{
	if (num < 0) return 0;
	if (num == 0) return 1;

	bool flg = 1;
	while (flg)
	{
		flg = 0;
		for (long long i = log10(num) - 1, m = xpow(10, i); i >= 0; i--, m = xpow(10, i))
			if (num / (m * 10) % 10 == num / m % 10) //  if repeating one digit
				num = (num / m - 1) * m + m - 1, flg = 1; // go to nearest non rep
	}

	int n = log10(num) + 1; // num digits
	long long dp[22][2] = { 0 };  // dp[digits][tight]
	dp[0][0] = 1, dp[0][1] = 1;

	long long ret = 1, m = 1;
	for (int i = 1; i < n; i++, m *= 10)
	{
		dp[i][0] = xpow(9, i);
		dp[i][1] = (num / m % 10) * dp[i - 1][0] + dp[i - 1][1];
		if (num / m % 10 > num / (m * 10) % 10) dp[i][1] -= dp[i - 1][0];
		// dp[i][1] is / 10 part for next numbers with digit i + 1

		ret += dp[i][0];
	}

	dp[n][1] = (num / m % 10 - 1) * dp[n - 1][0] + dp[n - 1][1];
	// add limit for n digits (same as num)
	return ret + dp[n][1];
}

int main()
{
	cin >> A >> B;

	cout << solve(B) - solve(A - 1) << "\n";

	return 0;
}