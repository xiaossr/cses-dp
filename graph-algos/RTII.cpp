#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector<int> adj[100005];
bool vis[100005], ons[100005];
vector<int> cyc;

bool search(int st)
{
	vis[st] = ons[st] = 1;
	for (const int& nx : adj[st])
	{
		if (ons[nx])
		{
			cyc.push_back(st);
			ons[st] = ons[nx] = 0;
			return 1;
		}
		else if (!vis[nx])
		{
			if (search(nx))
			{
				if (ons[st]) // backtracking unfinished
				{
					cyc.push_back(st);
					ons[st] = 0;
					return 1;
				}
				else // backtrack finished
				{
					cyc.push_back(st);
					return 0;
				}
			}
			if (!cyc.empty())
				return 0;
		}
	}

	ons[st] = 0;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].pb(b);
	}

	for (int i = 1; i <= N; i++)
	{
		search(i);
		if (cyc.empty()) continue;

		reverse(cyc.begin(), cyc.end());
		cout << cyc.size() + 1 << "\n";
		for (const auto& k : cyc)
			cout << k << " ";
		cout << cyc.at(0) << "\n";
		return 0;
	}

	/*reverse(ans.begin(), ans.end());
	for (const auto& k : ans)
		cout << k << " ";
	cout << "\n";*/

	cout << "IMPOSSIBLE\n";
	
	return 0;
}
