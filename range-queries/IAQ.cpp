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
const int maxN = 2e5 + 5;

int N, Q;
ll x[maxN], psum[maxN], ans[maxN];
ll cont[maxN], bit[maxN];
vector<pii> buc[maxN];

void ins(int ind, ll val)
{
	for (; ind <= N; ind += ind & -ind)
		bit[ind] += val;
}

ll get(int ind)
{
	ll ret = 0;
	while (ind)
		ret += bit[ind], ind -= ind & -ind;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> x[i], psum[i] = psum[i - 1] + x[i];
	x[N + 1] = INF;
	psum[N + 1] = psum[N] + x[N + 1];

	int a, b;
	for (int i = 1; i <= Q; i++)
		cin >> a >> b, buc[a].push_back({ b, i });

	deque<int> stck = { N + 1 };
	for (int i = N; i > 0; i--)
	{
		while (stck.size() && x[i] >= x[stck.front()])
			ins(stck.front(), -cont[stck.front()]), 
			stck.pop_front();
		cont[i] = ((ll) stck.front() - 1 - i) * x[i] - (psum[stck.front() - 1] - psum[i]);
		ins(i, cont[i]);
		stck.push_front(i);

		for (pii j : buc[i])
		{
			int pos = upper_bound(stck.begin(), stck.end(), j.first) - stck.begin() - 1;
			ans[j.second] = (pos ? get(stck[pos - 1]) - get(i - 1) : 0) +
				((ll) j.first - stck[pos]) * x[stck[pos]] - (psum[j.first] - psum[stck[pos]]);
		}
	}

	for (int i = 1; i <= Q; i++)
		cout << ans[i] << "\n";

	return 0;
}
