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
typedef vector<int> vi;

#define pb push_back

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 5;

int N, Q;
ll psum[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> psum[i], psum[i] += psum[i - 1];

	int a, b;
	for (int i = 0; i < Q; i++)
	{
		cin >> a >> b;
		cout << psum[b] - psum[a - 1] << "\n";
	}
	
	return 0;
}
