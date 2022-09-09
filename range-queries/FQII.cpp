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
const int maxN = 1e3 + 3;

int N, Q;
int st[4 * maxN][4 * maxN], a[maxN][maxN];

void buildy(int vx, int lx, int rx, int vy, int ly, int ry)
{
	if (ly == ry)
	{
		if (lx == rx) st[vx][vy] = a[lx][ly];
		else st[vx][vy] = st[vx * 2][vy] + st[vx * 2 + 1][vy];
	}
	else
	{
		int my = (ly + ry) / 2;
		buildy(vx, lx, rx, vy * 2, ly, my);
		buildy(vx, lx, rx, vy * 2 + 1, my + 1, ry);
		st[vx][vy] = st[vx][vy * 2] + st[vx][vy * 2 + 1];
	}
}

void buildx(int vx, int lx, int rx)
{
	if (lx != rx)
	{
		int mx = (lx + rx) / 2;
		buildx(vx * 2, lx, mx);
		buildx(vx * 2 + 1, mx + 1, rx);
	}
	buildy(vx, lx, rx, 1, 1, N);
}

int sumy(int vx, int vy, int tly, int try_, int ly, int ry)
{
	if (ly > ry) return 0;
	if (ly == tly && try_ == ry)
		return st[vx][vy];
	int tmy = (tly + try_) / 2;
	return sumy(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
		+ sumy(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
}

int sumx(int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
	if (lx > rx) return 0;
	if (lx == tlx && trx == rx)
		return sumy(vx, 1, 1, N, ly, ry);
	int tmx = (tlx + trx) / 2;
	return sumx(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
		+ sumx(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
}

void updy(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int nv)
{
	if (ly == ry)
	{
		if (lx == rx) st[vx][vy] = nv;
		else st[vx][vy] = st[vx * 2][vy] + st[vx * 2 + 1][vy];
	}
	else
	{
		int my = (ly + ry) / 2;
		if (y <= my)
			updy(vx, lx, rx, vy * 2, ly, my, x, y, nv);
		else updy(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, nv);
		st[vx][vy] = st[vx][vy * 2] + st[vx][vy * 2 + 1];
	}
}

void updx(int vx, int lx, int rx, int x, int y, int nv)
{
	if (lx != rx)
	{
		int mx = (lx + rx) / 2;
		if (x <= mx)
			updx(vx * 2, lx, mx, x, y, nv);
		else updx(vx * 2 + 1, mx + 1, rx, x, y, nv);
	}

	updy(vx, lx, rx, 1, 1, N, x, y, nv);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	char c;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> c, a[i][j] = (c == '*');
	buildx(1, 1, N);

	int t, x1, x2, y1, y2;
	while (Q--)
	{
		cin >> t;
		if (t == 1)
		{
			cin >> x1 >> y1;
			updx(1, 1, N, x1, y1, !a[x1][y1]);
			a[x1][y1] = !a[x1][y1];
		}
		else 
		{
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sumx(1, 1, N, x1, x2, y1, y2) << "\n";
		}
	}
	
	return 0;
}
