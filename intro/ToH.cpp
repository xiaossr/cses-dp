#include <iostream>
#include <cmath>
using namespace std;

int N;

void hanoi(int d, int at, int want, int btwn)
{
	if (d == 1) cout << at << " " << want << "\n";
	else
	{
		hanoi(d - 1, at, btwn, want);
		cout << at << " " << want << "\n";
		hanoi(d - 1, btwn, want, at);
	}

	return;
}

int main()
{
	cin >> N;

	cout << pow(2, N) - 1 << "\n";

	hanoi(N, 1, 3, 2);

	return 0;
}
