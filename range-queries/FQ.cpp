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
const int maxN = 1e3 + 3;

int N, Q;
int a[maxN][maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	char c;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> c;
			a[i][j] = (c == '*');
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}

	int x1, y1, x2, y2;
	while (Q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--;
		cout << a[x2][y2] - a[x1][y2] - a[x2][y1] + a[x1][y1] << "\n";
	}

	return 0;
}
