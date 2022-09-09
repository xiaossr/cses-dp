#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

int N, M;
char grid[1001][1001];
int vis[1003][1003];
char pth[1003][1003];
pii st;
vector<pii> monsters;

int dirx[] = { 1, 0, -1, 0 };
int diry[] = { 0, 1, 0, -1 };
char cd[] = { 'D', 'R', 'U', 'L' };

void searchmon()
{
	queue<pii> q;
	for (int i = 0; i < monsters.size(); i++)
		q.push(monsters[i]);

	while (!q.empty())
	{
		auto k = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = k.first + dirx[i], ny = k.second + diry[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && grid[nx][ny] != '#' && !vis[nx][ny])
				vis[nx][ny] = vis[k.first][k.second] + 1, q.push({ nx, ny });
		}
	}

	return;
}

pair<pii, int> searcha()
{
	queue< pair<pii, int> > q;
	q.push({ st, 1 });

	while (!q.empty())
	{
		auto k = q.front().first;
		auto d = q.front().second;
		q.pop();
		
		if (k.first == 0 || k.first == N - 1 || k.second == 0 || k.second == M - 1)
			return { k, d };

		for (int i = 0; i < 4; i++)
		{
			int nx = k.first + dirx[i], ny = k.second + diry[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && grid[nx][ny] != '#' && (d + 1 < vis[nx][ny] || vis[nx][ny] == 0) && pth[nx][ny] == '\0')
				pth[nx][ny] = cd[i], q.push({ {nx, ny}, d + 1 });
		}
	}

	return { { -1, -1 }, -1 };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'M') monsters.push_back({ i, j }), vis[i][j] = 1;
			else if (grid[i][j] == 'A') st = { i, j };
		}

	searchmon();
	auto en = searcha();

	if (en.second == -1)
		cout << "NO\n";
	else
	{
		cout << "YES\n" << en.second - 1 << "\n";
		
		stack<char> s;
		int x = en.first.first, y = en.first.second;
		while (make_pair(x, y) != st)
		{
			s.push(pth[x][y]);
			for (int i = 0; i < 4; i++)
				if (cd[i] == pth[x][y])
				{
					x -= dirx[i], y -= diry[i];
					break;
				}
		}

		while (!s.empty())
			cout << s.top(), s.pop();
		cout << "\n";
	}

	return 0;
}
