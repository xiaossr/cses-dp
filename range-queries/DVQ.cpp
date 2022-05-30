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

int N, Q;
int bit[maxN];

void ins(int ind, int val)
{
	for (; ind <= N; ind += (ind & -ind))
		bit[ind] += val;
	return;
}

int get(int ind)
{
	int ret = 0;
	while (ind)
		ret += bit[ind], ind -= (ind & -ind);
	return ret;
}

int sol[maxN];
vector<pii> query[maxN];
vi x(maxN);
map<int, int> fst;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");
  /*key is to process backwards after sorting queries*/

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> x[i];
	
	int a, b;
	for (int i = 0; i < Q; i++)
		cin >> a >> b, query[a].push_back({ b, i });

	for (int i = N; i >= 1; i--)
	{
		int z = x[i];
		if (fst.count(z)) ins(fst[z], -1);
		fst[z] = i;
		ins(i, 1);

		for (auto t : query[i])
			sol[t.second] = get(t.first);
	}

	for (int i = 0; i < Q; i++)
		cout << sol[i] << "\n";

	return 0;
}
