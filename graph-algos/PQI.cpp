#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

const int MOD = 1e9 + 7;

int N, Q;
int par[200005][33];

int jump(int a, int d)
{
	for (int i = 0; i < 30; i++)
		if (d & (1 << i))
			a = par[a][i];
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> par[i][0];

	for (int d = 1; d < 30; d++)
		for (int i = 1; i <= N; i++)
			par[i][d] = par[par[i][d - 1]][d - 1];

	// do something
	// cycles.... cycles what


	int x, k;
	while (Q--)
	{
		cin >> x >> k;
		cout << jump(x, k) << "\n";
	}
	
	return 0;
}
