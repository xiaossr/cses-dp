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

struct node
{
	ll val, lzadd, lzset;
}st[4 * maxN];

int N, Q;
ll a[maxN];

void push(int v, int tl, int tm, int tr)
{
	if (tl == tr) return;

	if (st[v].lzset != 0) // give strict order
	{
		st[v * 2].lzset = st[v * 2 + 1].lzset = st[v].lzset;
		st[v * 2].val = (tm - tl + 1) * st[v].lzset;
		st[v * 2 + 1].val = (tr - tm) * st[v].lzset;

		st[v * 2].lzadd = st[v * 2 + 1].lzadd = 0;
		st[v].lzset = 0;
	}
	else if (st[v].lzadd != 0)
	{
		if (st[v * 2].lzset == 0) st[v * 2].lzadd += st[v].lzadd;
		else st[v * 2].lzset += st[v].lzadd, st[v * 2].lzadd = 0;

		if (st[v * 2 + 1].lzset == 0) st[v * 2 + 1].lzadd += st[v].lzadd;
		else st[v * 2 + 1].lzset += st[v].lzadd, st[v * 2 + 1].lzadd = 0;

		st[v * 2].val += (tm - tl + 1) * st[v].lzadd;
		st[v * 2 + 1].val += (tr - tm) * st[v].lzadd;
		st[v].lzadd = 0;
	}

	return;
}

void build(int v, int tl, int tr)
{
	st[v].lzadd = st[v].lzset = 0;
	if (tl == tr)
		st[v].val = a[tl];
	else
	{
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v].val = st[v * 2].val + st[v * 2 + 1].val;
	}

	return;
}

void add(int v, int tl, int tr, int l, int r, ll nv)
{
	if (l > r) return;
	if (l <= tl && tr <= r)
	{
		st[v].val += (tr - tl + 1) * nv;
		if (st[v].lzset == 0) st[v].lzadd += nv;
		else st[v].lzset += nv;
		return;
	}

	int tm = (tl + tr) / 2;
	push(v, tl, tm, tr);
	add(v * 2, tl, tm, l, min(r, tm), nv);
	add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, nv);
	st[v].val = st[v * 2].val + st[v * 2 + 1].val;
}

void ass(int v, int tl, int tr, int l, int r, ll nv)
{
	if (l > r) return;
	if (l <= tl && tr <= r)
	{
		st[v].val = (r - l + 1) * nv;
		st[v].lzadd = 0;
		st[v].lzset = nv;
		return;
	}

	int tm = (tl + tr) / 2;
	push(v, tl, tm, tr);
	ass(v * 2, tl, tm, l, min(tm, r), nv);
	ass(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, nv);
	st[v].val = st[v * 2].val + st[v * 2 + 1].val;
}

ll get(int v, int tl, int tr, int l, int r)
{
	if (l > r) return 0;
	if (l <= tl && tr <= r) return st[v].val;

	int tm = (tl + tr) / 2;
	push(v, tl, tm, tr);
	return get(v * 2, tl, tm, l, min(tm, r)) +
		get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
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

	int t, x, y; ll z;
	while (Q--)
	{
		cin >> t;
		if (t == 1)
		{
			cin >> x >> y >> z;
			add(1, 1, N, x, y, z);
		}
		else if (t == 2)
		{
			cin >> x >> y >> z;
			ass(1, 1, N, x, y, z);
		}
		else
		{
			cin >> x >> y;
			cout << get(1, 1, N, x, y) << "\n";
		}
	}
	
	return 0;
}
