#include <iostream>
using namespace std;

char grid[8][8];
bool used[20][3]; // col, right diag, left diag

long long search(int row)
{
	if (row == 8) return 1;

	long long ret = 0;
	for (int col = 0; col < 8; col++)
	{
		if (grid[row][col] == '*' || used[col][0] 
			|| used[row - col + 8][1] || used[row + col][2]) continue;

		used[col][0] = used[row - col + 8][1] = used[row + col][2] = 1;
		ret += search(row + 1);
		used[col][0] = used[row - col + 8][1] = used[row + col][2] = 0;
	}

	return ret;
}

int main()
{
	// brute force it YASSS

	for (int i = 0; i < 8; i++)
		cin >> grid[i];

	cout << search(0) << "\n";

	return 0;
}
