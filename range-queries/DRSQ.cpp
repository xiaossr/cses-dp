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
typedef pair<ll, int> pli;
typedef vector<int> vi;

#define pb push_back
#define INF ((int) 2e9)

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 5;

int N, Q;
pli segtree[4 * maxN];

pli combine(pli a, pli b)
{
	return { a.first + b.first, a.second + b.second };
}

void build(int a[], int v, int tl, int tr)
{
	if (tl == tr) segtree[v] = { a[tl], 1 };
	else
	{
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		segtree[v] = combine(segtree[v * 2], segtree[v * 2 + 1]);
	}
}

pli get_sum(int v, int tl, int tr, int l, int r)
{
	if (l > r) return { 0, 0 };
	if (l == tl && r == tr) return segtree[v];
	int tm = (tl + tr) / 2;

	return combine(get_sum(v * 2, tl, tm, l, min(r, tm)),
		get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void upd(int v, int tl, int tr, int pos, int nv)
{
	if (tl == tr) segtree[v] = { nv, 1 };
	else
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			upd(v * 2, tl, tm, pos, nv);
		else upd(v * 2 + 1, tm + 1, tr, pos, nv);
		segtree[v] = combine(segtree[v * 2], segtree[v * 2 + 1]);
	}
}

int a[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> a[i];

	build(a, 1, 1, N);
	
	int t, x, y;
	while (Q--)
	{
		cin >> t >> x >> y;

		if (t == 2)
		{
			auto k = get_sum(1, 1, N, x, y);
			cout << k.first << "\n";
		}
		else
			upd(1, 1, N, x, y);
	}

	return 0;
}
