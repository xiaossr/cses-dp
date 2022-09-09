#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector<int> adj[100005];
int prv[100005];

int search()
{
	queue<pii> q;
	prv[1] = 1;
	q.push({ 1, 1 });

	while (!q.empty())
	{
		int k = q.front().first, d = q.front().second;
		q.pop();
		if (k == N) return d;

		for (const auto& nx : adj[k])
			if (!prv[nx])
				prv[nx] = k, q.push({ nx, d + 1 });
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
		cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

	int k = search();

	if (k == -1)
		cout << "IMPOSSIBLE\n";
	else
	{
		cout << k << "\n";
		
		stack<int> s;
		int at = N;
		while (at != 1)
			s.push(at), at = prv[at];
		s.push(1);

		while (!s.empty())
			cout << s.top() << " ", s.pop();
		cout << "\n";
	}

	return 0;
}
