#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int N, c = 0;
int a[200005], b[200005];
ll p[200005], dp[200005];
map<int, int> coor;
vector< vector< pair<int, ll> > > pro;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i] >> b[i] >> p[i];
		b[i]++; // inc by 1 to prevent overlapping projects (e.g. 1-6, 6-7)
		coor[a[i]], coor[b[i]];
	}

	for (auto& k : coor)
		k.second = c++; // assign each start/end point a compressed value

	pro.resize(c + 1);
	for (int i = 0; i < N; i++)
		pro[coor[b[i]]].push_back(make_pair(coor[a[i]], p[i]));
	// for each endpoint, mark starting point and payment 

	for (int i = 0; i < c; i++)
	{
		if (i) dp[i] = dp[i - 1]; // don't do anything
		for(const auto &pr : pro[i])
			dp[i] = max(dp[i], dp[pr.first] + pr.second); // if we attend this project
	}

	cout << dp[c - 1] << "\n";

	return 0;
}