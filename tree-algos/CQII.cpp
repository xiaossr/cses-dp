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
#include <cassert>
#include <string>
#include <map>
#include <utility>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;

#define pb push_back
#define INF ((ll) 1e18 + 3)

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 5;	// check limits dweeb

int N, Q;
vi adj[maxN];
int up[maxN][22], depth[maxN];

int jmp(int at, int d)
{
	for (int i = 0; i < 22; i++)
		if ((d >> i) & 1)
			at = up[at][i];
	return at;
}

void dfs(int v)
{
	for (int i = 1; i < 22; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (int x : adj[v])
		if (x != up[v][0])
			depth[x] = depth[up[x][0] = v] + 1,
			dfs(x);
}

int lca(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);

	a = jmp(a, depth[a] - depth[b]);
	if (a == b) return a;

	for (int i = 21; i >= 0; i--)
		if (up[a][i] != up[b][i])
			a = up[a][i], b = up[b][i];

	return up[a][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	int a, b;
	for (int i = 1; i < N; i++)
	{
		cin >> a, --a;
		adj[a].push_back(i);
	}

	up[0][0] = 0, depth[0] = 0;
	dfs(0);

	while (Q--)
	{
		cin >> a >> b; --a, --b;
		cout << lca(a, b) + 1 << "\n";
	}

	return 0;
}
