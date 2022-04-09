#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int N, a, b;
vector<int> x;
vector<ll> psum;
multiset<ll> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> a >> b;

	ll ans = -LLONG_MAX;
	x.resize(N + 3), psum.resize(N + 3, 0); 
	for (int i = 1; i <= N; i++)
		cin >> x[i], psum[i] = psum[i - 1] + x[i];

	s.insert(0);
	for (int i = a; i <= N; i++)
	{
		ans = max(ans, psum[i] - *s.begin());

		if (i - b >= 0)
		{
			ll del = psum[i - b];
			auto it = s.find(del);
			if (it != s.end()) s.erase(s.find(del));
		}
		if(i - a + 1 <= N)
			s.insert(psum[i - a + 1]);
	}

	cout << ans << "\n";

	return 0;
}
