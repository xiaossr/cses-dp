#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, M, at = 0, ans;
int par[100005], gp[100005];
vector< vector<int> > cluster;

int f(int a)
{
	if (par[a] == a) return a;
	return par[a] = f(par[a]);
}

pii merge(int a, int b)
{
	a = f(a), b = f(b);
	if (a == b) return { -1, -1 };
	if (cluster[a].size() < cluster[b].size()) swap(a, b);

	par[b] = a;
	cluster[a].insert(cluster[a].end(), cluster[b].begin(), cluster[b].end());
	for (auto& k : cluster[b])
		gp[k] = gp[a];

	ans--;
	return {cluster[a][0], cluster[b][0]};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	ans = N;
	cluster.resize(N + 3);
	for (int i = 1; i <= N; i++)
		par[i] = i, cluster[i].push_back(i), gp[i] = i;

	int a, b;
	int root;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		merge(a, b);
		root = a;
	}

	cout << ans - 1 << "\n";
	for (int i = 1; i <= N; i++)
	{
		pii k = merge(i, root);
		if (k.first != -1)
			cout << k.first << " " << k.second << "\n";
	}

	return 0;
}
