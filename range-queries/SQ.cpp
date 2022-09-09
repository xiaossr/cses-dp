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

int N, Q, nN;
char t[maxN];
int a[maxN], bit[4 * maxN], X[maxN], Y[maxN];
vi mp;

void upd(int at, int x)
{
	at = lower_bound(mp.begin(), mp.end(), at) - mp.begin() + 1;
	for(; at <= nN; at += (at & (-at)))
		bit[at] += x;
}

int get(int at)
{
	at = lower_bound(mp.begin(), mp.end(), at) - mp.begin() + 1;
	int ret = 0;
	while (at)
		ret += bit[at], at -= (at & -at);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> a[i], mp.push_back(a[i]); // mp for compression
	for (int i = 1; i <= Q; i++)
	{
		cin >> t[i] >> X[i] >> Y[i];
		mp.push_back(X[i]);
		mp.push_back(Y[i]);
		mp.push_back(X[i] - 1);
	}
	sort(mp.begin(), mp.end());
	nN = mp.size();

	for (int i = 1; i <= N; i++)
		upd(a[i], 1);
	for (int i = 1; i <= Q; i++)
	{
		if (t[i] == '!')
		{
			upd(a[X[i]], -1);
			a[X[i]] = Y[i];
			upd(Y[i], 1);
		}
		else
			cout << get(Y[i]) - get(X[i] - 1) << "\n";
	}

	return 0;
}
