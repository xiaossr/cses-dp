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

struct SCC
{
	int N;
	vector< vector<int> > adj, radj;
	vector<int> todo, comp, comps; vector<bool> vis;
	void init(int _N) {
		N = _N;
		adj.resize(N + 3), radj.resize(N + 3), comp = vector<int>(N + 3, -1), vis.resize(N + 3);
	}
	void ae(int x, int y) {
		adj[x].push_back(y), radj[y].push_back(x);
	}
	void dfs(int x) {
		vis[x] = 1; for (int y : adj[x]) if (!vis[y]) dfs(y);
		todo.push_back(x);
	}
	void dfs2(int x, int v) {
		comp[x] = v;
		for (int y : radj[x]) if (comp[y] == -1) dfs2(y, v);
	}
	void gen() {
		for (int i = 0; i < N; i++) 
			if (!vis[i]) dfs(i);
		reverse(todo.begin(), todo.end());
		for (int x : todo) 
			if (comp[x] == -1)
				dfs2(x, x), comps.push_back(x);
	}
};

int id[maxn], at = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	int N, M, a, b;
	cin >> N >> M;

	SCC graph;
	graph.init(N);
	while (M--)
	{
		cin >> a >> b;
		graph.ae(a, b);
	}
	graph.gen();

	for (int i = 1; i <= N; i++)
		if (!id[graph.comp[i]])
			id[graph.comp[i]] = ++at;

	cout << at << "\n";
	for (int i = 1; i <= N; i++)
		cout << id[graph.comp[i]] << " ";
	cout << "\n";
	
	return 0;
}
