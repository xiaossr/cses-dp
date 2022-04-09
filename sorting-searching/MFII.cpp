#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int K, N;
vector< pair<int, int> > m;
multiset< pair<int, int> > s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	m.resize(N);
	for (int i = 0; i < N; i++)
		cin >> m[i].second >> m[i].first;
	sort(m.begin(), m.end());

	int ans = 0;
	s.insert(m[0]), ans++;
	for (int i = 1; i < N; i++)
	{
		auto it = s.upper_bound({ m[i].second + 1, -1 });
		if (it == s.begin() && s.size() == K) continue; // set to keep track of movies being watched
		else if (it == s.begin() && s.size() < K)
		{
			s.insert(m[i]), ans++;
			continue;
		}
		else --it;

		s.insert(m[i]), ans++;
		s.erase(it);
	}

	cout << ans << "\n";

	return 0;
}
