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
#define INF ((ll) 2e14 + 3)

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 5;

struct val
{
	ll sum, pref, suff, ans;
};

val nval(ll v)
{
	val ret;
	ret.sum = v;
	ret.pref = ret.suff = ret.ans = max(0LL, v);
	return ret;
}

val st[4 * maxN];

val combine(val l, val r)
{
	val ret;
	ret.sum = l.sum + r.sum;
	ret.pref = max(l.pref, l.sum + r.pref);
	ret.suff = max(r.suff, r.sum + l.suff);
	ret.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	return ret;
}

int N, Q;

void build(ll a[], int v, int tl, int tr)
{
	if (tl == tr) st[v] = nval(a[tl]);
	else
	{
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		st[v] = combine(st[v * 2], st[v * 2 + 1]);
	}
}

void upd(int v, int tl, int tr, int pos, ll nv)
{
	if (tl == tr) st[v] = nval(nv);
	else
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm) upd(v * 2, tl, tm, pos, nv);
		else upd(v * 2 + 1, tm + 1, tr, pos, nv);
		st[v] = combine(st[v * 2], st[v * 2 + 1]);
	}
}

val get(int v, int tl, int tr, int l, int r)
{
	if (l > r) return nval(0);
	if (l == tl && r == tr) return st[v];

	int tm = (tl + tr) / 2;
	return combine(get(v * 2, tl, tm, l, min(r, tm)),
		get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll a[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> a[i];
	build(a, 1, 1, N);

	int x, y;
	while (Q--)
	{
		cin >> x >> y;
		upd(1, 1, N, x, y);
		cout << get(1, 1, N, 1, N).ans << "\n";
	}
	
	return 0;
}
