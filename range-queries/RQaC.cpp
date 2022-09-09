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

int cur = 1, N, Q;
vector<int> ver;
struct node 
{
	int left, right; ll sum;
} seg[maxN * 40];

void update(int& root, int idx, ll val, int l = 0, int h = N - 1) 
{
	seg[cur].left = seg[root].left;
	seg[cur].right = seg[root].right;
	seg[cur].sum = seg[root].sum + val;
	root = cur; cur++;
	int mid = (l + h) / 2;
	if (l == h)
		return;
	if (idx <= mid)
		update(seg[root].left, idx, val, l, mid);
	else
		update(seg[root].right, idx, val, mid + 1, h);
}

ll query(int root, int a, int b, int l = 0, int h = N - 1) 
{
	if (a <= l && h <= b)
		return seg[root].sum;
	int mid = (l + h) / 2;
	return (a <= mid ? query(seg[root].left, a, b, l, mid) : 0) +
		(mid < b ? query(seg[root].right, a, b, mid + 1, h) : 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	ver.push_back(0);
	for (int i = 0; i < N; i++) 
	{
		int x; cin >> x;
		update(ver[0], i, x);
	}

	while (Q--) 
	{
		int ch; cin >> ch;
		if (ch == 1) 
		{
			int k, a; ll x; cin >> k >> a >> x;
			k--, a--;
			update(ver[k], a, x - query(ver[k], a, a));
		}
		else if (ch == 2) 
		{
			int k, a, b; cin >> k >> a >> b;
			k--, a--, b--;
			cout << query(ver[k], a, b) << endl;
		}
		else 
		{
			int k; cin >> k;
			ver.push_back(ver[k - 1]);
		}
	}
	
	return 0;
}
