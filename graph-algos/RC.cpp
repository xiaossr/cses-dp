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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;

int N, M;
int num, maxc = 1;
int par[maxn], sz[maxn];

int f(int a)
{
	if (par[a] == a)
		return a;
	return par[a] = f(par[a]);
}

void merge(int a, int b)
{
	if (f(a) == f(b))
		return;
	a = f(a), b = f(b);
	num--;
	par[b] = a, sz[a] += sz[b];
	maxc = max(maxc, sz[a]);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> M;

	num = N;
	for (int i = 1; i <= N; i++)
		par[i] = i, sz[i] = 1;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		merge(a, b);
		cout << num << " " << maxc << "\n";
	}
	
	return 0;
}
