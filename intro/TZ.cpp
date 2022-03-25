#include <iostream>
using namespace std;

int N;

int main()
{
	cin >> N;

	int ans = 0;
	while (N)
		ans += N / 5, N /= 5;
	cout << ans << "\n";

	return 0;
}
