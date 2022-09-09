#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector<int> adj[100005], prv;

pii search(int st)
{
	queue<int> q;
	q.push(st);
	prv[st] = st;

	while (!q.empty())
	{
		int k = q.front();
		q.pop();

		for (const auto& nx : adj[k])
		{
			if (prv[nx] && prv[nx] != k && prv[k] != nx)
				return { k, nx };
			else if (!prv[nx])
				prv[nx] = k, q.push(nx);
		}
	}

	return { -1, -1 };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;

	int a, b;
	prv.resize(N + 3, 0);
	for (int i = 0; i < M; i++)
		cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

	bool flg = 0;
	for (int i = 1; i <= N; i++)
	{
		if (prv[i]) continue;

		auto pk = search(i);
		int k = pk.first, k2 = pk.second;
		if (k != -1)
		{
			/*figure out how to output*/
			stack<int> s1, s2;

			int nk = k;
			while (nk != prv[nk])
				s1.push(nk), nk = prv[nk];
			nk = k2;
			while (nk != prv[nk])
				s2.push(nk), nk = prv[nk];

			while (!s1.empty() && !s2.empty() && s1.top() == s2.top())
				nk = s1.top(), s1.pop(), s2.pop();
			s1.push(nk);

			while (!s2.empty())
				s1.push(s2.top()), s2.pop();
			s1.push(k);

			if (s1.size() < 4) continue;
			cout << s1.size() << "\n";
			while (!s1.empty())
				cout << s1.top() << " ", s1.pop();
			flg = 1;
		}

		if (flg) break;
	}

	cout << (!flg ? "IMPOSSIBLE\n" : "\n");

	return 0;
}
