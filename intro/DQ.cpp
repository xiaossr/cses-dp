#include <iostream>
#include <string>
#include <map>
using namespace std;

int Q;
long long K;
map< pair<long long, int>, long long > m;

long long qpow(long long x, int p)
{
	if (p == 0) return 1;
	else if (m[{x, p}]) return m[{x, p}];
	else if (p % 2) return m[{x, p}] = qpow(x, p / 2)* qpow(x, p / 2)* x;
	return m[{x, p}] = qpow(x, p / 2)* qpow(x, p / 2);
}

int main()
{
	cin >> Q;

	// long long EVERYTHING
	while (Q--)
	{
		cin >> K;

		int dig = 1;
		for (long long i = 9;; K -= i, dig++, i = 9LL * qpow(10, dig - 1) * dig)
			if (K - i <= 0) 
				break;
		// find # of digits 

		K--;
		long long num = K / dig, rem = K % dig; // calc final dig
		long long ans = qpow(10, dig - 1) + num;
		cout << to_string(ans)[rem] << "\n";
	}

	return 0;
}
