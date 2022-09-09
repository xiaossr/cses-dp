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
ll a[maxN], st[4 * maxN], lz[4 * maxN], lz2[4 * maxN];

void push(int v, int tl, int tm, int tr)
{
	if (!lz[v]) return;
	st[v * 2] += (ll)(lz[v] + lz[v] + (tm - tl) * lz2[v]) * (tm - tl + 1) / 2;
	lz[v * 2] += lz[v];
	lz2[v * 2] += lz2[v];

	st[v * 2 + 1] += (lz[v] + (tm + 1 - tl) * lz2[v] + lz[v] + (tr - tl) * lz2[v]) * (tr - tm) / 2;
	lz[v * 2 + 1] += (ll)(lz[v] + (tm + 1 - tl) * lz2[v]);
	lz2[v * 2 + 1] += lz2[v];

	lz[v] = 0;
	lz2[v] = 0;
}

void build(int v, int tl, int tr)
{
	if (tl == tr) st[v] = a[tl];
	else
	{
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v] = st[v * 2] + st[v * 2 + 1];
	}
}

void upd(int v, int tl, int tr, int l, int r, int nv)
{
	if (l <= tl && tr <= r)
	{
		st[v] += (ll)(nv + (nv + tr - tl)) * (tr - tl + 1) / 2;
		lz[v] += nv;
		lz2[v]++;
		return;
	}

	int tm = (tl + tr) / 2;
	push(v, tl, tm, tr);
	if (l <= tm) upd(v * 2, tl, tm, l, r, nv);
	if (tm < r) upd(v * 2 + 1, tm + 1, tr, l, r, nv + max(0, (tm - max(tl, l) + 1)));

	st[v] = st[v * 2] + st[v * 2 + 1];
}

ll get(int v, int tl, int tr, int l, int r)
{
	if (l <= tl && tr <= r) return st[v];

	int tm = (tl + tr) / 2;
	push(v, tl, tm, tr);
	ll ret = 0;

	if (l <= tm) ret += get(v * 2, tl, tm, l, r);
	if (tm < r) ret += get(v * 2 + 1, tm + 1, tr, l, r);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> a[i];
	build(1, 1, N);

	int t, x, y;
	while (Q--)
	{
		cin >> t >> x >> y;
		if (t == 1) upd(1, 1, N, x, y, 1);
		else cout << get(1, 1, N, x, y) << "\n";
	}
	
	return 0;
}
