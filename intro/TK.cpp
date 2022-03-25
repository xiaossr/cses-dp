#include <iostream>
using namespace std;

long long N;

int main()
{
	cin >> N;

	for (long long i = 1; i <= N; i++)
		cout << (i * i) * (i * i - 1) / 2 - 4 * (i - 2) * (i - 1) << "\n";

	return 0;
}
