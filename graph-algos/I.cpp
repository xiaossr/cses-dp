#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

const int MOD = 1e9 + 7;

int N, M;
vector< pair<int, ll> > adj[100005];
ll price[100005];
int ans[100005][3]; // [0] min flights [1] max flights [2] num flights

// dfs or topo sort?

// one search to find min cost
// one search to find max path
// one search to find min path
void searchcost()
{
	priority_queue<pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pq;
	price[1] = 0; // starting price is 0
	ans[1][2] = 1; // 1 possible way to start from 1
	ans[1][0] = 0; // 0 flights taken
	ans[1][1] = 0; // 0 flights taken
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		ll p = pq.top().first;
		int at = pq.top().second;
		pq.pop();
		if (p != price[at]) continue;

		for (const auto& nx : adj[at])
		{
			ll np = nx.second;
			int nat = nx.first;

			if (price[nat] > p + np)
			{
				// reset statistics
				ans[nat][2] = ans[at][2];
				ans[nat][0] = ans[at][0] + 1;
				ans[nat][1] = ans[at][1] + 1;

				price[nat] = p + np;
				pq.push({ p + np, nat });
			}
			else if (price[nat] == p + np)
				ans[nat][0] = min(ans[nat][0], ans[at][0] + 1), 
				ans[nat][2] += ans[at][2], ans[nat][2] %= MOD,
				ans[nat][1] = max(ans[nat][1], ans[at][1] + 1);
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin("test_input.in");

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		price[i] = 1e14 + 5;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adj[a].pb({ b, c });
	}

	searchcost();

	cout << price[N] << " " << ans[N][2] << " " << ans[N][0] << " " << ans[N][1] << "\n";
	
	return 0;
}
