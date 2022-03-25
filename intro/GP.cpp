#include <iostream>
using namespace std;

string s;
int p[48];

int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, 1, 0, -1 };
bool onpath[9][9] = { 0 };

int search(int ind, int r, int c) // too slow can't brute force :( 4^48...
{
	// if "dead end" ( aka two sections blocked off by current path - bc can't cross over self impossible to go to both)
	if (onpath[r][c - 1] && onpath[r][c + 1] && !onpath[r - 1][c] && !onpath[r + 1][c]) return 0;
	if (!onpath[r][c - 1] && !onpath[r][c + 1] && onpath[r - 1][c] && onpath[r + 1][c]) return 0;

	if (r == 7 && c == 1)
		return ind == 48;

	if (ind == 48) return 0;

	int ret = 0;
	onpath[r][c] = 1;

	if (p[ind] < 4)
	{
		int nr = r + dirx[p[ind]],
			nc = c + diry[p[ind]];
		if (!onpath[nr][nc])
			ret += search(ind + 1, nr, nc);
	}
	else for (int i = 0; i < 4; i++)
	{
		int nr = r + dirx[i],
			nc = c + diry[i];
		if (onpath[nr][nc]) continue;
		ret += search(ind + 1, nr, nc);
	}

	onpath[r][c] = 0;
	return ret;
}

// need R == L, D = U + 7

int main()
{
	cin >> s;
	for (int i = 0; i < 48; i++)
	{
		if (s[i] == 'U') p[i] = 0;
		else if (s[i] == 'R') p[i] = 1;
		else if (s[i] == 'D') p[i] = 2;
		else if (s[i] == 'L') p[i] = 3;
		else p[i] = 4;
	}

	for (int i = 0; i < 9; i++)
		onpath[0][i] = onpath[8][i] = onpath[i][0] = onpath[i][8] = 1;

	cout << search(0, 1, 1) << "\n";

	return 0;
}
