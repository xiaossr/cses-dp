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
const int maxn = 2e5 + 5;

int N;
int nx[maxn], len[maxn];
bool vis[maxn] = { 0 };
queue<int> path;
int steps = 0;

void dfs(int at)
{
	path.push(at);
	if (vis[at])
	{
		steps += len[at];
		return;
	}
	vis[at] = 1;
	steps++;
	dfs(nx[at]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> nx[i];

	for (int i = 1; i <= N; i++)
	{
		if (!vis[i])
		{
			steps = 0;
			dfs(i);

			bool dec = 1;
			while (!path.empty()) 
			{
				if (path.front() == path.back())
					dec = 0;
				len[path.front()] = steps;
				steps -= dec;
				path.pop();
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << len[i] << " ";
	cout << "\n";
	
	return 0;
}
