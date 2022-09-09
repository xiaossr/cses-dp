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

int N, Q;
int up[maxN][20];

int jmp(int at, int d)
{
	for (int i = 0; i < 18; i++)
		if ((d >> i) & 1)
			at = up[at][i];
	return at ? at : -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 2; i <= N; i++)
		cin >> up[i][0];
	
	for (int i = 1; i < 18; i++)
		for (int j = 1; j <= N; j++)
			up[j][i] = up[up[j][i - 1]][i - 1];

	int a, b;
	while (Q--)
	{
		cin >> a >> b;
		cout << jmp(a, b) << "\n";
	}

	return 0;
}
