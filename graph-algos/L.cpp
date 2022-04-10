#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define f first
#define s second

int N, M;
char grid[1005][1005];
pair<int, pii> vis[1005][1005]; // first is length second is direction

int dirx[] = { 0, 1, 0, -1 };
int diry[] = { 1, 0, -1, 0 };
char cd[] = { 'R', 'D', 'L', 'U' };

bool search(pii st)
{
	queue<pii> q;
	q.push(st);
	vis[st.first][st.second] = { 1, {-1, -1} };

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (grid[x][y] == 'B') return 1;

		//cout << x << " " << y << " " << vis[x][y].first << " " << vis[x][y].second.first << " " << vis[x][y].s.s << "\n";

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dirx[i], ny = y + diry[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M
				&& grid[nx][ny] != '#' && vis[nx][ny].first == 0)
				vis[nx][ny].first = vis[x][y].first + 1,
				vis[nx][ny].second = { x, y },
				q.push({ nx, ny });
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	pii st, en;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'A') st = { i, j };
			else if (grid[i][j] == 'B') en = { i, j };
		}

	cerr << "no overflow yet\n";
	if (!search(st))
		cout << "NO\n";
	else
	{
		cout << "YES\n"
			<< vis[en.first][en.second].first - 1 << "\n";

		stack<char> ord;
		int cx = en.first, cy = en.second;

		// string concentation overflow - use backtrack
		while (make_pair(cx, cy) != st)
		{
			int tx = vis[cx][cy].second.first, ty = vis[cx][cy].second.second;
			for (int i = 0; i < 4; i++)
				if (tx + dirx[i] == cx
					&& ty + diry[i] == cy)
					ord.push(cd[i]);
			cx = tx, cy = ty;
		}

		while (!ord.empty())
			cout << ord.top(), ord.pop();
	}

	return 0;
}
