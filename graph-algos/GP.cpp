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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 5;

bool vis[maxN];
char ans[maxN];
int N, M, K, in[maxN], rt[maxN];
vector<int> ord, comp, G[maxN], GR[maxN], C[maxN], SCC[maxN];

int flip(int x) {
	return (x & 1 ? x + 1 : x - 1);
}

void add_edge(char c1, int a, char c2, int b) {
	a = 2 * a - (c1 == '-');
	b = 2 * b - (c2 == '-');
	G[flip(a)].push_back(b);
	G[flip(b)].push_back(a);
	GR[a].push_back(flip(b));
	GR[b].push_back(flip(a));
}

void dfs1(int u) {
	vis[u] = true;
	for (int v : G[u])
		if (!vis[v])
			dfs1(v);
	ord.push_back(u);
}

void dfs2(int u) {
	vis[u] = true;
	comp.push_back(u);
	for (int v : GR[u])
		if (!vis[v])
			dfs2(v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

    cin >> M >> N;

    for (int i = 0, a, b; i < M; i++) {
        char c1, c2;
        cin >> c1 >> a >> c2 >> b;
        add_edge(c1, a, c2, b);
    }

    for (int i = 1; i <= 2 * N; i++)
        if (!vis[i])
            dfs1(i);

    fill(vis + 1, vis + 2 * N + 1, false);
    reverse(ord.begin(), ord.end());
    for (int u : ord) {
        if (!vis[u]) {
            dfs2(u);
            K++;
            for (int v : comp) {
                rt[v] = K;
                C[K].push_back(v);
            }
            comp.clear();
        }
    }

    // Impossible iff x and not(x) belong to same SCC
    for (int i = 1; i <= N; i++) {
        if (rt[2 * i] == rt[2 * i - 1]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int u = 1; u <= 2 * N; u++) {
        for (int v : G[u]) {
            if (rt[u] != rt[v]) {
                SCC[rt[u]].push_back(rt[v]);
                in[rt[v]]++;
            }
        }
    }

    queue<int> Q;
    ord.clear();
    for (int u = 1; u <= K; u++) {
        if (in[u] == 0) {
            ord.push_back(u);
            Q.push(u);
        }
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : SCC[u]) {
            in[v]--;
            if (in[v] == 0) {
                ord.push_back(v);
                Q.push(v);
            }
        }
    }

    fill(vis + 1, vis + N + 1, false);
    reverse(ord.begin(), ord.end());
    for (int k : ord) {
        for (int u : C[k]) {
            int i = (u + 1) / 2;
            if (!vis[i]) {
                ans[i] = (u & 1 ? '-' : '+');
                vis[i] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << endl;
	
	return 0;
}
