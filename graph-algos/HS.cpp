#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
ll dist[2505];
vector< pair< pii, ll> > e;
vector<int> adj[2505][2];
bool vis[2505][2];

void dfs(int at, int i)
{
	if (vis[at][i]) return;
	vis[at][i] = 1;
	for (auto nx : adj[at][i]) dfs(nx, i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) dist[i] = 1e14 + 5;
	dist[1] = 0;
	
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		e.push_back({{ a, b }, -c});
		adj[a][0].push_back(b), adj[b][1].push_back(a);
	}

	dfs(1, 0), dfs(N, 1);

	for (int i = 0; i < N; i++)
	{
		for (const auto& ce : e)
			if (dist[ce.first.second] > dist[ce.first.first] + ce.second)
			{
				dist[ce.first.second] = dist[ce.first.first] + ce.second;
				if (i == N - 1 && vis[ce.first.second][0] && vis[ce.first.second][1])
				{
					cout << "-1\n";
					return 0;
				}
			}
	}

	cout << -dist[N] << "\n";

	return 0;
}
