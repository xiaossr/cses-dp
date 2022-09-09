#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector< pair<pii, ll> > adj;
int par[100005]; ll dist[100005];

int bf()
{
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int v1 = adj[j].first.first, v2 = adj[j].first.second;
			ll d = adj[j].second;

			if (dist[v2] > dist[v1] + d)
			{
				if (i == N - 1)
				{
					return v2; // return if can still be relaxed
				}
				par[v2] = v1;
				dist[v2] = dist[v1] + d;
			}
		}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//ifstream fin("test_input.in");

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		par[i] = i;

	int a, b; ll c;
	for (int i = 0; i < M; i++)
		cin >> a >> b >> c, adj.push_back({ {a, b}, c });

	//dist[1] = 0;
	int k = bf();

	if (k == -1) cout << "NO\n";
	else
	{
		cout << "YES\n";
		stack<int> s;
		int at;
		
		for (int i = 0; i < N; i++)
			k = par[k]; // guarentees go into cycle

		cout << k << " ";
		at = par[k];
		while (at != k)
			s.push(at), at = par[at]; // lifo finds cycle

		while (!s.empty())
			cout << s.top() << " ", s.pop();
		cout << at << "\n";
	}
	
	return 0;
}
