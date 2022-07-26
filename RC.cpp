#include <iostream>
using namespace std;

int a, b;
int dp[505][505];

int search(int w, int h)
{
	if (dp[w][h] != -1) return dp[w][h];

	int ret = a * b + 1;
	for (int i = 1; i < w; i++)
		ret = min(ret, search(i, h) + search(w - i, h) + 1);

	for (int j = 1; j < h; j++)
		ret = min(ret, search(w, j) + search(w, h - j) + 1);

	return dp[w][h] = ret;
}

int main()
{
	cin >> a >> b;

	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
			dp[i][j] = -1, dp[i][i] = 0;

	cout << search(a, b) << "\n";

	return 0;
}