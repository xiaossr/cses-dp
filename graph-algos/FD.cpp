#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector< pair<int, ll> > adj[100005];
vector<ll> vis[2];

void dij()
{
	priority_queue< pair<ll, pair<int, bool> >, 
		vector< pair<ll, pair<int, bool> > >, 
		greater< pair<ll, pair<int, bool> > > > pq;

	pq.push({ 0, {1, 0} });
	vis[0][1] = 0;
	
	while (!pq.empty())
	{
		ll d = pq.top().first;
		int at = pq.top().second.first;
		bool used = pq.top().second.second;
		pq.pop();

		if (d > vis[used][at]) continue;

		for (const auto& k : adj[at])
		{
			if (d + k.second < vis[used][k.first])
				vis[used][k.first] = d + k.second, pq.push({ vis[used][k.first], {k.first, used} });
			if (!used && d + k.second / 2 < vis[1][k.first])
				vis[1][k.first] = d + k.second / 2, pq.push({ vis[1][k.first], {k.first, 1} });
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;

	int a, b; ll c;
	for (int i = 0; i < M; i++)
		cin >> a >> b >> c, adj[a].push_back({ b, c });
	vis[0].resize(N + 3, LLONG_MAX), vis[1].resize(N + 3, LLONG_MAX);

	dij();

	cout << min(vis[0][N], vis[1][N]) << "\n";

	return 0;
}
