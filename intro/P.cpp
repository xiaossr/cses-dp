#include <iostream>
using namespace std;

int N;

int main()
{
	cin >> N;

	if (N == 1) cout << "1\n";
	else if (N < 4) cout << "NO SOLUTION\n";
	else
	{
		for (int i = 2; i <= N; i += 2)
			cout << i << " ";
		for (int i = 1; i <= N; i += 2)
			cout << i << " ";
		cout << "\n";
	}

	return 0;
}
