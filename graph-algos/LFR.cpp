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
queue<int> q;
int par[100005], cnt[100005];

//void search()
//{
//	priority_queue<pii> pq;
//	pq.push({ 1, 1 });
//	dist[1] = 1;
//
//	while (!pq.empty())
//	{
//		int at = pq.top().second, d = pq.top().first;
//		pq.pop();
//		//cout << at << " ";
//
//		if (cnt[at] > N) {
//			dist[N] = 0;
//			return;
//		}if (d != dist[at]) continue;
//
//		cnt[at]++;
//		for (const auto& nx : adj[at])
//			if (!dist[nx] || d + 1 > dist[nx])
//				par[nx] = at, dist[nx] = d + 1, pq.push({ d + 1, nx });
//	}
//
//	return;
//}

void topo_sort()
{
	while (!q.empty())
	{
		int at = q.front();
		q.pop();

		for (const auto x : adj[at])
		{
			cnt[x]--;
			if (cnt[x] == 0)
				par[x] = at, q.push(x);
		}
	}
}

bool testok()
{
	if (par[N] != -1)
	{
		stack<int> s;
		int at = N;
		while (at != 1 && par[at])
			s.push(at), at = par[at];

		if (at != 1) return 0;
		s.push(1);

		cout << s.size() << "\n";
		while (!s.empty())
			cout << s.top() << " ", s.pop();
		cout << "\n";
		return 1;
	}

	return 0;
}

/*4 4
3 1
3 4
1 2
2 4*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream fin("test_input.in");
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		cnt[b]++;
	}

	for (int i = 2; i <= N; i++)
		if (cnt[i] == 0) q.push(i);

	topo_sort(); // starting point is not 1 passes through 1 along the way
	if (testok())
		return 0;

	// starting point is 1
	q.push(1);
	par[N] = -1;
	topo_sort();
	/*search(); */

	if(!testok())
		cout << "IMPOSSIBLE\n";
	
	return 0;
}
