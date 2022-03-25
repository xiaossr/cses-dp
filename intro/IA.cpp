#include <iostream>
using namespace std;

int N, pr, a; long long ans = 0;

int main()
{
	cin >> N >> a;
	
	pr = a;
	for (int i = 1; i < N; i++)
	{
		cin >> a;
		ans += max(pr - a, 0);
		pr = max(pr, a);
	}

	cout << ans << "\n";

	return 0;
}
