#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector<int> adj[100005];
bool vis[100005];
int npar[100005];
vector<int> ans;
queue<int> q;

bool topo_sort()
{
	while (!q.empty())
	{
		int k = q.front();
		q.pop();

		for (const auto& nx : adj[k])
		{
			npar[nx]--;
			if (npar[nx] == 0)
				ans.push_back(nx), q.push(nx);
		}
	}

	return ans.size() == N;
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
		adj[a].pb(b);
		npar[b]++;
	}

	for (int i = 1; i <= N; i++)
		if (npar[i] == 0)
			ans.push_back(i), q.push(i);
	
	if (topo_sort())
	{
		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	else cout << "IMPOSSIBLE\n";
	
	return 0;
}
