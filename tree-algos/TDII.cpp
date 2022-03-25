#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int N;
vector<int> adj[200005];
vector<long long> dsum, usum, dnum;
 
long long search(int at, int par) // calculate "downsum"
{
	//if (adj[at].size() == 1) return 0;
 
	for (const auto& k : adj[at])
	{
		if (k == par) continue;
		long long tmp = search(k, at);
		dnum[at] += tmp + 1;
		dsum[at] += tmp + 1 + dsum[k];
	}
 
	return dnum[at];
}
 
void findup(int at, int par) // calculate "upsum"
{
	if(par) usum[at] = usum[par] + dsum[par] - dsum[at] - (dnum[at] + 1) + N - 1 - dnum[at];
	for (const auto& k : adj[at])
	{
		// downsum of parent subtracted downsum of self, subtract parent-self edge
		// add parent upsum, add parent-self edge N - 1 - dnum[k] times
 
		if (k == par) continue;
		findup(k, at);
	}
}
 
int main()
{
	cin >> N;
 
	int a, b;
	dsum.assign(N + 3, 0), usum.assign(N + 3, 0), dnum.assign(N + 3, 0);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	search(1, 0);
	findup(1, 0);
 
	for (int i = 1; i <= N; i++)
		cout << dsum[i] + usum[i] << " ";
 
	return 0;
}
