#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> adj[200005];
int dp1[200005], dp2[200005];

// could greedy it
// dp1[v]: take v
// dp2[v]: no take v

void search(int at, int par)
{
	for (const auto& k : adj[at])
	{
		if (k == par) continue;
		search(k, at);

		dp2[at] += max(dp1[k], dp2[k]);
	}

	for (const auto& k : adj[at])
		if(k != par)
			dp1[at] = max(dp1[at], dp2[k] + 1 + dp2[at] - max(dp1[k], dp2[k])); // subtract from dp2 bc double count

	return;
}

int main()
{
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++)
		cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	search(1, 0);
	cout << max(dp1[1], dp2[1]) << "\n";

	return 0;
}
