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
#define INF ((ll) 2e14)

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 5;

int N, Q;
ll lazy[4 * maxN], st[4 * maxN];

void push(int v)
{
	st[v * 2] += lazy[v];
	lazy[v * 2] += lazy[v];
	st[v * 2 + 1] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

void build(ll a[], int v, int tl, int tr)
{
	if (tl == tr) st[v] = a[tl];
	else
	{
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		st[v] = max(st[v * 2], st[v * 2 + 1]);
	}
}

void upd(int v, int tl, int tr, int l, int r, ll addend)
{
	if (l > r) return;
	if (l <= tl && tr >= r)
		st[v] += addend, lazy[v] += addend;
	else
	{
		push(v);
		int tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, l, min(r, tm), addend);
		upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
		st[v] = max(st[v * 2], st[v * 2 + 1]);
	}
}

ll query(int v, int tl, int tr, int l, int r)
{
	if (l > r) return -INF;
	if (l <= tl && tr <= r)
		return st[v];

	push(v);
	int tm = (tl + tr) / 2;
	return max(query(v * 2, tl, tm, l, min(r, tm)), 
		query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll a[maxN], psum[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> a[i], psum[i] = a[i] + psum[i - 1];
	build(psum, 1, 0, N);

	int t, x; ll y;
	while (Q--)
	{
		cin >> t >> x >> y;
		if (t == 1)
			upd(1, 0, N, x, N, y - a[x]), a[x] = y;
		else
			cout << query(1, 0, N, x - 1, y) - query(1, 0, N, x - 1, x - 1) << "\n";
	}
	
	return 0;
}
