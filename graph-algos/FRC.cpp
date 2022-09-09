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

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;

int N, M;
bool g[2][maxn], vis[maxn];
vector<int> adj[2][maxn];

void dfs(int i)
{
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	vis[1] = 1;
	q.push(1);

	while (!q.empty())
	{
		int at = q.front();
		q.pop();

		for (const auto& k : adj[i][at])
			if (!vis[k])
				vis[k] = 1, g[i][k] = 1, q.push(k);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[0][a].push_back(b), adj[1][b].push_back(a);
	}

	dfs(0);
	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		if (!g[0][i])
		{
			cout << "NO\n" << "1 " << i << "\n";
			return 0;
		}
		if (!g[1][i])
		{
			cout << "NO\n" << i << " 1\n";
			return 0;
		}
	}
	cout << "YES\n";
	
	return 0;
}
