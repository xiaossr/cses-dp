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
vector<int> adj[100005];
int cnt[100005], par[100005];
bool from1[100005];
queue<int> q;

void topo_sort()
{
	while (!q.empty())
	{
		int k = q.front();
		q.pop();

		for (const auto& nx : adj[k])
		{
			cnt[nx] += (from1[k] ? cnt[k] : 0); // only sum those reachable from level 1
			cnt[nx] %= MOD;
			par[nx]--;

			if (from1[k]) from1[nx] = 1;
			if (par[nx] == 0) q.push(nx);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		par[b]++;
	}

	for (int i = 1; i <= N; i++)
		if (par[i] == 0)
			q.push(i);

	cnt[1] = 1;
	from1[1] = 1;
	topo_sort();

	cout << cnt[N] << "\n";
	
	return 0;
}
