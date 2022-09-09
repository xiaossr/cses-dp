#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
vector< vector<int> > fs;
vector<int> ans;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int a, b;
	fs.resize(N + 3), ans.resize(N + 3, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		fs[a].pb(b), fs[b].pb(a);
	}

	bool flg = 1;
	for (int i = 1; i <= N && flg; i++)
	{
		if (ans[i]) continue;
		ans[i] = 1;
		q.push(i);

		while (!q.empty())
		{
			int k = q.front();
			q.pop();

			int team = (ans[k] == 1 ? 2 : 1);
			for (auto& nx : fs[k])
			{
				if (ans[nx] == ans[k]) flg = 0;
				if (!ans[nx]) ans[nx] = team, q.push(nx);
			}

			if (!flg) break;
		}
	}

	if (!flg) cout << "IMPOSSIBLE";
	else for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}
