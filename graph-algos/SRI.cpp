#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector< pair<int, ll> > adj[100005];
vector<ll> ans;

void dij()
{
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > q;
	ans[1] = 0;
	q.push({ 0, 1 });

	while (!q.empty())
	{
		ll d = q.top().first;
		int at = q.top().second;
		q.pop();

		if (d > ans[at]) continue;

		ans[at] = d;
		for (const auto& k : adj[at])
			if (ans[k.first] > d + k.second)
				q.push({ d + k.second, k.first }), ans[k.first] = d + k.second;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;

	int a, b, c;
	ans.resize(N + 3, 1e14 + 3);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adj[a].pb({ b, c });
		//adj[b].pb({ a, c });
	}

	dij();

	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}
