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

int segtree[4 * maxN];

void build(int v, int tl, int tr)
{
	if (tl == tr) segtree[v] = 1;
	else
	{
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r) return 0;
	if (l == tl && r == tr) return segtree[v];

	int tm = (tl + tr) / 2;
	return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void upd(int v, int tl, int tr, int pos, int nv)
{
	if (tl == tr) segtree[v] = nv;
	else
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			upd(v * 2, tl, tm, pos, nv);
		else upd(v * 2 + 1, tm + 1, tr, pos, nv);
		segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
	}
}

int N;
int a[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> a[i];
	build(1, 1, N);

	int k;
	for (int i = 0; i < N; i++)
	{
		cin >> k;

		int l = 1, r = N;
		while (l < r)
		{
			int mid = (l + r) / 2; 
			if (get(1, 1, N, 1, mid) >= k) // only 1-mid queries; could use fenwick
				r = mid;
			else l = mid + 1;
		}

		cout << a[l] << " ";
		upd(1, 1, N, l, 0);
	}

	return 0;
}
