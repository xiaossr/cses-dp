#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int N, M;
char grid[1003][1003];
bool vis[1003][1003];

int dirx[] = { 1, 0, -1, 0 };
int diry[] = { 0, 1, 0, -1 };

void search(int x, int y)
{
	queue< pair<int, int> > q;
	q.push({ x, y });
	vis[x][y] = 1;

	while (!q.empty())
	{
		x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dirx[i], ny = y + diry[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && grid[nx][ny] == '.' && !vis[nx][ny])
				vis[nx][ny] = 1, q.push({ nx, ny });
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> grid[i];

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (grid[i][j] == '.' && !vis[i][j])
				ans++, search(i, j);

	cout << ans << "\n";

	return 0;
}
