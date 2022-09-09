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

int N, Q;
vector<int> nxt(200005);
set<int> par[200005];

vector<int> kai_cyc(200005, -1), kyo_node(200005, -1);

vector<bool> v1(200005, 0), v2(200005, 0);
vector< vector<int> > cycle;
vector<int> tmp;

int cycid = 0, nn = 0, st = -1;

vector<int> tin(200005), tout(200005);
int tem = 0;
vector<int> latkav;

void dfs(int at)
{
	v1[at] = 1;
	int c = nxt[at];

	if (v1[c] && !v2[c])
	{
		par[c].erase(at);
		latkav.push_back(at);
		st = c;
	}

	if (!v1[c]) dfs(c);

	if (st != -1)
	{
		tmp.push_back(at);
		kai_cyc[at] = cycid;
		kyo_node[at] = nn++;

		if (at == st)
		{
			cycle.push_back(tmp);
			st = -1;
			tmp.clear();
			nn = 0;
			cycid++;
		}
	}

	v2[at] = 1;
}

vector< vector<int> > up;
int mxh;

void dfs1(int at, int p)
{
	tin[at] = tem++;

	up[at][0] = p;
	for (int i = 1; i <= mxh; i++)
		if (up[at][i - 1] != -1)
			up[at][i] = up[up[at][i - 1]][i - 1];

	for (int c : par[at]) dfs1(c, at);
	tout[at] = tem++;
}

bool isanc(int u, int v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
	{
		cin >> nxt[i];
		par[nxt[i]].insert(i);
	}

	for (int i = 1; i <= N; i++)
		if (!v1[i])
			dfs(i);

	mxh = ceil(log2(N));
	up.assign(N + 1, vector<int>(mxh + 1, -1));

	for (int x : latkav) dfs1(x, -1);

	while (Q--)
	{
		int sta, en;
		cin >> sta >> en;

		if (sta == en)
		{
			cout << "0\n";
			continue;
		}

		if (kai_cyc[sta] != -1)
		{
			if (kai_cyc[sta] == kai_cyc[en])
			{
				int s = kyo_node[sta];
				int e = kyo_node[en];
				int sz = cycle[kai_cyc[st]].size();
				cout << (s - e + sz) % sz << "\n";
			}
			else cout << "-1\n";
			continue;
		}

		if (isanc(en, sta))
		{
			int jump = 0;
			for (int i = mxh; i >= 0; i--)
				if (up[sta][i] != -1 && !isanc(up[sta][i], en))
					sta = up[sta][i], jump += 1 << i;
			cout << jump + 1 << "\n";
		}
		else
		{
			int jump = 0;
			for (int i = mxh; i >= 0; i--)
				if (up[sta][i] != -1)
					sta = up[sta][i], jump += 1 << i;
			if (kai_cyc[sta] == kai_cyc[en])
			{
				int s = kyo_node[sta];
				int e = kyo_node[en];
				int sz = cycle[kai_cyc[st]].size();
				cout << (s - e + sz) % sz + jump << "\n";
			}
			else cout << "-1\n";
		}
	}
	
	return 0;
}
