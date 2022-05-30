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
int st[4 * maxN][2]; // 0 to left, 1 to right

void build(int a[], int v, int tl, int tr)
{
	if (tl == tr) st[v][0] = a[tl] - tl, st[v][1] = a[tl] + tl;
	else
	{
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		st[v][0] = min(st[v * 2][0], st[v * 2 + 1][0]),
			st[v][1] = min(st[v * 2][1], st[v * 2 + 1][1]);
	}
}

void upd(int v, int tl, int tr, int pos, int nv)
{
	if (tl == tr) st[v][0] = nv - tl, st[v][1] = nv + tl;
	else
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm) upd(v * 2, tl, tm, pos, nv);
		else upd(v * 2 + 1, tm + 1, tr, pos, nv);
		st[v][0] = min(st[v * 2][0], st[v * 2 + 1][0]),
			st[v][1] = min(st[v * 2][1], st[v * 2 + 1][1]);
	}
}

int get(int v, int tl, int tr, int l, int r, int d)
{
	if (l > r) return INF;
	if (l == tl && r == tr) return st[v][d];

	int tm = (tl + tr) / 2;
	return min(get(v * 2, tl, tm, l, min(r, tm), d),
		get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, d));
}

int pizza[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> pizza[i];
	build(pizza, 1, 1, N);

	int t, a, b;
	while (Q--)
	{
		cin >> t;
		if (t == 1)
		{
			cin >> a >> b;
			upd(1, 1, N, a, b);
		}
		else
		{
			cin >> a;
			int l = get(1, 1, N, 1, a, 0) + a, 
				r = get(1, 1, N, a + 1, N, 1) - a;
			cout << min(l, r) << "\n";
		}
	}
	
	return 0;
}
