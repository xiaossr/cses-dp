#include <iostream>
using namespace std;

int N, M;
const int MOD = 1e9 + 7;
int dp[1 << 10][2];

int main()
{
	cin >> N >> M;

	// dp[x][y][mask], everything before [x][y] covered, everything after [x + 1][y - 1] blank
	// 3 different cases (2 where [x][y] covered - vertical or horizontal tile), 1 where empty)
	// can reduce dimensions of dp to [mask][2] - prev and cur
	
	// mask exists for column - when transitioning from [x - 1][y] to [x][y], location (row) stays the same in mask

	dp[0][0] = 1;
	for(int j = 0; j < M; j++)
		for (int i = 0; i < N; i++)
		{
			for (int mask = 0; mask < (1 << N); mask++)
			{
				dp[mask][1] = dp[mask ^ (1 << i)][0]; // vertical tile (or no tile)
				if (i && !(mask & (1 << i)) && !(mask & (1 << (i - 1))))
					dp[mask][1] += dp[mask ^ (1 << (i - 1))][0]; // horizontal tile (or no tile)

				dp[mask][1] %= MOD;
			}

			for (int mask = 0; mask < (1 << N); mask++)
				dp[mask][0] = dp[mask][1];
		}

	cout << dp[0][0] << "\n";
	
	return 0;
}