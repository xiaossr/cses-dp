#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M, Q;
ll adj[505][505];

void fw()
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M >> Q;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			adj[i][j] = 1e14, adj[i][i] = 0;

	int a, b; ll c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c), adj[b][a] = min(adj[b][a], c);
	}

	fw();

	for (int i = 0; i < Q; i++)
		cin >> a >> b, cout << (adj[a][b] == 1e14 ? -1 : adj[a][b]) << "\n";

	return 0;
}
