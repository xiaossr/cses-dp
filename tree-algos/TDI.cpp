#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int N;
vector<int> adj[200005];
vector<int> vis, ans;
 
int bfs(int st)
{
	vis.assign(N + 3, -1);
	queue<int> q;
	q.push(st), vis[st] = 0;
 
	int ret = 0;
	while (!q.empty())
	{
		int k = q.front();
		ans[k] = max(ans[k], vis[k]);
		ret = k;
		q.pop();
 
		for (const auto& nx : adj[k])
			if(vis[nx] == -1)
				q.push(nx), vis[nx] = vis[k] + 1;
	}
 
	return ret;
}
 
int main()
{
	cin >> N;
 
	int a, b;
	ans.assign(N + 3, 0);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	a = bfs(1);
	b = bfs(a);
	bfs(b);
 
	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	cout << "\n";
 
	return 0;
}
