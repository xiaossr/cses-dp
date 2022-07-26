#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N, X;
int w[22];
vector<pii> dp;

//int dp[1 << 20], a[1 << 20];
//
//int sum(int mask) // find all 1s, add w[i]
//{
//	int ret = 0;
//	int i = 0;
//	while (mask)
//	{
//		int res = mask % 2;
//		ret += res * w[i++];
//		mask /= 2;
//	}
//
//	return ret;
//}
//
//int ans = 22;
// TLE
//void search(int curmask, int vis, int elev)
//{
//	if (vis == (1 << N) - 1)
//	{
//		// cout << curmask << " " << vis << " " << elev << "\n";
//		ans = min(ans, elev);
//		return;
//	}
//
//	int csum = dp[curmask];
//	for (int i = 0; i < N; i++)
//	{
//		if ((vis) & (1 << i)) continue;
//		vis ^= 1 << i;
//		curmask ^= 1 << i;
//		
//		if (w[i] + csum > X) search(1 << i, vis, elev + 1);
//		else search(curmask, vis, elev);
//
//		vis ^= 1 << i;
//		curmask ^= 1 << i;
//	}
//
//	return;
//}

int main()
{
	cin >> N >> X;

	for (int i = 0; i < N; i++)
		cin >> w[i];

	//for (int i = 0; i < 1 << N; i++)
	//	dp[i] = sum(i), a[i] = X + 1;

	//search(0, 0, 1);
	//cout << ans << "\n";

	dp.resize(1 << N, { N + 1, X + 1 });
	dp[0] = { 1, 0 };
	// dp[mask] = {# of elevator rides, current weight}
	for(int mask = 0; mask < 1 << N; mask++)
		for (int i = 0; i < N; i++)
		{
			if (mask & (1 << i))
			{
				pii pr = dp[mask ^ (1 << i)];
				if (pr.second + w[i] <= X)
					pr.second += w[i];
				else pr.first++, pr.second = w[i];
				dp[mask] = min(dp[mask], pr);
			}
		}

	cout << dp[(1 << N) - 1].first << "\n";

	return 0;
}