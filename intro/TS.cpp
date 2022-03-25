#include <iostream>
#include <set>
using namespace std;

long long N;
set<int> a, b;

int main()
{
	cin >> N;

	long long s = N * (N + 1) / 2;
	if (s % 2 != 0)
	{
		cout << "NO\n";
		return 0;
	}

	s /= 2;
	for (int i = 1; i <= N; i++)
		b.insert(i);

	long long cs = 0;
	for (int i = N; i >= 1 && cs != s; i--)
		if (cs + i <= s)
			cs += i, a.insert(i), b.erase(i);

	cout << "YES\n";
	cout << a.size() << "\n";
	for (const auto& k : a)
		cout << k << " ";
	cout << "\n";

	cout << b.size() << "\n";
	for (const auto& k : b)
		cout << k << " ";
	cout << "\n";

	return 0;
}
