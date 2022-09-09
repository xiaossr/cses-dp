#include <iostream>
using namespace std;

int T, a, b;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> a >> b;
		int x3 = 2 * a - b, y3 = 2 * b - a;
		cout << (x3 < 0 || y3 < 0 || x3 % 3 || y3 % 3 ? "NO\n" : "YES\n");
	}
	
	return 0;
}
