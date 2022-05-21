#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define s second
#define f first

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;

int N, M;
vector< pair<int, ll> > adj[maxn];
bool vis[100005];

ll prims()
{
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pq;
	ll ret = 0;
	int cnt = 0;
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int at = pq.top().second;
		ll d = pq.top().first;
		pq.pop();

		if (vis[at]) continue;
		vis[at] = 1;
		cnt++;
		ret += d;
		
		for (const auto &nx : adj[at])
		{
			int nat = nx.first;
			ll nd = nx.second;
			if (vis[nat]) continue;
			pq.push({ nd, nat });
		}
	}

	return (cnt != N ? -1 : ret);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> M;

	int a, b; ll c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].pb({ a, c });
	}

	ll ans = prims();
	if (ans == -1)
		cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
	
	return 0;
}
