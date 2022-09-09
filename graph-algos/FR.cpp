#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M, K;
vector< pair<int, ll> > adj[100005];
vector<ll> dists[100005];

void dij()
{
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pq;
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		ll d = pq.top().first;
		int at = pq.top().second;
		pq.pop();

		if (dists[at].size() == K) continue;
		dists[at].push_back(d);

		for (const auto& nx : adj[at])
			if (dists[nx.first].size() < K)
				pq.push({ d + nx.second, nx.first });
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	int a, b; ll c;
	for (int i = 0; i < M; i++)
		cin >> a >> b >> c, adj[a].push_back({ b, c });
	
	dij();

	for (const auto& k : dists[N])
		cout << k << " ";
	cout << "\n";
	
	return 0;
}
