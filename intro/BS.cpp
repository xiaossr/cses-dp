#include <iostream>
using namespace std;

int N;
const int MOD = 1e9 + 7;

long long qpow(int a)
{
	if (a == 0) return 1;
	if (a == 1) return 2;

	if (a % 2) return qpow(a / 2) * qpow(a / 2) % MOD * qpow(1) % MOD;
	return qpow(a / 2) * qpow(a / 2) % MOD;
}

int main()
{
	cin >> N;
	cout << qpow(N) << "\n";

	return 0;
}
