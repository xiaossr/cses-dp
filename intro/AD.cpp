#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long N;
long long tsum = 0, ans;
vector<long long> p;

void search()
{
	for (long long mask = 0; mask < (1 << N); mask++)
	{
		long long tmp = 0;
		for (long long i = 0; i < N; i++)
			if (mask & (1 << i))
				tmp += p[i];
		ans = min(ans, abs(tmp * 2 - tsum));
	}
}

int main()
{
	cin >> N;

	p.resize(N);
	for (int i = 0; i < N; i++)
		cin >> p[i], tsum += p[i];
	ans = tsum;

	search();
	cout << ans << "\n";

	return 0;
}
